/********************************************************************************
** Form generated from reading UI file 'magview.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAGVIEW_H
#define UI_MAGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Magview
{
public:

    void setupUi(QWidget *Magview)
    {
        if (Magview->objectName().isEmpty())
            Magview->setObjectName(QStringLiteral("Magview"));
        Magview->resize(200, 200);

        retranslateUi(Magview);

        QMetaObject::connectSlotsByName(Magview);
    } // setupUi

    void retranslateUi(QWidget *Magview)
    {
        Magview->setWindowTitle(QApplication::translate("Magview", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Magview: public Ui_Magview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAGVIEW_H
