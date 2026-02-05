#include "HsmsSender.h"

HsmsSender::HsmsSender(ISocket* socket, QObject* parent)
    : QObject(parent), socket(socket)
{
}

HsmsSender::~HsmsSender()
{

}

bool HsmsSender::InsertMsgQue(QByteArray& msg)
{
    {
        QMutexLocker locker(&mutex);
        MsgQue.enqueue(msg);
    }

    emit sendNext();   // ⭐ 이벤트 기반
    return true;
}

void HsmsSender::process()
{
    QByteArray msg;

    {
        QMutexLocker locker(&mutex);
        if (MsgQue.isEmpty())
            return;

        msg = MsgQue.dequeue();
    }

    socket->write(msg);

    Logger::instance()->getLog(MsgToSecsMsg::instance()->onMessage(msg));
}

