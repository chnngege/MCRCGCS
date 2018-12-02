/********************************************************************************
** Form generated from reading UI file 'toconfig.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOCONFIG_H
#define UI_TOCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Toconfig
{
public:
    QLineEdit *lineEdit_ininame;
    QPushButton *pushButton_save;

    void setupUi(QDialog *Toconfig)
    {
        if (Toconfig->objectName().isEmpty())
            Toconfig->setObjectName(QStringLiteral("Toconfig"));
        Toconfig->resize(400, 300);
        lineEdit_ininame = new QLineEdit(Toconfig);
        lineEdit_ininame->setObjectName(QStringLiteral("lineEdit_ininame"));
        lineEdit_ininame->setGeometry(QRect(10, 10, 113, 25));
        pushButton_save = new QPushButton(Toconfig);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setGeometry(QRect(140, 10, 80, 25));

        retranslateUi(Toconfig);

        QMetaObject::connectSlotsByName(Toconfig);
    } // setupUi

    void retranslateUi(QDialog *Toconfig)
    {
        Toconfig->setWindowTitle(QApplication::translate("Toconfig", "Dialog", nullptr));
        pushButton_save->setText(QApplication::translate("Toconfig", "SAVE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Toconfig: public Ui_Toconfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOCONFIG_H
