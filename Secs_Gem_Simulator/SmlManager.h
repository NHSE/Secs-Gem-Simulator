#pragma once

#include <QObject>

#include <SecsType.h>

class SmlManager : public QObject {
	Q_OBJECT

public:
	SmlManager(QObject* parent = nullptr);
	~SmlManager();

	bool ParseFile(const QString& path, QVector<SmlMessage>& outMessages, QString& errorMsg);

private:
	QString makeKey(int s, int f);
	bool validateSmlFormat(const QString& text, QString& errorMsg);
};