#pragma once

#include <QObject>
#include <QTimer>
#include <QMap>

struct Context 
{
    quint32 systemByte;
    QByteArray sentMsg;
    QTimer* timer;
};


class SettingManager : public QObject {
    Q_OBJECT

public:
    static SettingManager* instance();

    explicit SettingManager(QObject* parent = nullptr);
    ~SettingManager();

    SettingManager(const SettingManager&) = delete;
    SettingManager& operator=(const SettingManager&) = delete;

    void setAllTimeOut(int T3, int T5, int T6, int T7, int T8);
    void setTimeOut(QString name, int T);

    void startT3(quint32 systemByte, const QByteArray& sentMsg);
    void stopT3(quint32 systemByte);

    void startT6(quint32 systemByte, const QByteArray& sentMsg);
    void stopT6(quint32 systemByte);

public:
    int T3, T5, T6, T7, T8;

private:
    QMap<quint32, Context> t3Map;
    void handleT3Timeout(quint32 systemByte);

    QMap<quint32, Context> t6Map;
    void handleT6Timeout(quint32 systemByte);

    QString getCtrlType(const quint32& Stype);

signals:
    void t3TimeoutError(quint32 systemByte, const QByteArray& sentMsg);
    void t6TimeoutError(quint32 systemByte, const QByteArray& sentMsg);

private slots:
    void onT3Timeout(quint32 systemByte, const QByteArray& sentMsg);
    void onT6Timeout(quint32 systemByte, const QByteArray& sentMsg);
};
