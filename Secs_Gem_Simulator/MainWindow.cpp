#include "MainWindow.h"

#include <QFileDialog>
#include <QTime>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    hsmsClient = new HsmsClient(this);
    smlManager = new SmlManager(this);

    connect(ui.btnConnect, SIGNAL(clicked()), hsmsClient, SLOT(connectToEquipment()));
    connect(ui.btnDisConnect, SIGNAL(clicked()), hsmsClient, SLOT(DisconnectToEquipment()));
    connect(ui.btnLinkTest, SIGNAL(clicked()), hsmsClient, SLOT(LinkTestToEquipment()));

    connect(ui.btnOpen, SIGNAL(clicked()), this, SLOT(btnOpen_Clicked()));
    connect(ui.btnClos, SIGNAL(clicked()), this, SLOT(btnClose_Clicked()));

    connect(hsmsClient, SIGNAL(setValue(QString)), this, SLOT(SetConnectState(QString)));
    connect(Logger::instance(), SIGNAL(sendLog(QString)), this, SLOT(Logging_SecsMsg(QString)));

    ui.lw_MsgList->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui.lw_MsgList, &QListWidget::customContextMenuRequested, this, &MainWindow::onListContextMenu);
    connect(ui.lw_MsgList, &QListWidget::itemDoubleClicked, this, &MainWindow::onMsgItemDoubleClicked);

    settingMenu = new SettingMenu(this);

    // 메뉴 생성
    QMenu* Menu = ui.menuBar->addMenu("Setting");

    // 액션 생성
    SettingAction = new QAction("Setting", this);

    // 메뉴에 액션 추가
    Menu->addAction(SettingAction);

    // 시그널 연결
    connect(SettingAction, SIGNAL(triggered()), this, SLOT(OpenTimeOutMenu()));
}

MainWindow::~MainWindow()
{}

void MainWindow::btnOpen_Clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "open File", "C:/", "File (*.sml)");

    QVector<SmlMessage> messages;
    QString error;

    if (!smlManager->ParseFile(path, messages, error)) {
        return;
    }

    sxfxList.clear();
    messageMap.clear();

    for (const auto& msg : messages)
    {
        SxFx key{ msg.stream, msg.function };

        sxfxList.push_back(key);
        messageMap.emplace(key, msg);

        ui.lw_MsgList->addItem(
            QString("S%1F%2%3")
            .arg(msg.stream)
            .arg(msg.function)
            .arg(msg.wbit ? " W" : "")
        );
    }
}

void MainWindow::btnClose_Clicked()
{
    sxfxList.clear();
    messageMap.clear();
    ui.lw_MsgList->clear();
}

void MainWindow::SetConnectState(QString State)
{
    ui.lb_State->setText(State);
}

void MainWindow::Logging_SecsMsg(QString Msg)
{
    QString msg = QString("[%1] %2")
        .arg(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"))
        .arg(Msg);

    ui.tb_SecsMsg->append(msg);
}

void MainWindow::onListContextMenu(const QPoint& pos)
{
    QListWidgetItem* item = ui.lw_MsgList->itemAt(pos);
    if (!item)
        return;

    QMenu menu(this);
    QAction* showAction = menu.addAction("Show");

    QAction* selected = menu.exec(ui.lw_MsgList->viewport()->mapToGlobal(pos));
    if (selected == showAction) {
        onShowSml();
    }
}

void MainWindow::OpenTimeOutMenu()
{
    settingMenu->show();
}

void MainWindow::onShowSml()
{
    int row = ui.lw_MsgList->currentRow();
    if (row < 0 || row >= sxfxList.size())
        return;

    const SxFx& key = sxfxList[row];
    const SmlMessage& msg = messageMap.at(key);

    QDialog* dlg = new QDialog(this);
    dlg->setWindowTitle(
        QString("S%1F%2 Viewer")
        .arg(key.stream)
        .arg(key.function)
    );
    dlg->resize(700, 500);

    QTextEdit* edit = new QTextEdit(dlg);
    edit->setReadOnly(true);
    edit->setPlainText(msg.fullText);

    QVBoxLayout* layout = new QVBoxLayout(dlg);
    layout->addWidget(edit);
    dlg->setLayout(layout);

    dlg->show();
}

void MainWindow::onMsgItemDoubleClicked(QListWidgetItem* item)
{
    int row = ui.lw_MsgList->currentRow();
    if (row < 0 || row >= sxfxList.size())
        return;

    const SxFx& key = sxfxList[row];
    const SmlMessage& msg = messageMap.at(key);

    hsmsClient->SendSecsMsg(msg);
}