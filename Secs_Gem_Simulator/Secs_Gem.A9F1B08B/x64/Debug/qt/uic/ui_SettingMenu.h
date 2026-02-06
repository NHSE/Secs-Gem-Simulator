/********************************************************************************
** Form generated from reading UI file 'SettingMenu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGMENU_H
#define UI_SETTINGMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *Timer;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QTextEdit *tb_T3timer;
    QLabel *label_7;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QTextEdit *tb_T5timer;
    QLabel *label_8;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QTextEdit *tb_T6timer;
    QLabel *label_9;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QTextEdit *tb_T7timer;
    QLabel *label_10;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QTextEdit *tb_T8timer;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer;
    QWidget *tab_2;
    QPushButton *btn_Save;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(467, 442);
        verticalLayout_4 = new QVBoxLayout(Dialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        Timer = new QWidget();
        Timer->setObjectName(QString::fromUtf8("Timer"));
        verticalLayout_2 = new QVBoxLayout(Timer);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_2 = new QFrame(Timer);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 40));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_2->addWidget(frame_2);

        frame_9 = new QFrame(Timer);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_9);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        frame_3 = new QFrame(frame_9);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        tb_T3timer = new QTextEdit(frame_4);
        tb_T3timer->setObjectName(QString::fromUtf8("tb_T3timer"));
        tb_T3timer->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(tb_T3timer);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);


        verticalLayout_5->addWidget(frame_4);

        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(frame_5);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        tb_T5timer = new QTextEdit(frame_5);
        tb_T5timer->setObjectName(QString::fromUtf8("tb_T5timer"));
        tb_T5timer->setMinimumSize(QSize(0, 30));

        horizontalLayout_2->addWidget(tb_T5timer);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);


        verticalLayout_5->addWidget(frame_5);

        frame_8 = new QFrame(frame_3);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_8);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(frame_8);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        tb_T6timer = new QTextEdit(frame_8);
        tb_T6timer->setObjectName(QString::fromUtf8("tb_T6timer"));
        tb_T6timer->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(tb_T6timer);

        label_9 = new QLabel(frame_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);


        verticalLayout_5->addWidget(frame_8);

        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_7);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(frame_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        tb_T7timer = new QTextEdit(frame_7);
        tb_T7timer->setObjectName(QString::fromUtf8("tb_T7timer"));
        tb_T7timer->setMinimumSize(QSize(0, 30));

        horizontalLayout_4->addWidget(tb_T7timer);

        label_10 = new QLabel(frame_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_4->addWidget(label_10);


        verticalLayout_5->addWidget(frame_7);

        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(frame_6);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        tb_T8timer = new QTextEdit(frame_6);
        tb_T8timer->setObjectName(QString::fromUtf8("tb_T8timer"));
        tb_T8timer->setMinimumSize(QSize(0, 30));

        horizontalLayout_5->addWidget(tb_T8timer);

        label_11 = new QLabel(frame_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_5->addWidget(label_11);


        verticalLayout_5->addWidget(frame_6);


        horizontalLayout_6->addWidget(frame_3);

        horizontalSpacer = new QSpacerItem(500, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(frame_9);

        tabWidget->addTab(Timer, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        btn_Save = new QPushButton(frame);
        btn_Save->setObjectName(QString::fromUtf8("btn_Save"));
        btn_Save->setMaximumSize(QSize(60, 20));

        verticalLayout->addWidget(btn_Save, 0, Qt::AlignRight);


        verticalLayout_4->addWidget(frame);


        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QApplication::translate("Dialog", "Time Out Setting", nullptr));
        label_2->setText(QApplication::translate("Dialog", "T3", nullptr));
        label_7->setText(QApplication::translate("Dialog", "sec", nullptr));
        label_3->setText(QApplication::translate("Dialog", "T5", nullptr));
        label_8->setText(QApplication::translate("Dialog", "sec", nullptr));
        label_4->setText(QApplication::translate("Dialog", "T6", nullptr));
        label_9->setText(QApplication::translate("Dialog", "sec", nullptr));
        label_5->setText(QApplication::translate("Dialog", "T7", nullptr));
        label_10->setText(QApplication::translate("Dialog", "sec", nullptr));
        label_6->setText(QApplication::translate("Dialog", "T8", nullptr));
        label_11->setText(QApplication::translate("Dialog", "sec", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Timer), QApplication::translate("Dialog", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "Tab 2", nullptr));
        btn_Save->setText(QApplication::translate("Dialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGMENU_H
