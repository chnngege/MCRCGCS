#include "serialthread.h"
#include "mainwindow.h"

Serialthread::Serialthread()
{
    //this->serialPort = new QSerialPort;
    //findFreePorts();
    sensordatabase = new Database;

}

void Serialthread::run()
{
    this->serialPort = new QSerialPort;

    findFreePorts();
    connect(this->serialPort, SIGNAL(readyRead()), this, SLOT(receive_thread()));
}
void Serialthread::emit_readyRead()
{
    msg = serialPort->readAll();

    emit(readyread_thread());
}
//寻找空闲状态串口
void Serialthread::findFreePorts(){
QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
for (int i = 0; i < ports.size(); ++i){
    if (ports.at(i).isBusy()){
        ports.removeAt(i);
        continue;
     }
    port_thread = ports;
    i_thread = i;
    serialfind_flag = true;//have searched serial port flag
    emit (insert_port2combox());//ui->additem
}
if (!ports.size()){
   //QMessageBox::warning(NULL,"Tip",QStringLiteral("找不到空闲串口"));
   serialfind_flag = false;
   return;
 }
}

//接受来自串口的信息
void Serialthread::receive_thread(){
    QByteArray BUFFER;
    static quint16 id = 1;
    quint8 outquint8[USART_REC_LEN];
    QByteArray received_BUFFER = this->serialPort->readAll().toHex();
    //qDebug() << received_BUFFER << received_BUFFER.length();
    if(received.length() < USART_REC_LEN*2)
        received += received_BUFFER;
    else if(received.length() > USART_REC_LEN*2){
        received.clear();
        return;
    }
    //qDebug() << received.length() << received << received.left(2) << received.mid(2,2) ;
    if(received.left(6) == "4e4156")
    {
        if(received.length() == USART_REC_LEN*2)
        {
                BUFFER = ConvertHexChar(received);

                memcpy(&outquint8, BUFFER.data(), USART_REC_LEN);
                //qDebug() << outquint8;
                AP_Telemetry(outquint8);//decode
                if(issaveflag){
                    sensordatabase->startinsertdata(id);//save data to database
                    id += 1;
                }
                received.clear();
                emit(data_progressfinished());
        }
        else return;
    }
    else
    {
        received.clear();
        return;
    }
}

//receive data
void Serialthread::AP_Telemetry(quint8 RX_Buffer[USART_REC_LEN])
{
    Telemetry_BASE_GS = RX_Buffer_to_Telemetry_BASE_GS(RX_Buffer);
    Decode_Telemetry_BASE(RX_Buffer, Telemetry_BASE_GS, AP_DATA2GCS.UAV_FlagByte, AP_DATA2GCS.UAV_Active_PPM_num, AP_DATA2GCS.UAV_FM_Type, AP_DATA2GCS.UAV_AP_Seconds, AP_DATA2GCS.UAV_INS_Attitude,\
                                                                        AP_DATA2GCS.UAV_GPS_Satellite_num, AP_DATA2GCS.UAV_Current, AP_DATA2GCS.UAV_INS_Height, AP_DATA2GCS.UAV_GPS_Height, AP_DATA2GCS.UAV_BCS_Vel, AP_DATA2GCS.UAV_Lat, AP_DATA2GCS.UAV_Lon,\
                                                                        AP_DATA2GCS.UAV_GPS_Yaw, AP_DATA2GCS.UAV_GPS_Vel, AP_DATA2GCS.UAV_Attitude, AP_DATA2GCS.UAV_GPS_HDOP, AP_DATA2GCS.UAV_Voltage, AP_DATA2GCS.UAV_Height, AP_DATA2GCS.UAV_Distance, \
                                                                        AP_DATA2GCS.UAV_Vertical_Yaw_Parameter, AP_DATA2GCS.UAV_Displacement_to_PPM, AP_DATA2GCS.UAV_Bump_Flag, AP_DATA2GCS.UAV_LData);
}


QByteArray Serialthread::ConvertHexChar(QByteArray string_buffer)
{
    QByteArray BUFFER;
    unsigned int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = string_buffer.length();
    BUFFER.resize(len / 2);

    char lstr,hstr;
    for (int i = 0; i < len; i++) {

        hstr = string_buffer.at(i);
        lstr = string_buffer.at(i+1);

        hexdata = (unsigned int)Recognize_value(hstr);
        lowhexdata = (unsigned int)Recognize_value(lstr);

        if ((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16 + lowhexdata;

        i++;

        BUFFER[hexdatalen] = (quint8)hexdata;

        //qDebug() << "the index :"  << (quint8)hexdata;

        ++hexdatalen;
    }
        BUFFER.resize(hexdatalen);
        //qDebug() << BUFFER.toHex() << BUFFER[1] << BUFFER[2] << BUFFER[3] << BUFFER[4] << BUFFER[5];
    return BUFFER;
}

int Serialthread::Recognize_value(char ch)
{
    if ((ch >= '0') && (ch <= '9'))
        return ch - 0x30;
    else if ((ch >= 'A') && (ch <= 'F'))
        return ch - 'A' + 10;
    else if ((ch >= 'a') && (ch <= 'f'))
        return ch - 'a' + 10;
    else return ch -  ch;
}



