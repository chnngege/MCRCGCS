#include "database.h"
#include "ui_database.h"

bool issaveflag = false;

Database::Database(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Database)
{
    ui->setupUi(this);
    databasethread = new Databasethread;
    databasethread->start();
}

Database::~Database()
{
    delete ui;
}

void Database::on_pushButton_save_clicked()
{
    databasethread->getsavenamefromdialog(ui->lineEdit_savename->text());
    databasethread->sendsignal_createAnewDatabase();
    hide();
    issaveflag = true;//save data to database--serialthred
}

void Database::startinsertdata(quint16 id_)
{
    databasethread->sendsignal_insertdata(id_);
}

void Database::readdatafromdatabase()
{
    show();
    ui->pushButton_save->setEnabled(false);
    ui->pushButton_read->setEnabled(true);
}

void Database::handleTimeout()
{
    static quint8 i = 1;
    databasethread->sendsignal_database2GCS(i);
    i += 1;
    if(i == 50) m_pTimer->stop();
    else m_pTimer->start(100);
}

void Database::on_pushButton_read_clicked()
{
    databasethread->getsavenamefromdialog(ui->lineEdit_savename->text());
    databasethread->sendsignal_createAnewDatabase();
    hide();
    m_pTimer = new QTimer(this);
    m_pTimer->start(100);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));
}

void Database::dialogshowhide()
{
    ui->pushButton_save->setEnabled(true);
    ui->pushButton_read->setEnabled(false);
    show();
}


