/********************************************************************************
** Form generated from reading UI file 'signalchoose.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNALCHOOSE_H
#define UI_SIGNALCHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Signalchoose
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox_color_2;
    QComboBox *comboBox_color_3;
    QComboBox *comboBox_color_7;
    QComboBox *comboBox_signal;
    QComboBox *comboBox_color;
    QComboBox *comboBox_signal_2;
    QComboBox *comboBox_signal_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;

    void setupUi(QWidget *Signalchoose)
    {
        if (Signalchoose->objectName().isEmpty())
            Signalchoose->setObjectName(QStringLiteral("Signalchoose"));
        Signalchoose->resize(287, 138);
        Signalchoose->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(Signalchoose);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(170, 102, 111, 21));
        buttonBox->setStyleSheet(QLatin1String("QPushButton{\n"
"border:1px solid black}\n"
"QPushButton:hover{border: 2px solid ;\n"
"background-color: white;\n"
"border-right-color: rgb(255, 255, 255);\n"
"border-bottom-color: rgb(255, 255, 255);\n"
"border-top-color: rgb(136, 138, 133);\n"
"border-left-color: rgb(136, 138, 133);}\n"
"\n"
"QPushButton:pressed{border: 2px solid ;\n"
"background-color: white;\n"
"border-right-color: rgb(136, 138, 133);\n"
"border-bottom-color: rgb(136, 138, 133);\n"
"border-top-color: rgb(136, 138, 133);\n"
"border-left-color: rgb(136, 138, 133); \n"
"padding-left:3px; padding-top:3px;border-style: inset;}"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox_color_2 = new QComboBox(Signalchoose);
        comboBox_color_2->setObjectName(QStringLiteral("comboBox_color_2"));
        comboBox_color_2->setGeometry(QRect(3, 40, 41, 25));
        comboBox_color_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"position:absolute;\n"
"border:1px solid green;\n"
"	background-color: rgb(255, 255, 255);\n"
"z-index:999;\n"
"text-align:right;/*\346\227\240\346\225\210*/\n"
"	border-top-color: rgb(136, 138, 133);\n"
"	border-left-color: rgb(136, 138, 133);\n"
"	border-right-color: rgb(211, 215, 207);\n"
"	border-bottom-color: rgb(211, 215, 207);\n"
"}"));
        comboBox_color_3 = new QComboBox(Signalchoose);
        comboBox_color_3->setObjectName(QStringLiteral("comboBox_color_3"));
        comboBox_color_3->setGeometry(QRect(3, 70, 41, 25));
        comboBox_color_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"position:absolute;\n"
"border:1px solid green;\n"
"	background-color: rgb(255, 255, 255);\n"
"z-index:999;\n"
"text-align:right;/*\346\227\240\346\225\210*/\n"
"	border-top-color: rgb(136, 138, 133);\n"
"	border-left-color: rgb(136, 138, 133);\n"
"	border-right-color: rgb(211, 215, 207);\n"
"	border-bottom-color: rgb(211, 215, 207);\n"
"}"));
        comboBox_color_7 = new QComboBox(Signalchoose);
        comboBox_color_7->setObjectName(QStringLiteral("comboBox_color_7"));
        comboBox_color_7->setGeometry(QRect(3, 100, 161, 25));
        comboBox_color_7->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"color: rgb(32, 74, 135);\n"
"position:absolute;\n"
"border:1px solid green;\n"
"	background-color: rgb(255, 255, 255);\n"
"z-index:999;\n"
"	font: 75 11pt \"aakar\";\n"
"text-align:right;/*\346\227\240\346\225\210*/\n"
"	border-top-color: rgb(0, 0, 0);\n"
"	border-left-color: rgb(0, 0, 0);\n"
"	border-right-color: rgb(211, 215, 207);\n"
"	border-bottom-color: rgb(211, 215, 207);\n"
"}\n"
""));
        comboBox_signal = new QComboBox(Signalchoose);
        comboBox_signal->setObjectName(QStringLiteral("comboBox_signal"));
        comboBox_signal->setGeometry(QRect(50, 10, 191, 25));
        QPalette palette;
        QBrush brush(QColor(32, 74, 135, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        comboBox_signal->setPalette(palette);
        comboBox_signal->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"color: rgb(32, 74, 135);\n"
"position:absolute;\n"
"border:1px solid green;\n"
"	background-color: rgb(255, 255, 255);\n"
"z-index:999;\n"
"	font: 75 11pt \"aakar\";\n"
"text-align:right;/*\346\227\240\346\225\210*/\n"
"	border-top-color: rgb(0, 0, 0);\n"
"	border-left-color: rgb(0, 0, 0);\n"
"	border-right-color: rgb(211, 215, 207);\n"
"	border-bottom-color: rgb(211, 215, 207);\n"
"}\n"
""));
        comboBox_color = new QComboBox(Signalchoose);
        comboBox_color->setObjectName(QStringLiteral("comboBox_color"));
        comboBox_color->setGeometry(QRect(3, 10, 41, 25));
        QPalette palette1;
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        comboBox_color->setPalette(palette1);
        comboBox_color->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"position:absolute;\n"
"border:1px solid green;\n"
"	background-color: rgb(255, 255, 255);\n"
"z-index:999;\n"
"text-align:right;/*\346\227\240\346\225\210*/\n"
"	border-top-color: rgb(136, 138, 133);\n"
"	border-left-color: rgb(136, 138, 133);\n"
"	border-right-color: rgb(211, 215, 207);\n"
"	border-bottom-color: rgb(211, 215, 207);\n"
"}"));
        comboBox_signal_2 = new QComboBox(Signalchoose);
        comboBox_signal_2->setObjectName(QStringLiteral("comboBox_signal_2"));
        comboBox_signal_2->setGeometry(QRect(50, 40, 191, 25));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        comboBox_signal_2->setPalette(palette2);
        comboBox_signal_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"color: rgb(32, 74, 135);\n"
"position:absolute;\n"
"border:1px solid green;\n"
"	background-color: rgb(255, 255, 255);\n"
"z-index:999;\n"
"	font: 75 11pt \"aakar\";\n"
"text-align:right;/*\346\227\240\346\225\210*/\n"
"	border-top-color: rgb(0, 0, 0);\n"
"	border-left-color: rgb(0, 0, 0);\n"
"	border-right-color: rgb(211, 215, 207);\n"
"	border-bottom-color: rgb(211, 215, 207);\n"
"}\n"
""));
        comboBox_signal_3 = new QComboBox(Signalchoose);
        comboBox_signal_3->setObjectName(QStringLiteral("comboBox_signal_3"));
        comboBox_signal_3->setGeometry(QRect(50, 70, 191, 25));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        comboBox_signal_3->setPalette(palette3);
        comboBox_signal_3->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"color: rgb(32, 74, 135);\n"
"position:absolute;\n"
"border:1px solid green;\n"
"	background-color: rgb(255, 255, 255);\n"
"z-index:999;\n"
"	font: 75 11pt \"aakar\";\n"
"text-align:right;/*\346\227\240\346\225\210*/\n"
"	border-top-color: rgb(0, 0, 0);\n"
"	border-left-color: rgb(0, 0, 0);\n"
"	border-right-color: rgb(211, 215, 207);\n"
"	border-bottom-color: rgb(211, 215, 207);\n"
"}\n"
""));
        checkBox = new QCheckBox(Signalchoose);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(260, 12, 21, 21));
        checkBox->setStyleSheet(QLatin1String("QCheckBox {\n"
"    spacing: 5px; \n"
"}\n"
" \n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;\n"
"\n"
"}"));
        checkBox->setIconSize(QSize(16, 16));
        checkBox_2 = new QCheckBox(Signalchoose);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(260, 42, 21, 21));
        checkBox_2->setStyleSheet(QLatin1String("QCheckBox {\n"
"    spacing: 5px; \n"
"}\n"
" \n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;\n"
"\n"
"}"));
        checkBox_2->setIconSize(QSize(16, 16));
        checkBox_3 = new QCheckBox(Signalchoose);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(260, 72, 21, 21));
        checkBox_3->setStyleSheet(QLatin1String("QCheckBox {\n"
"    spacing: 5px; \n"
"}\n"
" \n"
"QCheckBox::indicator {\n"
"    width: 17px;\n"
"    height: 17px;\n"
"\n"
"}"));
        checkBox_3->setIconSize(QSize(16, 16));

        retranslateUi(Signalchoose);

        QMetaObject::connectSlotsByName(Signalchoose);
    } // setupUi

    void retranslateUi(QWidget *Signalchoose)
    {
        Signalchoose->setWindowTitle(QApplication::translate("Signalchoose", "Form", nullptr));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        checkBox_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Signalchoose: public Ui_Signalchoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNALCHOOSE_H
