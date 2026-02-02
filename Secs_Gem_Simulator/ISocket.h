#pragma once

#include <QByteArray>

class ISocket {
public:
    virtual ~ISocket() = default;

    virtual qint64 write(const QByteArray& data) = 0;
    //virtual void read();
    virtual bool isConnected() const = 0;
};