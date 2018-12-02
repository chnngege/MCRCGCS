#ifndef PACKAGE_H
#define PACKAGE_H
#include <QObject>
#include "serial/serialsetting.h"
#include "map/document.h"
#include "map/mappoints.h"
#include "serial/packet.h"

class Package  : public QObject{
    Q_OBJECT

public:
    explicit Package(QObject *parent = nullptr);
    QByteArray InnitialQByteArry(quint8 in[],quint8 len);
    void AP_Trajectory_Planning();
    void FM_Task();
    void One_button_return();
    void Cancel_onebuttonreturn();
    void Emergency_APlanding();
    void Open_APmotor();
    void Close_APmotor();
    void Test_APmotor();
    void Send_PWM() ;
    void Open_APcamera();
    void Calibrate_MC();
    void Restart_AP();
    void Calibrate_APMC();
    void Execution_FM();
    void Stop_Calibrate_APMC();
    void Calibrate_Accelerometer_Zero();
    void Hover_AP();
    void Circle_AP();
    void No_FM_Flight();
    void Savedata_AP();
    void Flight_Simulation();
    void Disable_INS_Correction();
    void Enable_INS_Correction();
    void MR_FB();
    void Send_FB_Coefficient();
    void Send_APINS_Coefficient();
    void Send_Coordinates_Height();
    void Joystick_APreturn();
    void Joystick_APrepeat();
    void Joystick_EmergencyLanding();
    void Joystick_Manual_Control();
    void Joystick_Automatic_Control();
    void Joystick_Semi_automatic_Control();
    void Joystick_Open_APmotor();
    void Joystick_Close_APmotor();
    void Send_APpump_Speed();
    void CalibrationPWM_1000();
    void CalibrationPWM_2000();
    void Start_CalibrationPWM();
    void Finish_CalibrationPWM();
    void Joystick_APcontrol();
    void Activate_joystick();
    void OSN_BOL();
    void OSN_MAL();
    void OSN_Telemetry_package();
    void _5S_Timestamp();
    Serialsetting *serial_protocol;

signals:
    void Serial_Senddata();
    void map_progressbar();

private:
    quint8 current_waypoint_number = 0;//当前发送的航点的编号
    //地图新设置了几个航点就执行几次飞行任务函数，该变量用于指示当前发送的航点的编号
};




#endif // PACKAGE_H
