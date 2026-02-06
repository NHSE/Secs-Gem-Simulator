#pragma once

#include <QThread>
#include <QTcpSocket>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>

#include "ISocket.h"
#include "MsgToSecsMsg.h"
#include "Logger.h"
#include "SecsType.h"

class HsmsSender : public QObject {
    Q_OBJECT

public:
    explicit HsmsSender(ISocket* socket, QObject* parent = nullptr);
    ~HsmsSender();

    bool InsertMsgQue(QByteArray &msg, bool wbit = false);

private:
    ISocket* socket;

private:
    QQueue<QueData> MsgQue;
    QMutex mutex;
    QWaitCondition cond;

signals:
    void setValue(QString State);
    void sendNext();

public slots:
    void process();
};