#include "MainWindow.h"
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    hsmsClient = new HsmsClient(this);

    connect(ui.btnConnect, SIGNAL(clicked()), hsmsClient, SLOT(connectToEquipment()));
    connect(ui.btnDisConnect, SIGNAL(clicked()), hsmsClient, SLOT(DisconnectToEquipment()));
    connect(ui.btnOpen, SIGNAL(clicked()), this, SLOT(TcpIpConnect()));

    connect(hsmsClient, SIGNAL(setValue(QString)), this, SLOT(SetConnectState(QString)));
    connect(Logger::instance(), SIGNAL(sendLog(QString)), this, SLOT(Logging_SecsMsg(QString)));
}

MainWindow::~MainWindow()
{}

void MainWindow::TcpIpConnect()
{
    QString file_path = QFileDialog::getOpenFileName(this, "open File", "C:/", "File (*.*)");
}

void MainWindow::SetConnectState(QString State)
{
    ui.lb_State->setText(State);
}

void MainWindow::Logging_SecsMsg(QString Msg)
{
    ui.tb_SecsMsg->append(Msg);
}