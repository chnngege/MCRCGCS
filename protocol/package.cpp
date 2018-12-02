#include "helper.h"
#include "package.h"
#include "checksum.h"
#include "types.h"

//package1
quint8 function_num = 0;

//package2
quint8 PPM_num = 0;
quint16 Vel = 0;
quint16 H = 0;
quint16 Lat = 0;
quint16 Lon = 0;
quint16 Param1 = 0;
quint16 Param2 = 0;
//data from AP
AP_DATA2GCS_struct AP_DATA2GCS ;

Command_TypeDef Command;
Command_TypeDef Command_AP;
FM_TypeDef FM;
FM_TypeDef FM_AP;
Telemetry_BASE_TypeDef Telemetry_BASE;
Telemetry_BASE_TypeDef Telemetry_BASE_GS;
quint8 TX_Buffer[USART_REC_LEN];
struct Progress_Bar map_Progress_Bar;

//*************************************************//
Package::Package(QObject *parent) :
      QObject(parent) {
    serial_protocol = new Serialsetting;
}
//轨迹规划--发送航点轨迹
void Package::AP_Trajectory_Planning()
{
    for(;current_waypoint_number<MAP_PLANNING.num_points;current_waypoint_number++){
        FM = Finalize_FM(MAP_PLANNING.num_points, 1,
                     MAP_PLANNING.map_v[current_waypoint_number],
                     MAP_PLANNING.map_h[current_waypoint_number],
                     MAP_PLANNING.lnglat_array[current_waypoint_number][1],
                     MAP_PLANNING.lnglat_array[current_waypoint_number][0],
                     MAP_PLANNING.map_p[current_waypoint_number],
                     MAP_PLANNING.map_pp[current_waypoint_number]);
        FM_to_TX_Buffer(FM, TX_Buffer);
        QByteArray sendM=InnitialQByteArry(TX_Buffer,32);
        serial_protocol->sendMsg(sendM);
        map_Progress_Bar.MAP_POINTS = 100 * current_waypoint_number / MAP_PLANNING.num_points;//发送航点任务的进度条
        emit(map_progressbar());
    }
    map_Progress_Bar.MAP_POINTS = 100;
    emit(map_progressbar());
}
//********************single command***********************************//
void Package::FM_Task()
{
    Command = Finalize_Command(0x10, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}

void Package::One_button_return()
{
    Command = Finalize_Command(0x15, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    quint8 SIZE_TX_Buffer =sizeof(TX_Buffer)/sizeof(TX_Buffer[0]);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,SIZE_TX_Buffer);
    serial_protocol->sendMsg(sendM);
    for(int i=0; i<15; i++)
        qDebug() << "\r\n" << sendM.at(i);
        //qDebug() << "\r\n" << TX_Buffer[i];
    qDebug() << "\r\n\r\n";
}

void Package::Cancel_onebuttonreturn()
{
    Command = Finalize_Command(0x16, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}

void Package::Emergency_APlanding()
{
    Command = Finalize_Command(0x21, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}

void Package::Open_APmotor()
{
    Command = Finalize_Command(0x23, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Close_APmotor()
{
    Command = Finalize_Command(0x26, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Test_APmotor()
{
    Command = Finalize_Command(0x27, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Send_PWM()
{
    Command = Finalize_Command(0x30, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Open_APcamera()
{
    Command = Finalize_Command(0x31, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Calibrate_MC()
{
    Command = Finalize_Command(0x32, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Restart_AP()
{
    Command = Finalize_Command(0x41, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}

void Package::Execution_FM()
{
    Command = Finalize_Command(0x45, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Calibrate_APMC()
{
    Command = Finalize_Command(0x4a, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Stop_Calibrate_APMC()
{
    Command = Finalize_Command(0x4b, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}

void Package::Calibrate_Accelerometer_Zero()
{
    Command = Finalize_Command(0x4c, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Hover_AP()
{
    Command = Finalize_Command(0x4d, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Circle_AP()
{
    Command = Finalize_Command(0x4d, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::No_FM_Flight()
{
    Command = Finalize_Command(0x4e, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Savedata_AP()
{
    Command = Finalize_Command(0x52, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Flight_Simulation()
{
    Command = Finalize_Command(0x6f, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Disable_INS_Correction()
{
    Command = Finalize_Command(0x85, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Enable_INS_Correction()
{
    Command = Finalize_Command(0x86, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::MR_FB()
{
    Command = Finalize_Command(0x8c, 0x01, (float)0.310000000238);
    Command_to_TX_Buffer(Command, TX_Buffer);
    quint8 SIZE_TX_Buffer = 15;//sizeof(TX_Buffer)/sizeof(TX_Buffer[0])
    QByteArray sendM=InnitialQByteArry(TX_Buffer,SIZE_TX_Buffer);
    //emit(Serial_Senddata());
    serial_protocol->sendMsg(sendM);
    for(int i=0; i<15; i++)
        qDebug() << "\r\n" << sendM.at(i);
        //qDebug() << "\r\n" << TX_Buffer[i];
    qDebug() << "\r\n\r\n";

}
void Package::Send_FB_Coefficient()
{
    Command = Finalize_Command(0x8d, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Send_APINS_Coefficient()
{
    Command = Finalize_Command(0x8e, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Send_Coordinates_Height()
{
    Command = Finalize_Command(0x50, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_APreturn()
{
    Command = Finalize_Command(0x60, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_APrepeat()
{
    Command = Finalize_Command(0x62, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_EmergencyLanding()
{
    Command = Finalize_Command(0x64, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_Manual_Control()
{
    Command = Finalize_Command(0xb3, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_Automatic_Control()
{
    Command = Finalize_Command(0xb0, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_Semi_automatic_Control()
{
    Command = Finalize_Command(0xb5, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_Open_APmotor()
{
    Command = Finalize_Command(0xc0, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_Close_APmotor()
{
    Command = Finalize_Command(0xc5, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Send_APpump_Speed()
{
    Command = Finalize_Command(0x67, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::CalibrationPWM_1000()
{
    Command = Finalize_Command(0x7b, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::CalibrationPWM_2000()
{
    Command = Finalize_Command(0x7c, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Start_CalibrationPWM()
{
    Command = Finalize_Command(0x7f, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Finish_CalibrationPWM()
{
    Command = Finalize_Command(0x8a, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Joystick_APcontrol()
{
    Command = Finalize_Command(0xaa, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::Activate_joystick()
{
    Command = Finalize_Command(0xbb, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::OSN_BOL()
{
    Command = Finalize_Command(0xcc, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::OSN_MAL()
{
    Command = Finalize_Command(0xdd, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::OSN_Telemetry_package()
{
    Command = Finalize_Command(0xae, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}
void Package::_5S_Timestamp()
{
    Command = Finalize_Command(0xee, 0x00, 0);
    Command_to_TX_Buffer(Command, TX_Buffer);
    QByteArray sendM=InnitialQByteArry(TX_Buffer,15);
    serial_protocol->sendMsg(sendM);
}

QByteArray Package::InnitialQByteArry(quint8 in[],quint8 len)//输入int数组和数组长度，将数组中的值存入QByteArry中
{
    QByteArray byteArry;
    byteArry.resize(len);
    for (int i=0;i<len;i++)
    {
        byteArry[i]=in[i];
    }
    return byteArry;
}
