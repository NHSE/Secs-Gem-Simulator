#include "Logger.h"

Logger* Logger::instance()
{
	static Logger instance;
	return &instance;
}


Logger::Logger(QObject* parent)
	: QObject(parent)
{

}

Logger::~Logger()
{

}

void Logger::getLog(QString Msg)
{
	emit sendLog(Msg);
}