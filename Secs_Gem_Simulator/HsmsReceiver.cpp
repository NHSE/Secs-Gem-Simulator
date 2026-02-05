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
}