#include "MsgToSecsMsg.h"

MsgToSecsMsg::MsgToSecsMsg(QObject* parent)
    : QObject(parent)
{ }

MsgToSecsMsg::~MsgToSecsMsg()
{ }

QString MsgToSecsMsg::onMessage(const QByteArray& msg)
{
    HsmsHeader h = parseHeader(msg);

    if (h.sType != 0x00)
        return handleControlMessage(h);
    

    return handleDataMessage(h, msg.mid(10));
}

HsmsHeader MsgToSecsMsg::parseHeader(const QByteArray& data)
{
    HsmsHeader h;
    h.sessionId = (quint8(data[4]) << 8) | quint8(data[5]);
    h.stream = quint8(data[6] & 0x7F);
    h.wBit = quint8(data[6] & 0x80);
    h.function = quint8(data[7]);
    h.pType = quint8(data[8]);
    h.sType = quint8(data[9]);
    return h;
}

QString MsgToSecsMsg::handleDataMessage(const HsmsHeader& h, const QByteArray& body)
{
    QString header =
        QString("S%1F%2 %3")
        .arg(h.stream)
        .arg(h.function)
        .arg(h.wBit ? "W" : "");

    QString secsTree = QString();

    if (body.size() >= 5)
        secsTree = dumpSecs(body);

    
    QString ret = "[HSMS][DATA]\n" + header + "\n" + secsTree;
    return ret;
}

QString MsgToSecsMsg::handleControlMessage(const HsmsHeader& h)
{
    QString ret = "";

    switch (h.sType) {
    case 0x02:
        ret = "Select.rep";
        break;

    case 0x04:
        ret = "Deselect.res";
        break;

    case 0x06:
        ret = "Linktest.res";
        break;

    default:
        ret = "Unknown Control Msg";
        break;
    }

    return ret;
}

SecsType MsgToSecsMsg::parseType(quint8 b)
{
    switch (b & 0xFC) {
    case 0x00: return SecsType::L;
    case 0x20: return SecsType::B;
    case 0x24: return SecsType::BOOLEAN;
    case 0x40: return SecsType::A;
    case 0xA4: return SecsType::U1;
    case 0xA8: return SecsType::U2;
    case 0xB0: return SecsType::U4;
    case 0xA0: return SecsType::U8;
    case 0x64: return SecsType::I1;
    case 0x68: return SecsType::I2;
    case 0x70: return SecsType::I4;
    case 0x60: return SecsType::I8;
    case 0x90: return SecsType::F4;
    case 0x80: return SecsType::F8;
    default:   return SecsType::UNKNOWN;
    }
}

int MsgToSecsMsg::parseLength(const QByteArray& data, int& offset, int lenBytes)
{
    int len = 0;
    for (int i = 0; i < lenBytes; ++i) {
        len = (len << 8) | quint8(data[offset++]);
    }
    return len;
}

QString MsgToSecsMsg::parseItem(const QByteArray& data, int& offset, int depth)
{
    QString indent(depth * 2, ' ');
    quint8 first = quint8(data[offset++]);

    SecsType type = parseType(first);
    int lenBytes = first & 0x03;
    int length = parseLength(data, offset, lenBytes);

    QString out;

    if (type == SecsType::L) {
        out += QString("%1<L[%2]\n").arg(indent).arg(length);
        for (int i = 0; i < length; ++i) {
            out += parseItem(data, offset, depth + 1);
        }
        out += QString("%1>\n").arg(indent);
        return out;
    }

    // ---- B ----
    if (type == SecsType::B) {
        out += QString("%1<B[%2] 0x%3").arg(indent).arg(length).arg(static_cast<quint8>(data[offset++]), 2, 16, QChar('0'));
        out += ">\n";
        return out;
    }

    // ---- BOOLEAN ----
    if (type == SecsType::B) {
        out += QString("%1<BOOLEAN[%2] 0x%3\n").arg(indent).arg(length).arg(static_cast<bool>(data[offset++]));
        out += ">\n";
        return out;
    }

    // ---- ASCII ----
    if (type == SecsType::A) {
        QByteArray str = data.mid(offset, length);
        offset += length;
        out += QString("%1<A[%2] \"%3\">\n")
            .arg(indent)
            .arg(length)
            .arg(QString::fromLatin1(str));
        return out;
    }

    // ---- I1 ----
    if (type == SecsType::I1) {
        out += QString("%1<I1 ").arg(indent);

        for (int i = 0; i < length; ++i) {
            qint8 v = (qint8)data[offset++];
            out += QString::number(v);
            if (i != length - 1) out += " ";
        }

        out += ">\n";
        return out;
    }


    // ---- I2 ----
    if (type == SecsType::I2) {
        out += QString("%1<I2 ").arg(indent);

        int count = length / 2;
        for (int i = 0; i < count; ++i) {
            qint16 v =
                (qint8)data[offset++] << 8 |
                (quint8)data[offset++];

            out += QString::number(v);
            if (i != count - 1) out += " ";
        }

        out += ">\n";
        return out;
    }

    // ---- I4 ----
    if (type == SecsType::I4) {
        out += QString("%1<I4 ").arg(indent);

        int count = length / 4;
        for (int i = 0; i < count; ++i) {
            qint32 v =
                (qint8)data[offset++] << 24 |
                (quint8)data[offset++] << 16 |
                (quint8)data[offset++] << 8 |
                (quint8)data[offset++];

            out += QString::number(v);
            if (i != count - 1) out += " ";
        }

        out += ">\n";
        return out;
    }

    // ---- I8 ----
    if (type == SecsType::I8) {
        out += QString("%1<I8 ").arg(indent);

        int count = length / 8;
        for (int i = 0; i < count; ++i) {
            qint64 v =
                (qint64)(qint8)data[offset++] << 56 |
                (qint64)(quint8)data[offset++] << 48 |
                (qint64)(quint8)data[offset++] << 40 |
                (qint64)(quint8)data[offset++] << 32 |
                (qint64)(quint8)data[offset++] << 24 |
                (qint64)(quint8)data[offset++] << 16 |
                (qint64)(quint8)data[offset++] << 8 |
                (qint64)(quint8)data[offset++];

            out += QString::number(v);
            if (i != count - 1) out += " ";
        }

        out += ">\n";
        return out;
    }

    // ---- F4 ----
    if (type == SecsType::F4) {
        out += QString("%1<F4 ").arg(indent);

        int count = length / 4;
        for (int i = 0; i < count; ++i) {
            quint32 raw =
                (quint8)data[offset++] << 24 |
                (quint8)data[offset++] << 16 |
                (quint8)data[offset++] << 8 |
                (quint8)data[offset++];

            float v;
            memcpy(&v, &raw, sizeof(float));

            out += QString::number(v);
            if (i != count - 1) out += " ";
        }

        out += ">\n";
        return out;
    }

    // ---- F8 ----
    if (type == SecsType::F8) {
        out += QString("%1<F8 ").arg(indent);

        int count = length / 8;
        for (int i = 0; i < count; ++i) {
            quint64 raw =
                (quint64)(quint8)data[offset++] << 56 |
                (quint64)(quint8)data[offset++] << 48 |
                (quint64)(quint8)data[offset++] << 40 |
                (quint64)(quint8)data[offset++] << 32 |
                (quint64)(quint8)data[offset++] << 24 |
                (quint64)(quint8)data[offset++] << 16 |
                (quint64)(quint8)data[offset++] << 8 |
                (quint64)(quint8)data[offset++];

            double v;
            memcpy(&v, &raw, sizeof(double));

            out += QString::number(v);
            if (i != count - 1) out += " ";
        }

        out += ">\n";
        return out;
    }

    // ---- U1 ----
    if (type == SecsType::U1) {
        out += QString("%1<U1 ").arg(indent);
        for (int i = 0; i < length; ++i) {
            out += QString::number(quint8(data[offset++])) + " ";
        }
        out += ">\n";
        return out;
    }

    // ---- U2 ----
    if (type == SecsType::U2) {
        out += QString("%1<U2 ").arg(indent);

        int count = length / 2;
        for (int i = 0; i < count; ++i) {
            quint16 v =
                (quint8)data[offset++] << 8 |
                (quint8)data[offset++];

            out += QString::number(v);
            if (i != count - 1) out += " ";
        }

        out += ">\n";
        return out;
    }

    // ---- U4 ----
    if (type == SecsType::U4) {
        out += QString("%1<U4 ").arg(indent);

        int count = length / 4;   // U4 °³¼ö

        for (int i = 0; i < count; ++i) {
            quint32 u4 =
                (quint8)data[offset++] << 24 |
                (quint8)data[offset++] << 16 |
                (quint8)data[offset++] << 8 |
                (quint8)data[offset++];

            out += QString::number(u4);

            if (i != count - 1)
                out += " ";
        }

        out += ">\n";
        return out;
    }

    // ---- U8 ----
    if (type == SecsType::U8) {
        out += QString("%1<U8 ").arg(indent);

        int count = length / 8;
        for (int i = 0; i < count; ++i) {
            quint64 v =
                (quint64)(quint8)data[offset++] << 56 |
                (quint64)(quint8)data[offset++] << 48 |
                (quint64)(quint8)data[offset++] << 40 |
                (quint64)(quint8)data[offset++] << 32 |
                (quint64)(quint8)data[offset++] << 24 |
                (quint64)(quint8)data[offset++] << 16 |
                (quint64)(quint8)data[offset++] << 8 |
                (quint64)(quint8)data[offset++];

            out += QString::number(v);
            if (i != count - 1) out += " ";
        }

        out += ">\n";
        return out;
    }

    // fallback
    offset += length;
    out += QString("%1<UNKNOWN len=%2>\n").arg(indent).arg(length);
    return out;
}

QString MsgToSecsMsg::dumpSecs(const QByteArray& body)
{
    //0~3 system byte
    //4~ body
    int offset = 4;
    return parseItem(body, offset);
}