/********************************************************************************
** Form generated from reading UI file 'setpoint.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPOINT_H
#define UI_SETPOINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setpoint
{
public:

    void setupUi(QWidget *Setpoint)
    {
        if (Setpoint->objectName().isEmpty())
            Setpoint->setObjectName(QStringLiteral("Setpoint"));
        Setpoint->resize(856, 514);

        retranslateUi(Setpoint);

        QMetaObject::connectSlotsByName(Setpoint);
    } // setupUi

    void retranslateUi(QWidget *Setpoint)
    {
        Setpoint->setWindowTitle(QApplication::translate("Setpoint", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Setpoint: public Ui_Setpoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPOINT_H
