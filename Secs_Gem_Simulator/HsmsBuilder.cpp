#include "HsmsBuilder.h"
#include "HsmsEnums.h"

HsmsBuilder::HsmsBuilder()
{

}

HsmsBuilder::~HsmsBuilder()
{

}

QByteArray HsmsBuilder::MakeControlMsg(HsmsSType type)
{
    QByteArray packet;

    // Length (10 bytes)
    packet.append(char(0x00));
    packet.append(char(0x00));
    packet.append(char(0x00));
    packet.append(char(0x0A));

    // HSMS Header
    packet.append(char(0x00)); packet.append(char(0x00));               // Device ID

    packet.append(char(0x00));                                          // Stream + W

    packet.append(char(0x00));                                          // Function

    packet.append(char(0x00));                                          // PType

    packet.append(char(static_cast<uint8_t>(type)));                    // SType

    packet.append(char(0x00)); packet.append(char(0x00));               // System Bytes
    packet.append(char(0x00)); packet.append(char(0x00));

    return packet;
}