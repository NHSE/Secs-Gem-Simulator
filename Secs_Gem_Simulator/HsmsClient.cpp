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

    connect(hsmsSender, &HsmsSender::sendNext, hsmsSender, &HsmsSender::process, Qt::QueuedConnection);
    connect(hsmsReceiver, SIGNAL(setValue(ConnectionState)), this, SLOT(StateChange(ConnectionState)));

    connect(TcpSocket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)), this, SLOT(onSocketError(QAbstractSocket::SocketError)));
    connect(TcpSocket, SIGNAL(readyRead()), hsmsReceiver, SLOT(onReadyRead()));
    connect(TcpSocket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(TcpSocket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));

}

HsmsClient::~HsmsClient()
{ }

void HsmsClient::connectToEquipment()
{
    if (TcpSocket->state() == QAbstractSocket::ConnectedState)   return;

    QString IP = SettingManager::instance()->IP;
    int Port = SettingManager::instance()->Port;
    TcpSocket->connectToHost(QHostAddress(IP), Port);
}


void HsmsClient::DisconnectToEquipment()
{
    if (TcpSocket->state() == QAbstractSocket::ConnectedState)
    {
        QByteArray msg = hsmsBuilder->MakeControlMsg(HsmsSType::DeselectReq);
        hsmsSender->InsertMsgQue(msg, true);
        TcpSocket->close();

        // T5 동안 Connect 불가
    }
}

void HsmsClient::LinkTestToEquipment()
{
    if (TcpSocket->state() != QAbstractSocket::ConnectedState)   return;

    QByteArray msg = hsmsBuilder->MakeControlMsg(HsmsSType::LinktestReq);

    hsmsSender->InsertMsgQue(msg, true);
}

void HsmsClient::StateChange(const ConnectionState State)
{
    emit setValue(State);
}

void HsmsClient::onConnected()
{
    QByteArray msg = hsmsBuilder->MakeControlMsg(HsmsSType::SelectReq);
    hsmsSender->InsertMsgQue(msg, true);
}

void HsmsClient::onDisconnected()
{
    Logger::instance()->getLog("TCP Disconnected");

    emit setValue(ConnectionState::Disconnected);
}

void HsmsClient::onSocketError(QAbstractSocket::SocketError error)
{
    QString error_log = QString("[TCP][ERROR] %1 %2").arg(error).arg(TcpSocket->errorString());
    Logger::instance()->getLog(error_log);

    emit setValue(ConnectionState::Disconnected);
}

SmlMessage HsmsClient::SendSecsMsg(SmlMessage Msg)
{
    //데이터 만들기
    QByteArray data_msg = hsmsBuilder->buildBodyFromSml(Msg.fullText);
    if (data_msg == "FORMAT ERROR")
    {
        Logger::instance()->getLog("[ERROR][SML PARSE] Invalid SML format - data format mismatch(offset overflow)");
        return SmlMessage();
    }

    int length = data_msg.length();

    //길이 + 헤더 만들기
    QByteArray packet = hsmsBuilder->MakeDataHeader(Msg, length);

    //A(길이) + B(헤더) + C(데이터) 영역 합치기
    packet.append(data_msg);

    hsmsSender->InsertMsgQue(packet, Msg.wbit);

    return Msg;
}