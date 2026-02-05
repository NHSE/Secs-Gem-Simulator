#include "HsmsAdapter.h"

#include <QDataStream>

HsmsAdapter::HsmsAdapter(QTcpSocket* socket)
    : socket(socket) {
}


qint64 HsmsAdapter::write(const QByteArray& data) {
    return socket->write(data);;
}


QByteArray HsmsAdapter::readAll() {
    QByteArray msg = socket->readAll();

    if (!msg.isEmpty())
    {
        return msg;
    }

    return QByteArray();
}


bool HsmsAdapter::isConnected() const {
    return socket->state() == QAbstractSocket::ConnectedState;
}
