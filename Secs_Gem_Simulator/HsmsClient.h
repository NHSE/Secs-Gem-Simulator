#pragma once

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QHostAddress>

#include "HsmsBuilder.h"
#include "HsmsSender.h"
#include "HsmsAdapter.h"
#include "HsmsReceiver.h"

class HsmsClient : public QObject {
    Q_OBJECT

public:
    explicit HsmsClient(QObject* parent = nullptr);
    ~HsmsClient();

private:
    HsmsBuilder* hsmsBuilder;
    HsmsSender* hsmsSender;
    HsmsAdapter* hsmsAdapter;
    HsmsReceiver* hsmsReceiver;

    QTcpSocket* TcpSocket;

signals:
    void setValue(QString State);

public slots:
    void connectToEquipment();
    void DisconnectToEquipment();
    void StateChange(QString State);
};