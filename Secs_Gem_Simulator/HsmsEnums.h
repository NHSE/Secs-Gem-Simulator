#pragma once
#include <cstdint>

enum class HsmsControlType
{
    SelectReq,
    SelectRsp,
    DeselectReq,
    LinktestReq,
    LinktestRsp,
    SeparateReq
};

enum class HsmsSType : uint8_t
{
    Data = 0x00,
    SelectReq = 0x01,
    SelectRsp = 0x02,
    DeselectReq = 0x03,
    DeselectRsp = 0x04,
    LinktestReq = 0x05,
    LinktestRsp = 0x06,
    RejectReq = 0x07,
    SeparateReq = 0x09
};

struct HsmsHeader
{
    quint16 sessionId;    // Big Endian
    quint8  stream;       // Stream or 0
    quint8  function;     // Function or 0
    bool wBit;            // wait Bit
    quint8  pType;        // Always 0x00
    quint8  sType;        // 0 = Data, else Control
    quint32 systemBytes;  // Transaction ID
};
