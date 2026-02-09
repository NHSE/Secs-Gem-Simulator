#pragma once

#include <QByteArray>
#include <QString>

enum class SecsType 
{
    L, B, BOOLEAN, A, U1, U2, U4, U8, I1, I2, I4, I8, F4, F8, UNKNOWN
};

enum class ConnectionState
{
    Connected, Disconnected
};

struct SmlMessage 
{
    int stream;
    int function;
    bool wbit;
    QString fullText;
};

struct SxFx 
{
    int stream;
    int function;

    bool operator<(const SxFx& other) const {
        if (stream != other.stream)
            return stream < other.stream;
        return function < other.function;
    }
};

struct QueData
{
    QByteArray msg;
    bool wbit = false;
};