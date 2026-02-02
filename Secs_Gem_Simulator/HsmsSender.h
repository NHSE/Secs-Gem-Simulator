#pragma once

#include <QThread>
#include <QTcpSocket>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>

#include "ISocket.h"

class HsmsSender : public QThread {
    Q_OBJECT

public:
    explicit HsmsSender(ISocket* socket, QObject* parent = nullptr);
    ~HsmsSender();

    bool InsertMsgQue(QByteArray &msg);

private:
    ISocket* socket;

    void run();

private:
    QQueue<QByteArray> MsgQue;
    QMutex mutex;
    QWaitCondition cond;

signals:
    void setValue(QString State);
};