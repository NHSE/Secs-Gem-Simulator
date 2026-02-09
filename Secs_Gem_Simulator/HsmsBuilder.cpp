#include "HsmsBuilder.h"
#include "HsmsEnums.h"

#include <vector>

HsmsBuilder::HsmsBuilder()
{

}

HsmsBuilder::~HsmsBuilder()
{

}

QString HsmsBuilder::extractBody(const QString& fullText)
{
    int start = fullText.indexOf('<');
    int end = fullText.lastIndexOf('>');

    if (start < 0 || end < 0 || end <= start)
        return "";

    return fullText.mid(start, end - start + 1);
}

uint16_t HsmsBuilder::getDeviceID()
{
    int value = SettingManager::instance()->DeviceID;

    return static_cast<uint16_t>(value);
}

uint8_t HsmsBuilder::secsTypeToByte(const QString & type)
{
    if (type == "L")        return 0x01;

    if (type == "A")        return 0x41;

    if (type == "B")        return 0x21;

    if (type == "BOOLEAN")  return 0x25;

    if (type == "U1")       return 0xA5;
    if (type == "U2")       return 0xA9;
    if (type == "U4")       return 0xB1;
    if (type == "U8")       return 0xA1;

    if (type == "I1")       return 0x65;
    if (type == "I2")       return 0x69;
    if (type == "I4")       return 0x71;
    if (type == "I8")       return 0x61;

    if (type == "F4")       return 0x91;
    if (type == "F8")       return 0x81;

    return 0x00; // unknown
}

std::vector<QString> HsmsBuilder::ParserData(const QString& bodyText)
{
    std::vector<QString> data;
    QString dataText;
    bool bAscii = false;
    for (int i = 0; i < bodyText.length(); i++)
    {
        if (!bAscii)
        {
            if (bodyText[i] == '.')  break;

            if (bodyText[i] == '<' || bodyText[i] == '[' || bodyText[i] == ']'
                || bodyText[i] == '\\' || bodyText[i] == '\n')    continue;

            if (bodyText[i] == '"')
            {
                if (!dataText.isEmpty())
                {
                    data.push_back(dataText);
                    dataText.clear();
                }

                bAscii = true;

                continue;
            }

            if (bodyText[i] == ">" || bodyText[i] == " " || bodyText[i] == '\t')
            {
                if (!dataText.isEmpty())
                {
                    data.push_back(dataText);
                    dataText.clear();
                }
            }
            else
            {
                if (bodyText[i] != ">" && bodyText[i] != '\n')
                {
                    dataText.append(bodyText[i]);

                }
                else
                {
                    data.push_back(dataText);
                    dataText.clear();
                    bAscii = false;
                }
            }
        }
        else
        {
            if (bodyText[i] == '"')
            {
                data.push_back(dataText);
                dataText.clear();
                bAscii = false;

                continue;
            }

            dataText.append(bodyText[i]);
        }
    }

    return data;
}

int HsmsBuilder::getLength(const QString& type)
{
    if (type == "U1" || type == "I1" || type == "B") return 1;
    if (type == "U2" || type == "I2") return 2;
    if (type == "U4" || type == "I4" || type == "F4") return 4;
    if (type == "U8" || type == "I8" || type == "F8") return 8;
    return 0;
}

QByteArray HsmsBuilder::buildBodyFromSml(const QString& fullText)
{
    QByteArray body;

    QString bodyText = extractBody(fullText);
    if (bodyText.isEmpty())
        return body;

    // 데이터 파싱 (포맷, 크기, 데이터)
    std::vector<QString> data = ParserData(bodyText);

    // 끝일 때 . 나오면 종료
    int index = 0;
    while (index < data.size())
    {
        if (data[index] == "L")
        {
            uint8_t type = secsTypeToByte(QString(data[index]));

            body.append(char(type));
            body.append(char(data[++index].toInt()));
        }
        else if (data[index] == "B")
        {
            uint8_t type = secsTypeToByte(data[index]);

            body.append(char(type));

            int length = data[++index].toInt();
            body.append(char(length));

            int v = data[++index].toInt(nullptr, 16);
            body.append(char(v));

        }
        else if (data[index] == "BOOLEAN")
        {
            uint8_t type = secsTypeToByte(data[index]);

            body.append(char(type));
            body.append(char(data[++index].toInt()));
            
            QString result = data[++index];
            if (result == "TRUE")
            {
                body.append(char(0xFF));
            }
            else
            {
                body.append(char(0x00));
            }

        }
        else
        {
            uint8_t type = secsTypeToByte(data[index]);

            if (type == 0x00)
            {
                return "";
            }

            body.append(char(type));
            
            if (data[index] == "A")
            {
                QString ascii = data[++index];
                QByteArray asciiBytes = ascii.toLatin1();

                if (asciiBytes.size() > 0)
                {
                    body.append(char(asciiBytes.size()));   // length
                    body.append(asciiBytes);                // data
                }
                else body.append(char(0x00));
            }
            else
            {

                // U4 2 의 경우 4 x 2 = 8 byte
                int typeLength = getLength(data[index]);
                int elementCount = data[++index].toInt();
                int totalLength = typeLength * elementCount;

                body.append(static_cast<char>(totalLength));

                quint64 value = data[++index].toULongLong();
                for (int i = typeLength - 1; i >= 0; --i)
                {
                    body.append(static_cast<char>((value >> (i * 8)) & 0xFF));
                }
            }
        }

        index++;
    }

    return body;
}

QByteArray HsmsBuilder::MakeControlMsg(const HsmsSType& type)
{
    QByteArray packet;

    // Length (+ 10 bytes)
    packet.append(char(0x00));
    packet.append(char(0x00));
    packet.append(char(0x00));
    packet.append(char(0x0A));

    // HSMS Header
    uint16_t DeviceID = getDeviceID();
    packet.append(static_cast<char>((DeviceID >> 8) & 0xFF));            // Device ID
    packet.append(static_cast<char>(DeviceID & 0xFF));

    packet.append(char(0x00));                                          // Stream + W

    packet.append(char(0x00));                                          // Function

    packet.append(char(0x00));                                          // PType

    packet.append(char(static_cast<uint8_t>(type)));                    // SType

    packet.append(char((systemByte >> 24) & 0xFF));                     // System Bytes
    packet.append(char((systemByte >> 16) & 0xFF));
    packet.append(char((systemByte >> 8) & 0xFF));
    packet.append(char(systemByte & 0xFF));

    systemByte++;

    return packet;
}

QByteArray HsmsBuilder::MakeDataHeader(const SmlMessage& Msg, const int &length)
{
    QByteArray packet;

    // ---------------------------------
    // Length (4 bytes, Big Endian)
    // HSMS Header = 10 bytes
    // Body 없음
    // ---------------------------------
    quint32 data_length = static_cast<quint32>(length) + 10;

    packet.append(char((data_length >> 24) & 0xFF));
    packet.append(char((data_length >> 16) & 0xFF));
    packet.append(char((data_length >> 8) & 0xFF));
    packet.append(char(data_length & 0xFF));

    // ---------------------------------
    // HSMS Header (10 bytes)
    // ---------------------------------

    // Device ID
    uint16_t DeviceID = getDeviceID();
    packet.append(static_cast<char>((DeviceID >> 8) & 0xFF));
    packet.append(static_cast<char>(DeviceID & 0xFF));

    // Stream + W-bit
    quint8 streamByte = Msg.stream & 0x7F;
    if (Msg.wbit)
        streamByte |= 0x80;

    packet.append(char(streamByte));

    // Function
    packet.append(char(Msg.function & 0xFF));

    // PType (항상 0x00)
    packet.append(char(0x00));

    // SType (Data Message = 0x00)
    packet.append(char(0x00));

    // System Bytes
    packet.append(char((systemByte >> 24) & 0xFF));
    packet.append(char((systemByte >> 16) & 0xFF));
    packet.append(char((systemByte >> 8) & 0xFF));
    packet.append(char(systemByte & 0xFF));

    systemByte++;

    return packet;
}