#include "HsmsSender.h"

HsmsSender::HsmsSender(ISocket* socket, QObject* parent)
    : QObject(parent), socket(socket)
{
}

HsmsSender::~HsmsSender()
{

}

bool HsmsSender::InsertMsgQue(QByteArray& msg, bool wbit)
{
    {
        QMutexLocker locker(&mutex);

        QueData data;
        data.msg = msg, data.wbit = wbit;
        MsgQue.enqueue(data);
    }

    emit sendNext();   // ⭐ 이벤트 기반
    return true;
}

void HsmsSender::process()
{
    QueData data;

    {
        QMutexLocker locker(&mutex);
        if (MsgQue.isEmpty())
            return;

        data = MsgQue.dequeue();
    }

    socket->write(data);

    Logger::instance()->getLog(MsgToSecsMsg::instance()->onMessage(data.msg));
}

