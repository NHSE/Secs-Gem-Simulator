#include "HsmsAdapter.h"

HsmsAdapter::HsmsAdapter(QTcpSocket* socket)
    : socket(socket) {
}

qint64 HsmsAdapter::write(const QByteArray& data) {
    return socket->write(data);
}

/*
void HsmsAdapter::read() {
    QByteArray msg = socket->readAll();

    if (!msg.isEmpty())
    {
        //emit readData(msg);
    }
}
*/

bool HsmsAdapter::isConnected() const {
    return socket->state() == QAbstractSocket::ConnectedState;
}
