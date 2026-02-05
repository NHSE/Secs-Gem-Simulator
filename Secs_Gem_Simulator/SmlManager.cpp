#include "SmlManager.h"

#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QVector>
#include <QSet>
#include <QMessageBox>

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

    // SxFx, SxFx W 허용
    QRegularExpression sxfxRe(R"(S(\d+)\s*F(\d+)\s*(W)?)");

    bool collecting = false;
    bool hasBody = false;

    SmlMessage current;
    QString buffer;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QString trimmed = line.trimmed();

        // 메시지 시작
        if (!collecting) {
            auto m = sxfxRe.match(trimmed);
            if (m.hasMatch()) {
                int s = m.captured(1).toInt();
                int f = m.captured(2).toInt();
                bool wbit = !m.captured(3).isEmpty();

                QString key = QString("S%1F%2").arg(s).arg(f);
                if (sxfxSet.contains(key)) {
                    errorMsg = "Duplicate SxFx detected: " + key;

                    QMessageBox::critical(nullptr, "Error !", errorMsg);
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
                hasBody = false;

                // ⭐ 헤더만 있고 바로 끝나는 메시지
                if (trimmed.endsWith(".")) {
                    current.fullText = buffer;

                    if (!validateSmlFormat(current.fullText, errorMsg)) {
                        QMessageBox::critical(nullptr, "Error !", errorMsg);
                        return false;
                    }

                    outMessages.push_back(current);
                    collecting = false;
                }
            }
            continue;
        }

        // 메시지 수집 중
        // 닫히지 않았는데 또 SxFx 등장
        if (sxfxRe.match(trimmed).hasMatch()) {
            errorMsg =
                "Previous SML message not closed with '>.' before new SxFx:\n"
                + buffer;
            QMessageBox::critical(nullptr, "Error !", errorMsg);
            return false;
        }

        buffer += line + "\n";

        // 데이터 시작 감지
        if (trimmed.startsWith("<"))
            hasBody = true;

        // 종료 조건
        if (hasBody) {
            // 데이터 있는 메시지는 반드시 >.
            if (trimmed.endsWith(">.")) {
                current.fullText = buffer;

                if (!validateSmlFormat(current.fullText, errorMsg)) {
                    QMessageBox::critical(nullptr, "Error !", errorMsg);
                    return false;
                }

                outMessages.push_back(current);
                collecting = false;
            }
        }
        else {
            // 헤더만 있는 메시지
            if (trimmed.endsWith(".")) {
                current.fullText = buffer;
                outMessages.push_back(current);
                collecting = false;
            }
        }
    }

    // 파일 끝났는데 메시지 미종료
    if (collecting) {
        if (hasBody) {
            errorMsg =
                "SML message with body must end with '>.'\n"
                "Message:\n" + buffer;

            QMessageBox::critical(nullptr, "Error !", errorMsg);
            return false;
        }
        else {
            if (!buffer.trimmed().endsWith(".")) {
                errorMsg = "SML header must end with '.'";

                QMessageBox::critical(nullptr, "Error !", errorMsg);

                return false;
            }
            current.fullText = buffer;

            if (!validateSmlFormat(current.fullText, errorMsg)) {
                QMessageBox::critical(nullptr, "Error !", errorMsg);
                return false;
            }

            outMessages.push_back(current);
        }
    }

    return true;
}


QString SmlManager::makeKey(int s, int f) {
    return QString("S%1F%2").arg(s).arg(f);
}

bool SmlManager::validateSmlFormat(const QString& text, QString& errorMsg)
{
    QRegularExpression withSize(
        R"(<\s*([A-Z][A-Z0-9]*)\s*\[\s*\d+\s*\][^>]*>)"
    );

    QRegularExpression asciiNoSize(
        R"(<\s*A\s+[^>]*>)"
    );

    QRegularExpression anyClosedTag(
        R"(<\s*([A-Z]\d*)[^>\n]*>)"
    );

    QSet<QString> sizeRequiredTypes = {
        "L", "B", "BOOLEAN",
        "U1", "U2", "U4", "U8",
        "I1", "I2", "I4", "I8",
        "F4", "F8"
    };

    QStringList lines = text.split('\n');

    for (int i = 0; i < lines.size(); ++i) {
        QString line = lines[i].trimmed();

        if (line.isEmpty())
            continue;

        // <L [3] 처럼 안 닫힌 줄은 스킵
        if (!line.endsWith(">"))
            continue;

        auto m = anyClosedTag.match(line);
        if (!m.hasMatch())
            continue;

        QString type = m.captured(1);

        // ASCII
        if (type == "A") {
            if (!asciiNoSize.match(line).hasMatch() &&
                !withSize.match(line).hasMatch()) {
                errorMsg = QString(
                    "Invalid ASCII format at line %1: %2"
                ).arg(i + 1).arg(line);
                return false;
            }
            continue;
        }

        // 나머지는 size 필수
        if (sizeRequiredTypes.contains(type)) {
            if (!withSize.match(line).hasMatch()) {
                errorMsg = QString(
                    "Size required but missing at line %1: %2"
                ).arg(i + 1).arg(line);
                return false;
            }
        }
    }

    return true;
}
