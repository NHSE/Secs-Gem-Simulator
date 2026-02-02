/********************************************************************************
** Form generated from reading UI file 'ui_MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UI_MAINWINDOW_H
#define UI_UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
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
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lb_State;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QTextBrowser *textBrowser_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QLabel *label;
    QPushButton *btnConnect;
    QPushButton *btnDisConnect;
    QFrame *frame_3;
    QGridLayout *gridLayout;
    QPushButton *btnOpen;
    QPushButton *btnClose;
    QTextBrowser *textBrowser_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

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
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setMaximumSize(QSize(16777215, 50));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_5);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        textEdit = new QTextEdit(frame_5);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        horizontalLayout_5->addWidget(textEdit);

        textEdit_2 = new QTextEdit(frame_5);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        horizontalLayout_5->addWidget(textEdit_2);

        textEdit_3 = new QTextEdit(frame_5);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));

        horizontalLayout_5->addWidget(textEdit_3);


        verticalLayout_2->addWidget(frame_5);

        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_6);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lb_State = new QLabel(frame_6);
        lb_State->setObjectName(QString::fromUtf8("lb_State"));

        horizontalLayout_6->addWidget(lb_State);


        verticalLayout_2->addWidget(frame_6);

        frame_7 = new QFrame(frame_4);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_7);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tabWidget = new QTabWidget(frame_7);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textBrowser = new QTextBrowser(tab);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        horizontalLayout_2->addWidget(textBrowser);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        textBrowser_2 = new QTextBrowser(tab_2);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));

        horizontalLayout_3->addWidget(textBrowser_2);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_4->addWidget(tabWidget);

        frame = new QFrame(frame_7);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(186, 60));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        btnConnect = new QPushButton(frame_2);
        btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
        QFont font;
        btnConnect->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, btnConnect);

        btnDisConnect = new QPushButton(frame_2);
        btnDisConnect->setObjectName(QString::fromUtf8("btnDisConnect"));
        btnDisConnect->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, btnDisConnect);


        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnOpen = new QPushButton(frame_3);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));

        gridLayout->addWidget(btnOpen, 0, 0, 1, 1);

        btnClose = new QPushButton(frame_3);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        gridLayout->addWidget(btnClose, 0, 1, 1, 1);

        textBrowser_3 = new QTextBrowser(frame_3);
        textBrowser_3->setObjectName(QString::fromUtf8("textBrowser_3"));

        gridLayout->addWidget(textBrowser_3, 1, 0, 1, 2);


        verticalLayout->addWidget(frame_3);


        horizontalLayout_4->addWidget(frame);


        verticalLayout_2->addWidget(frame_7);

        frame_7->raise();
        frame_5->raise();
        frame_6->raise();

        horizontalLayout->addWidget(frame_4);

        Secs_Gem_SimulatorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Secs_Gem_SimulatorClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 20));
        Secs_Gem_SimulatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Secs_Gem_SimulatorClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Secs_Gem_SimulatorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Secs_Gem_SimulatorClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Secs_Gem_SimulatorClass->setStatusBar(statusBar);

        retranslateUi(Secs_Gem_SimulatorClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Secs_Gem_SimulatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *Secs_Gem_SimulatorClass)
    {
        Secs_Gem_SimulatorClass->setWindowTitle(QApplication::translate("Secs_Gem_SimulatorClass", "Secs_Gem_Simulator", nullptr));
        lb_State->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Not Connect", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Secs_Gem_SimulatorClass", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Secs_Gem_SimulatorClass", "Tab 2", nullptr));
        label->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Connect", nullptr));
        btnConnect->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Connect", nullptr));
        btnDisConnect->setText(QApplication::translate("Secs_Gem_SimulatorClass", "DisConnect", nullptr));
        btnOpen->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Open", nullptr));
        btnClose->setText(QApplication::translate("Secs_Gem_SimulatorClass", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Secs_Gem_SimulatorClass: public Ui_Secs_Gem_SimulatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UI_MAINWINDOW_H
