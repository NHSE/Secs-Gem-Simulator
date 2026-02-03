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
    connect(TcpSocket, SIGNAL(&QTcpSocket::errorOccurred), this, SLOT(onSocketError));
    connect(TcpSocket, SIGNAL(readyRead()), hsmsReceiver, SLOT(onReadyRead()));

    hsmsSender->start();
}

HsmsClient::~HsmsClient()
{ }

void HsmsClient::connectToEquipment()
{
    if (TcpSocket->state() == QAbstractSocket::ConnectedState)   return;

    TcpSocket->connectToHost(QHostAddress("127.0.0.1"), 5000);

    QByteArray msg = hsmsBuilder->MakeControlMsg(HsmsSType::SelectReq);

    hsmsSender->InsertMsgQue(msg);
}


void HsmsClient::DisconnectToEquipment()
{
    if (TcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        QByteArray msg = hsmsBuilder->MakeControlMsg(HsmsSType::DeselectReq);
        hsmsSender->InsertMsgQue(msg);
        TcpSocket->close();
    }
}

void HsmsClient::StateChange(QString State)
{
    emit setValue(State);
}

void HsmsClient::onSocketError(QAbstractSocket::SocketError error)
{

}