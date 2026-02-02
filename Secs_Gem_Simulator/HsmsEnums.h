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
