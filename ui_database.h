/********************************************************************************
** Form generated from reading UI file 'database.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_H
#define UI_DATABASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Database
{
public:
    QLineEdit *lineEdit_savename;
    QPushButton *pushButton_save;
    QPushButton *pushButton;
    QPushButton *pushButton_read;

    void setupUi(QDialog *Database)
    {
        if (Database->objectName().isEmpty())
            Database->setObjectName(QStringLiteral("Database"));
        Database->resize(400, 300);
        lineEdit_savename = new QLineEdit(Database);
        lineEdit_savename->setObjectName(QStringLiteral("lineEdit_savename"));
        lineEdit_savename->setGeometry(QRect(20, 20, 201, 25));
        pushButton_save = new QPushButton(Database);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setGeometry(QRect(20, 80, 80, 25));
        pushButton = new QPushButton(Database);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 80, 80, 25));
        pushButton_read = new QPushButton(Database);
        pushButton_read->setObjectName(QStringLiteral("pushButton_read"));
        pushButton_read->setGeometry(QRect(270, 80, 80, 25));

        retranslateUi(Database);

        QMetaObject::connectSlotsByName(Database);
    } // setupUi

    void retranslateUi(QDialog *Database)
    {
        Database->setWindowTitle(QApplication::translate("Database", "Dialog", nullptr));
        pushButton_save->setText(QApplication::translate("Database", "SAVE", nullptr));
        pushButton->setText(QApplication::translate("Database", "INSERT", nullptr));
        pushButton_read->setText(QApplication::translate("Database", "READ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Database: public Ui_Database {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_H
