#include "SettingManager.h"
#include "Logger.h"

SettingManager* SettingManager::instance()
{
	static SettingManager instance;
	return &instance;
}


SettingManager::SettingManager(QObject* parent)
	: QObject(parent)
{
    connect(this, SIGNAL(t3TimeoutError(quint32, QByteArray)), this, SLOT(onT3Timeout(quint32, QByteArray)));
    connect(this, SIGNAL(t6TimeoutError(quint32, QByteArray)), this, SLOT(onT6Timeout(quint32, QByteArray)));
}

SettingManager::~SettingManager()
{

}

void SettingManager::setAllTimeOut(int T3, int T5, int T6, int T7, int T8)
{
	this->T3 = T3;
	this->T5 = T5;
	this->T6 = T6;
	this->T7 = T7;
	this->T8 = T8;
}

void SettingManager::setTimeOut(QString name, int T)
{
	if (name == "T3")		this->T3 = T;
	else if (name == "T5")	this->T5 = T;
	else if (name == "T6")	this->T6 = T;
	else if (name == "T7")	this->T7 = T;
	else if (name == "T8")	this->T8 = T;
}

QString SettingManager::getCtrlType(const quint32& Stype)
{
    QString ret = "";

    switch (Stype) {
    case 0x01:
        ret = "Select.res";
        break;

    case 0x03:
        ret = "Deselect.res";
        break;

    case 0x05:
        ret = "Linktest.res";
        break;

    default:
        ret = "Unknown Control Msg";
        break;
    }

    return ret;
}

void SettingManager::startT3(quint32 systemByte, const QByteArray& sentMsg)
{
    if (t3Map.contains(systemByte))
        return;

    QTimer* timer = new QTimer(this);
    timer->setSingleShot(true);

    connect(timer, &QTimer::timeout, this, [this, systemByte]() {
        handleT3Timeout(systemByte);
        });

    Context ctx;
    ctx.systemByte = systemByte;
    ctx.sentMsg = sentMsg;
    ctx.timer = timer;

    t3Map.insert(systemByte, ctx);
    timer->start(this->T3 * 1000);
}

void SettingManager::stopT3(quint32 systemByte)
{
    t3Map.remove(systemByte);
}

void SettingManager::handleT3Timeout(quint32 systemByte)
{
    if (!t3Map.contains(systemByte))
        return;

    Context ctx = t3Map.take(systemByte);

    // 1. 타이머 정리
    ctx.timer->stop();
    ctx.timer->deleteLater();

    // 2. 에러 통지
    emit t3TimeoutError(systemByte, ctx.sentMsg);
}

void SettingManager::onT3Timeout(quint32 systemByte, const QByteArray& sentMsg)
{
    quint8 sType = quint8(sentMsg[9]);

    quint8 stream = static_cast<quint8>(sentMsg[6] & 0x7F);
    quint8 function = static_cast<quint8>(sentMsg[7]);

    QString log = QString("[ERROR][S%1F%2] T3 Time Out")
            .arg(stream)
            .arg(function);

    Logger::instance()->sendLog(log);
}

void SettingManager::startT6(quint32 systemByte, const QByteArray& sentMsg)
{
    if (t6Map.contains(systemByte))
        return;

    QTimer* timer = new QTimer(this);
    timer->setSingleShot(true);

    connect(timer, &QTimer::timeout, this, [this, systemByte]() {
        handleT6Timeout(systemByte);
        });

    Context ctx;
    ctx.systemByte = systemByte;
    ctx.sentMsg = sentMsg;
    ctx.timer = timer;

    t6Map.insert(systemByte, ctx);
    timer->start(this->T6 * 1000);
}

void SettingManager::stopT6(quint32 systemByte)
{
    t6Map.remove(systemByte);
}

void SettingManager::handleT6Timeout(quint32 systemByte)
{
    if (!t6Map.contains(systemByte))
        return;

    Context ctx = t6Map.take(systemByte);

    // 1. 타이머 정리
    ctx.timer->stop();
    ctx.timer->deleteLater();

    // 2. 에러 통지
    emit t6TimeoutError(systemByte, ctx.sentMsg);
}

void SettingManager::onT6Timeout(quint32 systemByte, const QByteArray& sentMsg)
{
    quint8 sType = static_cast<quint8>(sentMsg[9]);

    QString ctrl = getCtrlType(sType);
    QString log = QString("[ERROR][%1] T6 Time Out")
            .arg(ctrl);

    Logger::instance()->sendLog(log);
}