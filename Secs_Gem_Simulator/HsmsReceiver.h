#pragma once

#include <QThread>

#include "ISocket.h"

class HsmsReceiver : public QThread {
    Q_OBJECT

public:
    explicit HsmsReceiver(ISocket* socket, QObject* parent = nullptr);
    ~HsmsReceiver();

private:
    ISocket* socket;

signals:
    void setValue(QString State);

private slots:
    void onReadyRead(QByteArray& msg);
};
