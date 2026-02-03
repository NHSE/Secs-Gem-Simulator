#pragma once

#include <QThread>

#include "ISocket.h"

#include "Logger.h"
#include "SecsType.h"
#include "HsmsEnums.h"
#include "MsgToSecsMsg.h"

class HsmsReceiver : public QObject {
    Q_OBJECT

public:
    explicit HsmsReceiver(ISocket* socket, QObject* parent = nullptr);
    ~HsmsReceiver();

private:
    ISocket* socket;
    MsgToSecsMsg* msgToSecsMsg;

signals:
    void setValue(QString State);

private slots:
    void onReadyRead();
};
