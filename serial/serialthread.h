#ifndef SERIALTHREAD_H
#define SERIALTHREAD_H

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include <QThread>
#include "packet.h"
#include "protocol/helper.h"
#include "database/database.h"

class Serialthread : public QThread {
    Q_OBJECT
public:
    explicit Serialthread();
    QSerialPort *serialPort;
    void findFreePorts();
    int Recognize_value(char ch);
    void AP_Telemetry(quint8 RX_Buffer[USART_REC_LEN]);
    QByteArray ConvertHexChar(QByteArray string_buffer);
    bool serialfind_flag;//1:have searched serial port flag
    SensorData s;
    QList<QSerialPortInfo> port_thread;
    int i_thread;
    QByteArray msg ;

signals:
    void addserialport();
    void data_progressfinished();
    void readyread_thread();
    void insert_port2combox();

private slots:
    void receive_thread();
    void emit_readyRead();
protected:
    void run();

private:
    QByteArray received;
    Database *sensordatabase;

};



#endif // SERIALTHREAD_H
