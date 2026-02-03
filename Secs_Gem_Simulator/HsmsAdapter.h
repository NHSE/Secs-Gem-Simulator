#pragma once
#include "ISocket.h"
#include <QTcpSocket>

class HsmsAdapter : public ISocket {
public:
    explicit HsmsAdapter(QTcpSocket* socket);

    qint64 write(const QByteArray& data) override;
    QByteArray readAll() override;
    bool isConnected() const override;

private:
    QTcpSocket* socket;
    QByteArray* recvBuffer;

signals:
    //void readData(QByteArray& msg);
};
