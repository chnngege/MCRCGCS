/********************************************************************************
** Form generated from reading UI file 'gyroscopeview.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GYROSCOPEVIEW_H
#define UI_GYROSCOPEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gyroscopeview
{
public:

    void setupUi(QWidget *Gyroscopeview)
    {
        if (Gyroscopeview->objectName().isEmpty())
            Gyroscopeview->setObjectName(QStringLiteral("Gyroscopeview"));
        Gyroscopeview->resize(200, 200);

        retranslateUi(Gyroscopeview);

        QMetaObject::connectSlotsByName(Gyroscopeview);
    } // setupUi

    void retranslateUi(QWidget *Gyroscopeview)
    {
        Gyroscopeview->setWindowTitle(QApplication::translate("Gyroscopeview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gyroscopeview: public Ui_Gyroscopeview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GYROSCOPEVIEW_H
