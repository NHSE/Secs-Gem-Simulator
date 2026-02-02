#include "HsmsReceiver.h"

HsmsReceiver::HsmsReceiver(ISocket* socket, QObject* parent)
    : QThread(parent), socket(socket)
{
}

HsmsReceiver::~HsmsReceiver()
{

}

void HsmsReceiver::onReadyRead(QByteArray& msg)
{
   
}