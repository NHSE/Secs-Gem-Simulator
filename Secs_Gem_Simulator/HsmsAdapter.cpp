#include "HsmsAdapter.h"

#include <QDataStream>

HsmsAdapter::HsmsAdapter(QTcpSocket* socket)
    : socket(socket) {
}


qint64 HsmsAdapter::write(const QueData& data) {
    
    if (data.wbit)
    {
        quint32 systemByte = extractSystemByte(data.msg);

        quint8 sType = quint8(data.msg[9]);

        if (sType != 0x00) //컨트롤 메세지의 경우
        {
            SettingManager::instance()->startT6(systemByte, data.msg);
        }
        else //데이터 메세지의 경우
        {
            SettingManager::instance()->startT3(systemByte, data.msg);
        }
    }

    return socket->write(data.msg);;
}


QByteArray HsmsAdapter::readAll() {
    QByteArray msg = socket->readAll();

    quint32 systemByte = extractSystemByte(msg);
    SettingManager::instance()->stopT3(systemByte);
    SettingManager::instance()->stopT6(systemByte);

    if (!msg.isEmpty())
    {
        return msg;
    }

    return QByteArray();
}

quint32 HsmsAdapter::extractSystemByte(const QByteArray& data)
{
    // HSMS: system byte = bytes 10~13 (big endian)
    quint32 systemByte =
        (quint8(data[10]) << 24) |
        (quint8(data[11]) << 16) |
        (quint8(data[12]) << 8) |
        (quint8(data[13]));

    return systemByte;
}

bool HsmsAdapter::isConnected() const {
    return socket->state() == QAbstractSocket::ConnectedState;
}
