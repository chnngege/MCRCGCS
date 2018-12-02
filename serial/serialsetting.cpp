#include "serialsetting.h"
#include "ui_serialsetting.h"

Serialsetting::Serialsetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Serialsetting)
{
    ui->setupUi(this);

    serial_thread = new Serialthread();
    //connect(serial_thread, SIGNAL(readyread_thread()), this, SLOT(recvMsg()));
    connect(serial_thread, SIGNAL(insert_port2combox()), this, SLOT(addserialport()));
    //serial thread start
    serial_thread->start();
}

Serialsetting::~Serialsetting()
{
    delete ui;
}

void Serialsetting::addserialport()
{
    if(serial_thread->serialfind_flag)
        ui->portName->addItem(serial_thread->port_thread.at(serial_thread->i_thread).portName());
    else return;
}

//初始化串口
bool Serialsetting::initSerialPort(){
    serial_thread->serialPort->setPortName(ui->portName->currentText());
    if (!serial_thread->serialPort->open(QIODevice::ReadWrite)){//read or write
        QMessageBox::warning(NULL,"Tip",QStringLiteral("串口打开失败"));
        return false;
    }
    serial_thread->serialPort->setBaudRate(ui->baudRate->currentText().toInt());
    serial_thread->serialPort->setDataBits(QSerialPort::Data8);
    serial_thread->serialPort->setStopBits(QSerialPort::OneStop);
    serial_thread->serialPort->setParity(QSerialPort::NoParity);
    return true;
}

void Serialsetting::sendMsg(QByteArray sendM){
    serial_thread->serialPort->write(sendM);//.data()
}

void Serialsetting::recvMsg(){
    QByteArray msg = serial_thread->msg;
    //do something
    ui->comLog->insertPlainText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") + " [recieve] " + msg.toHex() + "\n");

    qDebug() << "data is :" << msg.toHex() << "\n";
}
//open serial widget
void Serialsetting::on_buttonBox_accepted()
{
    initSerialPort();
    hide();
}

void Serialsetting::on_buttonBox_rejected()
{
    serial_thread->serialPort->close();
    hide();
    issaveflag=false;//stop save data to database
}
