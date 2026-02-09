/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Secs_Gem_SimulatorClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *rbtn_State;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *tb_SecsMsg;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QPushButton *btnConnect;
    QPushButton *btnDisConnect;
    QLabel *label;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QPushButton *btnLinkTest;
    QListWidget *lw_MsgList;
    QPushButton *btnClos;
    QPushButton *btnOpen;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Secs_Gem_SimulatorClass)
    {
        if (Secs_Gem_SimulatorClass->objectName().isEmpty())
            Secs_Gem_SimulatorClass->setObjectName(QString::fromUtf8("Secs_Gem_SimulatorClass"));
        Secs_Gem_SimulatorClass->resize(600, 530);
        Secs_Gem_SimulatorClass->setMaximumSize(QSize(600, 530));
        centralWidget = new QWidget(Secs_Gem_SimulatorClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMaximumSize(QSize(600, 500));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_4 = new QFrame(centralWidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setMaximumSize(QSize(16777215, 50));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Sunken);
        horizontalLayout_6 = new QHBoxLayout(frame_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        rbtn_State = new QRadioButton(frame_6);
        rbtn_State->setObjectName(QString::fromUtf8("rbtn_State"));
        rbtn_State->setEnabled(true);

        horizontalLayout_6->addWidget(rbtn_State);


        verticalLayout_2->addWidget(frame_6);

        frame_7 = new QFrame(frame_4);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Sunken);
        horizontalLayout_4 = new QHBoxLayout(frame_7);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        scrollArea = new QScrollArea(frame_7);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setMinimumSize(QSize(300, 0));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 296, 361));
        horizontalLayout_7 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        tb_SecsMsg = new QTextEdit(scrollAreaWidgetContents);
        tb_SecsMsg->setObjectName(QString::fromUtf8("tb_SecsMsg"));

        horizontalLayout_7->addWidget(tb_SecsMsg);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_4->addWidget(scrollArea);

        frame = new QFrame(frame_7);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(215, 60));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        formLayout = new QFormLayout(frame_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        btnConnect = new QPushButton(frame_2);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        btnConnect->setMinimumSize(QSize(0, 20));
        btnConnect->setMaximumSize(QSize(100, 16777215));
        QFont font;
        btnConnect->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, btnConnect);

        btnDisConnect = new QPushButton(frame_2);
        btnDisConnect->setObjectName(QString::fromUtf8("btnDisConnect"));
        btnDisConnect->setMinimumSize(QSize(0, 20));
        btnDisConnect->setMaximumSize(QSize(100, 16777215));
        btnDisConnect->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, btnDisConnect);

        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnLinkTest = new QPushButton(frame_3);
        btnLinkTest->setObjectName(QString::fromUtf8("btnLinkTest"));

        gridLayout->addWidget(btnLinkTest, 3, 1, 1, 1);

        lw_MsgList = new QListWidget(frame_3);
        lw_MsgList->setObjectName(QString::fromUtf8("lw_MsgList"));

        gridLayout->addWidget(lw_MsgList, 2, 0, 1, 2);

        btnClos = new QPushButton(frame_3);
        btnClos->setObjectName(QString::fromUtf8("btnClos"));
        btnClos->setMaximumSize(QSize(90, 16777215));

        gridLayout->addWidget(btnClos, 1, 1, 1, 1);

        btnOpen = new QPushButton(frame_3);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setMaximumSize(QSize(90, 16777215));

        gridLayout->addWidget(btnOpen, 1, 0, 1, 1);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        verticalLayout->addWidget(frame_3);


        horizontalLayout_4->addWidget(frame);


        verticalLayout_2->addWidget(frame_7);

        frame_7->raise();
        frame_6->raise();

        horizontalLayout->addWidget(frame_4);

        Secs_Gem_SimulatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Secs_Gem_SimulatorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 20));
        Secs_Gem_SimulatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Secs_Gem_SimulatorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMouseTracking(false);
        Secs_Gem_SimulatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Secs_Gem_SimulatorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Secs_Gem_SimulatorClass->setStatusBar(statusBar);
        toolBar_2 = new QToolBar(Secs_Gem_SimulatorClass);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        Secs_Gem_SimulatorClass->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar = new QToolBar(Secs_Gem_SimulatorClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Secs_Gem_SimulatorClass->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(Secs_Gem_SimulatorClass);

        QMetaObject::connectSlotsByName(Secs_Gem_SimulatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *Secs_Gem_SimulatorClass)
    {
        Secs_Gem_SimulatorClass->setWindowTitle(QApplication::translate("Secs_Gem_SimulatorClass", "Secs_Gem_Simulator", nullptr));
        rbtn_State->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Not Connect", nullptr));
        btnConnect->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Connect", nullptr));
        btnDisConnect->setText(QApplication::translate("Secs_Gem_SimulatorClass", "DisConnect", nullptr));
        label->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Connect", nullptr));
        btnLinkTest->setText(QApplication::translate("Secs_Gem_SimulatorClass", "LinkTest", nullptr));
        btnClos->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Close", nullptr));
        btnOpen->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Open", nullptr));
        label_2->setText(QApplication::translate("Secs_Gem_SimulatorClass", "File", nullptr));
        toolBar_2->setWindowTitle(QApplication::translate("Secs_Gem_SimulatorClass", "toolBar_2", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Secs_Gem_SimulatorClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Secs_Gem_SimulatorClass: public Ui_Secs_Gem_SimulatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
