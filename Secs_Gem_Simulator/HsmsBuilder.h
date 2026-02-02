#pragma once

#include <QtCore/QObject>
#include "HsmsEnums.h"

class HsmsBuilder {

public:
    explicit HsmsBuilder();
    ~HsmsBuilder();

    QByteArray MakeControlMsg(HsmsSType type);

private:

};