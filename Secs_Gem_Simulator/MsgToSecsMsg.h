#pragma once

#include <QtCore/QObject>
#include "SecsType.h"
#include "HsmsEnums.h"

class MsgToSecsMsg : public QObject {
    Q_OBJECT
public:
    explicit MsgToSecsMsg(QObject* parent = nullptr);
    ~MsgToSecsMsg();

    QString onMessage(const QByteArray& msg);

private:
    SecsType parseType(quint8 b);
    int parseLength(const QByteArray& data, int& offset, int lenBytes);
    QString parseItem(const QByteArray& data, int& offset, int depth = 0);
    QString dumpSecs(const QByteArray& body);
    QString handleControlMessage(const HsmsHeader& h);
    QString handleDataMessage(const HsmsHeader& h, const QByteArray& body);
    HsmsHeader parseHeader(const QByteArray& data);

};