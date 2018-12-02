/********************************************************************************
** Form generated from reading UI file 'serialsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALSETTING_H
#define UI_SERIALSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serialsetting
{
public:
    QWidget *widget;
    QLabel *label_19;
    QComboBox *baudRate;
    QLabel *label_15;
    QComboBox *portName;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QTextBrowser *comLog;

    void setupUi(QWidget *Serialsetting)
    {
        if (Serialsetting->objectName().isEmpty())
            Serialsetting->setObjectName(QStringLiteral("Serialsetting"));
        Serialsetting->resize(586, 142);
        Serialsetting->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        widget = new QWidget(Serialsetting);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 251, 81));
        widget->setStyleSheet(QLatin1String("QWidget{\n"
"border:1px solid grey\n"
"};"));
        label_19 = new QLabel(widget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 50, 71, 21));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
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
        label_19->setPalette(palette);
        label_19->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 57 9pt \"aakar\";"));
        baudRate = new QComboBox(widget);
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->setObjectName(QStringLiteral("baudRate"));
        baudRate->setGeometry(QRect(90, 50, 151, 22));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        baudRate->setPalette(palette1);
        baudRate->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 57 9pt \"aakar\";\n"
"background-color: rgb(255, 255, 255);"));
        label_15 = new QLabel(widget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 10, 71, 21));
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
        label_15->setPalette(palette2);
        label_15->setStyleSheet(QLatin1String("font: 57 9pt \"aakar\";\n"
"\n"
"color: rgb(0, 0, 0);"));
        portName = new QComboBox(widget);
        portName->setObjectName(QStringLiteral("portName"));
        portName->setGeometry(QRect(90, 10, 151, 22));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        portName->setPalette(palette3);
        portName->setStyleSheet(QLatin1String("font: 57 9pt \"aakar\";\n"
"color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        label = new QLabel(Serialsetting);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 141, 17));
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(Serialsetting);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(160, 110, 101, 20));
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
        pushButton = new QPushButton(Serialsetting);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 110, 80, 21));
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border:1px solid black};\n"
"font: 57 9pt \"aakar\";"));
        comLog = new QTextBrowser(Serialsetting);
        comLog->setObjectName(QStringLiteral("comLog"));
        comLog->setGeometry(QRect(290, -12, 291, 151));
        comLog->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        retranslateUi(Serialsetting);

        QMetaObject::connectSlotsByName(Serialsetting);
    } // setupUi

    void retranslateUi(QWidget *Serialsetting)
    {
        Serialsetting->setWindowTitle(QApplication::translate("Serialsetting", "Form", nullptr));
        label_19->setText(QApplication::translate("Serialsetting", "baudrate\357\274\232", nullptr));
        baudRate->setItemText(0, QApplication::translate("Serialsetting", "9600", nullptr));
        baudRate->setItemText(1, QApplication::translate("Serialsetting", "4800", nullptr));
        baudRate->setItemText(2, QApplication::translate("Serialsetting", "19200", nullptr));
        baudRate->setItemText(3, QApplication::translate("Serialsetting", "38400", nullptr));

        label_15->setText(QApplication::translate("Serialsetting", "portname\357\274\232", nullptr));
        label->setText(QApplication::translate("Serialsetting", "Serial port configuration", nullptr));
        pushButton->setText(QApplication::translate("Serialsetting", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serialsetting: public Ui_Serialsetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALSETTING_H
