#pragma once

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>

#include "HsmsBuilder.h"
#include "HsmsSender.h"
#include "HsmsAdapter.h"
#include "HsmsReceiver.h"
#include "Logger.h"

class HsmsClient : public QObject {
    Q_OBJECT

public:
    explicit HsmsClient(QObject* parent = nullptr);
    ~HsmsClient();

    SmlMessage SendSecsMsg(SmlMessage Msg);

private:
    HsmsBuilder* hsmsBuilder;
    HsmsSender* hsmsSender;
    HsmsAdapter* hsmsAdapter;
    HsmsReceiver* hsmsReceiver;

    QTcpSocket* TcpSocket;

signals:
    void setValue(const ConnectionState State);

public slots:
    void connectToEquipment();
    void DisconnectToEquipment();
    void LinkTestToEquipment();

    void StateChange(const ConnectionState State);

    void onConnected();
    void onDisconnected();
    void onSocketError(QAbstractSocket::SocketError error);
};