#ifndef PACKET_H
#define PACKET_H

#include <QByteArray>
#include <QDebug>
#include <QtMath>
#include <QtGlobal>
#include <QTime>
#include <QList>
#include <QSerialPort>
#include <QSerialPortInfo>
#define SETPOINT_THRESHOLD 0.02








// OUT DATA

const static char SETPOINT = 's';
struct SetPoint {
    unsigned short speed;
    short yaw;
    short pitch;
    short roll;
    short checksum;
};

static QByteArray encode_setpoint(SetPoint s) {
    s.checksum = s.speed+s.yaw+s.pitch+s.roll;
    QByteArray bytes;
    bytes.append(SETPOINT).append(SETPOINT)
            .append(reinterpret_cast<const char*>(&s.speed), sizeof(short))
            .append(reinterpret_cast<const char*>(&s.yaw), sizeof(short))
            .append(reinterpret_cast<const char*>(&s.pitch), sizeof(short))
            .append(reinterpret_cast<const char*>(&s.roll), sizeof(short))
            .append(reinterpret_cast<const char*>(&s.checksum), sizeof(short));
    //qDebug() << QString("encode_setpoint : %1 | %2 | %3 | %4").arg(s.speed).arg(s.yaw).arg(s.pitch).arg(s.roll);
    return bytes;
}

static bool is_equal(SetPoint &left, SetPoint &right) {
    return left.speed==right.speed && left.yaw==right.yaw &&
            left.pitch==right.pitch && left.roll==right.roll;
}

static bool compute_variation(SetPoint &left, SetPoint &right) {
    bool speed, yaw, pitch, roll;
    if(left.speed==0) {
        if(right.speed==0)
            speed=false;
        else
            speed=(qAbs(right.speed-left.speed)/right.speed)>SETPOINT_THRESHOLD;
    }
    if(left.yaw==0) {
        if(right.yaw==0)
            yaw=false;
        else
            yaw=(qAbs(right.yaw-left.yaw)/right.yaw)>SETPOINT_THRESHOLD;
    }
    if(left.pitch==0) {
        if(right.pitch==0)
            pitch=false;
        else
            pitch=(qAbs(right.pitch-left.pitch)/right.pitch)>SETPOINT_THRESHOLD;
    }
    if(left.roll==0) {
        if(right.roll==0)
            roll=false;
        else
            roll=(qAbs(right.roll-left.roll)/right.roll)>SETPOINT_THRESHOLD;
    }
    return speed || yaw || pitch || roll;
}





const static char PIDPARAMS = 'p';
struct PIDParams {
    float ykp;
    float yti;
    float ytd;
    float pkp;
    float ptd;
    float pti;
    float rkp;
    float rtd;
    float rti;
    float checksum;
};

static QByteArray encode_pid_params(PIDParams p) {
    p.checksum = p.ykp+p.ytd+p.yti+p.pkp+p.ptd+p.pti+p.rkp+p.rtd+p.rti;
    QByteArray bytes;
    bytes.append(PIDPARAMS).append(PIDPARAMS)
            .append(reinterpret_cast<const char*>(&p.ykp), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.ytd), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.yti), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.pkp), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.ptd), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.pti), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.rkp), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.rtd), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.rti), sizeof(float))
            .append(reinterpret_cast<const char*>(&p.checksum), sizeof(float));
    return bytes;
}





const static char SETTINGS = 't';
struct Settings {
    bool HG;
    bool HD;
    bool BG;
    bool BD;
};

static QByteArray encode_settings(Settings t) {
    char HG = t.HG?'y':'n';
    char HD = t.HD?'y':'n';
    char BG = t.BG?'y':'n';
    char BD = t.BD?'y':'n';
    char checksum = HG+HD+BG+BD;
    QByteArray bytes;
    bytes.append(SETTINGS)
            .append(HG)
            .append(HD)
            .append(BG)
            .append(BD)
            .append(checksum);
    return bytes;
}

enum SETTINGS_SET {
    ALL,
    PITCH_TEST,
    ROLL_TEST,
    STOP
};



static Settings get_settings(SETTINGS_SET s) {
    Settings t;
    switch(s) {
    case ALL:
        t.HG=true;
        t.HD=true;
        t.BG=true;
        t.BD=true;
        return t;
    case PITCH_TEST:
        t.HG=false;
        t.HD=true;
        t.BG=true;
        t.BD=false;
        return t;
    case ROLL_TEST:
        t.HG=true;
        t.HD=false;
        t.BG=false;
        t.BD=true;
        return t;
    case STOP:
        t.HG=false;
        t.HD=false;
        t.BG=false;
        t.BD=false;
        return t;
    }
}



// IN DATA

struct SensorData {
    float alt;
    float yaw;
    float pitch;
    float roll;
};

static SensorData sensor_from_bytes(QByteArray bytes) {
    SensorData s;

    s.yaw = bytes.at(2);
    s.pitch = bytes.at(3);
    s.roll = bytes.at(4);

    return s;

    /*
    static int i;
    i++;

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int test =qrand()%5;

    if(i == 100) i=0;
    s.alt = test;
    s.yaw = i*7-5;
    s.pitch = test;
    s.roll = test*2+3;
*/

    /*
    s.alt = *reinterpret_cast<const float*>(bytes.left(4).data());
    s.yaw = *reinterpret_cast<const float*>(bytes.mid(4,4).data());
    s.pitch = *reinterpret_cast<const float*>(bytes.mid(8,4).data());
    s.roll = *reinterpret_cast<const float*>(bytes.right(4).data());
    //qDebug() << QString("Alt = %1 - Yaw = %2 - Pitch = %3 - Roll = %4").arg(s.alt).arg(s.yaw).arg(s.pitch).arg(s.roll);
    */


}
//地图航点轨迹规划
struct Trajectory_Planning{
    double map_m[30];
    double map_v[30];
    double map_h[30];
    double lnglat_array[30][2];
    double map_p[30];
    double map_pp[30];
    double distance[30];
    quint8 num_points = 0;//the number of map points
};
extern struct Trajectory_Planning MAP_PLANNING;

//定义存储进度条进度数据的结构体
struct Progress_Bar{
    quint8 MAP_POINTS = 0;
};
extern struct Progress_Bar map_Progress_Bar;

enum WAVE{
    INS_YAW = 0,
    INS_ROLL,
    INS_PITCH,
    INS_HEIGHT,
    SET_YAW,
    SET_ROLL,
    SET_PITCH,
    SET_HEIGHT,
    GPS_HEIGHT,
    GPS_SPEED,
    GPS_YAW,
    SPEED_OX,
    SPEED_OY,
    SPEED_OZ
};
extern bool check_flag[3];//信号的复选框
#define num_para 70 //the bunber of parameters on setting interface
extern int time_cancel2start;
#define WAVENUMBER 14//the bunber of waveforms
#endif // PACKET_H
