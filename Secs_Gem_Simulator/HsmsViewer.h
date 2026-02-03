#pragma once

#include <QThread>
#include <QTcpSocket>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>

#include "ISocket.h"

class HsmsViewer : public QThread {
    Q_OBJECT

public:
    explicit HsmsViewer(QObject* parent = nullptr);
    ~HsmsViewer();

private:


signals:
    void setMsg(QString Msg);
};
