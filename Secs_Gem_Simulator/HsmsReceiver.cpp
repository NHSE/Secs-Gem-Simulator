#include "HsmsReceiver.h"

HsmsReceiver::HsmsReceiver(ISocket* socket, QObject* parent)
    : QObject(parent), socket(socket)
{

}

HsmsReceiver::~HsmsReceiver()
{

}

void HsmsReceiver::onReadyRead()
{
    QByteArray data = socket->readAll();

    if (data.isEmpty())
        return;

    Logger::instance()->getLog(MsgToSecsMsg::instance()->onMessage(data));

    quint8 sType = static_cast<quint8>(data[9]);

    if (quint8(data[7]) == 0x00) // Control Message
    {
        switch (sType)
        {
        case 0x02: // Select.rsp
            emit setValue(ConnectionState::Connected);
            break;

        case 0x04: // Deselect.rsp
            emit setValue(ConnectionState::Disconnected);
            break;

        case 0x09: // Separate.req
            emit setValue(ConnectionState::Disconnected);
            break;

        default:
            break;
        }
    }
}