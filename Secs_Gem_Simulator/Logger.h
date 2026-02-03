#pragma once

#include <QObject>

class Logger : public QObject {
    Q_OBJECT

public:
    static Logger* instance();

    explicit Logger(QObject* parent = nullptr);
    ~Logger();

    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void getLog(QString Msg);

private:
     
    
signals:
    void sendLog(QString Log);

private slots:

};