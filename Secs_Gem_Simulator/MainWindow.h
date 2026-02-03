#pragma once

#include "ui_MainWindow.h"
#include "HsmsClient.h"
#include "Logger.h"

#include <QtWidgets/QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::Secs_Gem_SimulatorClass ui;
    HsmsClient* hsmsClient;

private slots :
    void TcpIpConnect();
    void SetConnectState(QString State);
    void Logging_SecsMsg(QString Msg);
};

