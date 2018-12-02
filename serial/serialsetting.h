#ifndef SERIALSETTING_H
#define SERIALSETTING_H

#include <QDialog>
#include "packet.h"
#include "serialthread.h"

namespace Ui {
class Serialsetting;
}

class Serialsetting : public QDialog
{
    Q_OBJECT

public:
    explicit Serialsetting(QWidget *parent = nullptr);
    ~Serialsetting();
    Serialthread *serial_thread;
    void sendMsg(QByteArray sendM);
private:
    Ui::Serialsetting *ui;
    bool initSerialPort();

private slots:
    void on_buttonBox_accepted();
    void recvMsg();
    void  addserialport();
    void on_buttonBox_rejected();

private:

};

#endif // SERIALSETTING_H
