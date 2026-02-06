#pragma once

#include <QtCore/QObject>
#include "HsmsEnums.h"
#include "SecsType.h"

class HsmsBuilder {

public:
    explicit HsmsBuilder();
    ~HsmsBuilder();

    QByteArray MakeControlMsg(const HsmsSType& type);
    QByteArray MakeDataHeader(const SmlMessage& Msg, const int& length);
    QByteArray buildBodyFromSml(const QString& fullText);

private:
    std::vector<QString> ParserData(const QString& bodyText);
    int getLength(const QString& type);

private:
    quint32 systemByte = 0x00;
};