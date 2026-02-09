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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QFrame *frame_13;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_2;
    QFrame *frame_14;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLineEdit *tb_Ip;
    QLabel *label_3;
    QLineEdit *tb_Port;
    QLabel *label_5;
    QLineEdit *tb_Deviceid;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_T3;
    QLineEdit *tb_T3timer;
    QLabel *label_7;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lb_T5;
    QLineEdit *tb_T5timer;
    QLabel *label_8;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lb_T6;
    QLineEdit *tb_T6timer;
    QLabel *label_9;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lb_T7;
    QLineEdit *tb_T7timer;
    QLabel *label_10;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lb_T8;
    QLineEdit *tb_T8timer;
    QLabel *label_11;
    QTextBrowser *textBrowser;
    QPushButton *btn_Save;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(651, 524);
        Dialog->setMinimumSize(QSize(651, 480));
        Dialog->setMaximumSize(QSize(651, 524));
        verticalLayout_4 = new QVBoxLayout(Dialog);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        frame = new QFrame(Dialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame_13 = new QFrame(frame);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setFrameShape(QFrame::Box);
        frame_13->setFrameShadow(QFrame::Sunken);
        verticalLayout_8 = new QVBoxLayout(frame_13);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_2 = new QLabel(frame_13);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_8->addWidget(label_2, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(frame_13);

        frame_14 = new QFrame(frame);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setFrameShape(QFrame::Box);
        frame_14->setFrameShadow(QFrame::Sunken);
        horizontalLayout_9 = new QHBoxLayout(frame_14);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_4 = new QLabel(frame_14);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_9->addWidget(label_4);

        tb_Ip = new QLineEdit(frame_14);
        tb_Ip->setObjectName(QString::fromUtf8("tb_Ip"));
        tb_Ip->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(tb_Ip);

        label_3 = new QLabel(frame_14);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_9->addWidget(label_3);

        tb_Port = new QLineEdit(frame_14);
        tb_Port->setObjectName(QString::fromUtf8("tb_Port"));
        tb_Port->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(tb_Port);

        label_5 = new QLabel(frame_14);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_9->addWidget(label_5);

        tb_Deviceid = new QLineEdit(frame_14);
        tb_Deviceid->setObjectName(QString::fromUtf8("tb_Deviceid"));
        tb_Deviceid->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(tb_Deviceid);


        verticalLayout->addWidget(frame_14);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 40));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_3->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout->addWidget(frame_2);

        frame_9 = new QFrame(frame);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::Box);
        frame_9->setFrameShadow(QFrame::Sunken);
        horizontalLayout_6 = new QHBoxLayout(frame_9);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        frame_3 = new QFrame(frame_9);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Sunken);
        verticalLayout_5 = new QVBoxLayout(frame_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_4 = new QFrame(frame_3);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(frame_4);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lb_T3 = new QLabel(frame_4);
        lb_T3->setObjectName(QString::fromUtf8("lb_T3"));

        horizontalLayout->addWidget(lb_T3);

        tb_T3timer = new QLineEdit(frame_4);
        tb_T3timer->setObjectName(QString::fromUtf8("tb_T3timer"));
        tb_T3timer->setMinimumSize(QSize(0, 30));
        tb_T3timer->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(tb_T3timer);

        label_7 = new QLabel(frame_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);


        verticalLayout_5->addWidget(frame_4);

        frame_5 = new QFrame(frame_3);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Sunken);
        horizontalLayout_2 = new QHBoxLayout(frame_5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lb_T5 = new QLabel(frame_5);
        lb_T5->setObjectName(QString::fromUtf8("lb_T5"));

        horizontalLayout_2->addWidget(lb_T5);

        tb_T5timer = new QLineEdit(frame_5);
        tb_T5timer->setObjectName(QString::fromUtf8("tb_T5timer"));
        tb_T5timer->setMinimumSize(QSize(0, 30));
        tb_T5timer->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(tb_T5timer);

        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_2->addWidget(label_8);


        verticalLayout_5->addWidget(frame_5);

        frame_8 = new QFrame(frame_3);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::Box);
        frame_8->setFrameShadow(QFrame::Sunken);
        horizontalLayout_3 = new QHBoxLayout(frame_8);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lb_T6 = new QLabel(frame_8);
        lb_T6->setObjectName(QString::fromUtf8("lb_T6"));

        horizontalLayout_3->addWidget(lb_T6);

        tb_T6timer = new QLineEdit(frame_8);
        tb_T6timer->setObjectName(QString::fromUtf8("tb_T6timer"));
        tb_T6timer->setMinimumSize(QSize(0, 30));
        tb_T6timer->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(tb_T6timer);

        label_9 = new QLabel(frame_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_3->addWidget(label_9);


        verticalLayout_5->addWidget(frame_8);

        frame_7 = new QFrame(frame_3);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Sunken);
        horizontalLayout_4 = new QHBoxLayout(frame_7);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lb_T7 = new QLabel(frame_7);
        lb_T7->setObjectName(QString::fromUtf8("lb_T7"));
        lb_T7->setEnabled(false);

        horizontalLayout_4->addWidget(lb_T7);

        tb_T7timer = new QLineEdit(frame_7);
        tb_T7timer->setObjectName(QString::fromUtf8("tb_T7timer"));
        tb_T7timer->setEnabled(false);
        tb_T7timer->setMinimumSize(QSize(0, 30));
        tb_T7timer->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(tb_T7timer);

        label_10 = new QLabel(frame_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(false);

        horizontalLayout_4->addWidget(label_10);


        verticalLayout_5->addWidget(frame_7);

        frame_6 = new QFrame(frame_3);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Sunken);
        horizontalLayout_5 = new QHBoxLayout(frame_6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lb_T8 = new QLabel(frame_6);
        lb_T8->setObjectName(QString::fromUtf8("lb_T8"));
        lb_T8->setEnabled(false);

        horizontalLayout_5->addWidget(lb_T8);

        tb_T8timer = new QLineEdit(frame_6);
        tb_T8timer->setObjectName(QString::fromUtf8("tb_T8timer"));
        tb_T8timer->setEnabled(false);
        tb_T8timer->setMinimumSize(QSize(0, 30));
        tb_T8timer->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(tb_T8timer);

        label_11 = new QLabel(frame_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(false);

        horizontalLayout_5->addWidget(label_11);


        verticalLayout_5->addWidget(frame_6);


        horizontalLayout_6->addWidget(frame_3);

        textBrowser = new QTextBrowser(frame_9);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(400, 0));

        horizontalLayout_6->addWidget(textBrowser);


        verticalLayout->addWidget(frame_9);

        btn_Save = new QPushButton(frame);
        btn_Save->setObjectName(QString::fromUtf8("btn_Save"));
        btn_Save->setMaximumSize(QSize(60, 20));

        verticalLayout->addWidget(btn_Save, 0, Qt::AlignRight);


        verticalLayout_4->addWidget(frame);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label_2->setText(QApplication::translate("Dialog", "IP Setting", nullptr));
        label_4->setText(QApplication::translate("Dialog", "IP", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Port", nullptr));
        label_5->setText(QApplication::translate("Dialog", "Device ID", nullptr));
        label->setText(QApplication::translate("Dialog", "Time Out Setting", nullptr));
        lb_T3->setText(QApplication::translate("Dialog", "T3", nullptr));
        label_7->setText(QApplication::translate("Dialog", "sec", nullptr));
        lb_T5->setText(QApplication::translate("Dialog", "T5", nullptr));
        label_8->setText(QApplication::translate("Dialog", "sec", nullptr));
        lb_T6->setText(QApplication::translate("Dialog", "T6", nullptr));
        label_9->setText(QApplication::translate("Dialog", "sec", nullptr));
        lb_T7->setText(QApplication::translate("Dialog", "T7", nullptr));
        label_10->setText(QApplication::translate("Dialog", "sec", nullptr));
        lb_T8->setText(QApplication::translate("Dialog", "T8", nullptr));
        label_11->setText(QApplication::translate("Dialog", "sec", nullptr));
        textBrowser->setHtml(QApplication::translate("Dialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<table border=\"1\" style=\" margin-top:0px; margin-bottom:22px; margin-left:0px; margin-right:0px;\" cellspacing=\"2\" cellpadding=\"0\">\n"
"<tr>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">name</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -q"
                        "t-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">description</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">typical</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">value<br />range</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" ma"
                        "rgin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">T3</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#666666;\">Reply timeout</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\"><br /></span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#666666;\">HSMS</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">\302\240\354\227\220\354\204\234 Primary Message\353\245\274 \354\240\204\354"
                        "\206\241\355\225\234 \353\213\244\354\235\214 Reply Mesage\353\245\274 \354\204\244\354\240\225\353\220\234 \354\213\234\352\260\204\354\225\210\354\227\220 \353\260\233\354\247\200 \353\252\273\355\226\210\354\235\204 \353\225\214 \353\260\234\354\203\235\302\240</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">45</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">1~120</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-"
                        "left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">T5</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#000000; background-color:#ffffff;\">Connect Separation Timeout</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\"><br /></span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#666666;\">HSMS</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,san"
                        "s-serif'; font-size:8pt; color:#666666;\">\302\240\354\227\220\354\204\234 \354\206\214\354\274\223\354\235\264 \354\227\260\352\262\260\353\220\234 \355\233\204 \354\204\244\354\240\225\353\220\234 \354\213\234\352\260\204\353\217\231\354\225\210 selection handshaking\354\235\204 \354\247\204\355\226\211\355\225\230\352\263\240 \354\213\244\355\214\250\355\225\230\353\251\264 connection\354\235\204 \353\201\212\352\263\240 \354\236\254\354\213\234\353\217\204\355\225\230\352\270\260\352\271\214\354\247\200 \352\270\260\353\213\244\353\246\254\353\212\224 \354\213\234\352\260\204</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">10</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; paddin"
                        "g-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">1~240</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">T6</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#666666;\">Control timeout</span><span "
                        "style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\"><br /></span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#666666;\">HSMS</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">\302\240\354\227\220\354\204\234 Control Message\353\245\274 \354\240\204\354\206\241\355\225\234 \355\233\204 \354\235\221\353\213\265 rsp \353\251\224\354\204\270\354\247\200\352\260\200 \354\204\244\354\240\225\353\220\234 \354\213\234\352\260\204 \354\225\210\354\227\220 \353\217\204\354\260\251\355\225\230\354\247\200 \354\225\212\354\225\230\354\235\204 \353\225\214 \353\260\234\354\203\235</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDG"
                        "othicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">5</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">1~240</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">T7</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent"
                        ":0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#000000; background-color:#ffffff;\">N</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#666666;\">ot selected timeout</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\"><br /></span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#666666;\">HSMS</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">\302\240\354\227\220\354\204\234 \354\206\214\354\274\223\354\235\264 connect \353\220\234 \355\233\204 \354\204\244\354\240\225\353\220\234 \354\213\234\352\260\204 \354\225\210\354\227\220 select.req \353\251\224\354\204\270\354\247\200\353\245\274 \353\260\233\354\247\200 \353\252\273 \355\226\210\354\235\204 \353\225\214 \353\260\234\354\203\235</span></p></td>"
                        "\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">10</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">1~240</span></p></td></tr>\n"
"<tr>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-"
                        "size:8pt; color:#666666;\">T8</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#000000; background-color:#ffffff;\">Network Intercharacter Time</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\"><br /></span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; font-weight:600; color:#666666;\">HSMS</span><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">\302\240\354\227\220\354\204\234 \353\215\260\354\235\264\355\204\260 \353\254\270\354\236\220\354\227\264\354\235\204 \354\210\230\354\213\240 \355\233\204 \353\213\244\354\235\214 \353\215\260\354\235\264\355\204\260 \353"
                        "\254\270\354\236\220\354\227\264\354\235\204 \354\204\244\354\240\225\353\220\234 \354\213\234\352\260\204 \354\225\210\354\227\220 \353\260\233\354\247\200 \353\252\273 \355\226\210\354\235\204 \353\225\214 \353\260\234\354\203\235</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">5</span></p></td>\n"
"<td style=\" padding-left:0; padding-right:0; padding-top:7; padding-bottom:11;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'AppleSDGothicNeo,Noto Sans KR,sans-serif'; font-size:8pt; color:#666666;\">1~120</span></p></td></tr></table></body></html>", nullptr));
        btn_Save->setText(QApplication::translate("Dialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGMENU_H
