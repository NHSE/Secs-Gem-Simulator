#pragma once
#include "SecsType.h"

#include <QByteArray>

class ISocket {
public:
    virtual ~ISocket() = default;

    virtual qint64 write(const QueData& data) = 0;
    virtual QByteArray readAll() = 0;
    virtual bool isConnected() const = 0;
};