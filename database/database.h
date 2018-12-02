#ifndef DATABASE_H
#define DATABASE_H
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileDialog>
#include <QtSql>
#include <QMessageBox>
#include "serial/packet.h"
#include "protocol/helper.h"
#include "database/databasethread.h"
#include <QTime>

namespace Ui {
class Database;
}
extern bool issaveflag;

class Database : public QDialog
{
    Q_OBJECT

public:
    explicit Database(QWidget *parent = nullptr);
    ~Database();
    void startinsertdata(quint16 id_);
    Databasethread *databasethread;

public slots:
    void on_pushButton_save_clicked();

    void handleTimeout();
    void dialogshowhide();
    void readdatafromdatabase();

signals:

private slots:
    void on_pushButton_read_clicked();

private:
    Ui::Database *ui;   
    QTimer *m_pTimer;
};

#endif // DATABASE_H
