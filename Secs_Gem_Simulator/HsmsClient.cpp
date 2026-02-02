#include "HsmsClient.h"
#include "HsmsEnums.h"

HsmsClient::HsmsClient(QObject* parent)
    : QObject(parent)
{
    TcpSocket = new QTcpSocket(this);
    hsmsAdapter = new HsmsAdapter(TcpSocket);
    hsmsBuilder = new HsmsBuilder();
    hsmsSender = new HsmsSender(hsmsAdapter);
    hsmsReceiver = new HsmsReceiver(hsmsAdapter);

    connect(hsmsSender, SIGNAL(setValue(QString)), this, SLOT(StateChange(QString)));
    hsmsSender->start();

    //connect(hsmsAdapter, SIGNAL(&hsmsAdapter::readData(QByteArray)), hsmsReceiver, SLOT(&hsmsReceiver::onReadyRead(QByteArray)));
    //hsmsReceiver->start();
}

HsmsClient::~HsmsClient()
{ }

void HsmsClient::connectToEquipment()
{
    TcpSocket->connectToHost(QHostAddress("127.0.0.1"), 5000);

    QByteArray msg = hsmsBuilder->MakeControlMsg(HsmsSType::SelectReq);

    hsmsSender->InsertMsgQue(msg);
}

void HsmsClient::DisconnectToEquipment()
{
    if (TcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        TcpSocket->close();
    }
}

void HsmsClient::StateChange(QString State)
{
    emit setValue(State);
}