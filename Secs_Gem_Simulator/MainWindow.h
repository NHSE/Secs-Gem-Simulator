#pragma once

#include "ui_MainWindow.h"
#include "HsmsClient.h"
#include "Logger.h"
#include "SmlManager.h"

#include <QtWidgets/QMainWindow>
#include <map>

/*
namespace std {
    template <>
    struct hash<SxFx> {
        size_t operator()(const SxFx& k) const {
            return (std::hash<int>()(k.stream) << 1)
                ^ std::hash<int>()(k.function);
        }
    };
}
*/

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

    QVector<SxFx> sxfxList;                 // ¸®½ºÆ® À§Á¬°ú 1:1 ¸ÅÄª
    std::map<SxFx, SmlMessage> messageMap;

private slots :
    void btnOpen_Clicked();
    void btnClose_Clicked();

    void SetConnectState(QString State);
    void Logging_SecsMsg(QString Msg);
    void onListContextMenu(const QPoint& pos);
    void onShowSml();

    void onMsgItemDoubleClicked(QListWidgetItem* item);
};

