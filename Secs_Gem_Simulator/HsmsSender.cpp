#include "HsmsSender.h"

HsmsSender::HsmsSender(ISocket* socket, QObject* parent)
    : QThread(parent), socket(socket)
{

}

HsmsSender::~HsmsSender()
{

}

bool HsmsSender::InsertMsgQue(QByteArray &msg)
{
    bool ret = false;

    QMutexLocker locker(&mutex);
    MsgQue.enqueue(msg);
    cond.wakeOne();

    emit setValue("Connect");

    return true;
}

void HsmsSender::run()
{
    while (1)
    {
        mutex.lock();

        while (MsgQue.isEmpty())
        {
            cond.wait(&mutex);
        }

        QByteArray msg = MsgQue.dequeue();

        mutex.unlock();

        socket->write(msg);
    }
}

