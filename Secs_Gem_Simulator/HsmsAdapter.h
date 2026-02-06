#pragma once
#include "ISocket.h"
#include "SecsType.h"
#include "SettingManager.h"

#include <QTcpSocket>

class HsmsAdapter : public ISocket {
public:
    explicit HsmsAdapter(QTcpSocket* socket);

    qint64 write(const QueData& data) override;
    QByteArray readAll() override;
    bool isConnected() const override;
    
    quint32 extractSystemByte(const QByteArray& data);

private:
    QTcpSocket* socket;
    QByteArray* recvBuffer;

signals:
    //void readData(QByteArray& msg);
};
