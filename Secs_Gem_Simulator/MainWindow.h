#pragma once

#include "ui_MainWindow.h"
#include "HsmsClient.h"
#include "Logger.h"
#include "SmlManager.h"
#include "SettingMenu.h"

#include <QtWidgets/QMainWindow>
#include <map>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::Secs_Gem_SimulatorClass ui;

    HsmsClient* hsmsClient;
    SmlManager* smlManager;
    SettingMenu* settingMenu;

    QVector<SxFx> sxfxList;                 // ¸®½ºÆ® À§Á¬°ú 1:1 ¸ÅÄª
    std::map<SxFx, SmlMessage> messageMap;

    QAction* SettingAction;

private slots :
    void btnOpen_Clicked();
    void btnClose_Clicked();

    void SetConnectState(const ConnectionState State);
    void Logging_SecsMsg(QString Msg);
    void onListContextMenu(const QPoint& pos);
    void onShowSml();

    void onMsgItemDoubleClicked(QListWidgetItem* item);
    void OpenTimeOutMenu();
};

