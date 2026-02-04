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

SmlMessage HsmsClient::SendSecsMsg(SmlMessage Msg)
{
    //데이터 만들기
    QByteArray data_msg = hsmsBuilder->buildBodyFromSml(Msg.fullText);
    int length = data_msg.length();

    //길이 + 헤더 만들기
    QByteArray packet = hsmsBuilder->MakeDataHeader(Msg, length);

    //A(길이) + B(헤더) + C(데이터) 영역 합치기
    packet.append(data_msg);

    hsmsSender->InsertMsgQue(packet);

    return Msg;
}