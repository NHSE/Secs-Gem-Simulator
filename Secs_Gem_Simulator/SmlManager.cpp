#include "SmlManager.h"

#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QVector>
#include <QSet>

SmlManager::SmlManager(QObject* parent)
	: QObject(parent)
{ }

SmlManager::~SmlManager()
{ }

bool SmlManager::ParseFile(const QString& path, QVector<SmlMessage>& outMessages, QString& errorMsg)
{
    outMessages.clear();
    QSet<QString> sxfxSet;

    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        errorMsg = "File open failed";
        return false;
    }

    QTextStream in(&file);

    // S2F33, S2F33 W, S2F33W 모두 허용
    QRegularExpression re(R"(S(\d+)\s*F(\d+)\s*(W)?)");

    bool collecting = false;

    SmlMessage current;
    QString buffer;

    while (!in.atEnd()) {
        QString line = in.readLine();

        if (!collecting) {
            auto m = re.match(line);
            if (m.hasMatch()) {
                int s = m.captured(1).toInt();
                int f = m.captured(2).toInt();
                bool wbit = !m.captured(3).isEmpty();

                QString key = makeKey(s, f);
                if (sxfxSet.contains(key)) {
                    errorMsg = QString("Duplicate SxFx detected: %1").arg(key);
                    return false;
                }

                sxfxSet.insert(key);

                current = {};
                current.stream = s;
                current.function = f;
                current.wbit = wbit;

                buffer.clear();
                buffer += line + "\n";

                collecting = true;
            }
        }
        else {
            buffer += line + "\n";

            // 메시지 블록 종료
            if (line.contains(".")) {
                current.fullText = buffer;
                outMessages.push_back(current);

                collecting = false;
            }
        }
    }

    if (collecting)
    {
        current.fullText = buffer;
        outMessages.push_back(current);
    }

    return true;
}

QString SmlManager::makeKey(int s, int f) {
    return QString("S%1F%2").arg(s).arg(f);
}