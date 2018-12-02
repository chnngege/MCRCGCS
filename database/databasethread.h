#ifndef DATABASETHREAD_H
#define DATABASETHREAD_H
#include <QThread>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QFileDialog>
#include <QtSql>
#include <QMessageBox>
#include "serial/packet.h"
#include "protocol/helper.h"

class Databasethread : public QThread
{
    Q_OBJECT
    
public:
    explicit Databasethread(){}
    void sendsignal_createAnewDatabase();
    void getsavenamefromdialog(QString savename);
    void sendsignal_insertdata(quint16 id_);
    void sendsignal_database2GCS(quint8 id_sig);

protected:
    void run();

signals:
    void thread_createAnewDatabase();
    void thread_insertdata();
    void thread_database2GCS();
    void data2GCSfinished();

private slots:
    void insertdata();
    void database2GCS();
    void createAnewDatabase();

private:
    QString fileName;
    quint16 id_insertdata;
    quint8 i_database2GCS;

};

#endif // DATABASETHREAD_H
