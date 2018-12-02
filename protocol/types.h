#ifndef TYPES_H_
#define TYPES_H_

#include "stdint.h"
#include <QtGui>

//下面是表1.2中的ID定义
#define Set_PPM                       				 0x10				//设置航点
#define Return_Home                     			 0x15				//一键返航
#define Canel_Return_Home                			 0x16				//取消一键返航
#define Emergency_Landing                      0x21				//紧急降落
#define Release_Parachute                      0x21				//释放降落伞
#define Close_Parachute_Cabin                  0x22				//关闭降落伞舱
#define Open_Motor                             0x23				//启动电机
#define Close_Motor                            0x26				//关闭电机
#define Test_Motor                             0x27				//测试电机（低速）
#define Send_PWM_Duty_Cycle              		   0x30       //发送PWM占空比
#define Open_Camera                            0x31				//启动相机
#define Full_Calibration_MagCompass            0x32 			//全面校准磁罗盘
#define Restart_Autopilot                      0x41				//重启自动驾驶仪
#define Re_Perform_Flight_Mission     		     0x45				//再次执行飞行任务
#define Single_Calibration_MagCompass          0x4a				//单向校准磁罗盘
#define Stop_Calibration_MagCompass            0x4b				//停止校准磁罗盘
#define Calibration_Acc                 			 0x4c				//校准加速度计零点
#define AP_Hover                                  0x4d				//悬停
#define AP_Hover_8_shape                          0x4d				//盘旋
#define None_Flight_Mission	                   0x4e				//无飞行任务飞行
#define Autopilot_Save_Data                    0x52				//自动驾驶仪保存数据
#define Flight_Sim_mode                        0x6f       //飞行模拟模式
#define Disable_Correction_INS                 0x85	 		  //禁用INS校正
#define Enable_Correction_INS                  0x86			  //启用INS校正
#define Send_MR_Feedback_Coefficient           0x8c				//发送多旋翼(MR) 的反馈系数
#define Send_Flight_Feedback_Coefficient       0x8d				//发送飞机的反馈系数
#define Send_INS_Coefficient                   0x8e				//发送INS系数
#define Send_Coordinate_and_Height					   0x50				//发送坐标和高度校正参数
#define Send_Parameters_RotatingDevice_1       0x51				//发送旋转装置的参数
#define Send_Parameters_RotatingDevice_2       0x52				//
#define Send_Parameters_RotatingDevice_3       0x53				//
#define Send_Parameters_RotatingDevice_4       0x54				//
#define Send_Parameters_RotatingDevice_5       0x55				//
#define Joystick_Return                        0x60				//操纵杆：返航
#define Joystick_Repeat_Route                  0x62				//操纵杆：重复路线
#define Joystick_Emergency_Landing             0x64				//操纵杆：紧急降落
#define Joystick_Open_Parachute                0x64				//操纵杆：开启降落伞
#define Joystick_CameraZoom                    0x65				//操纵杆控制:相机变焦
#define Camera_Zoom                            0x66				//相机变焦（拉远镜头）
#define Joystick_Switch_Manual_Mode      			 0xb3				//操纵杆控制：切换到手动控制模式
#define Joystick_Switch_Auto_Mode        			 0xb0				//操纵杆控制：切换到自动控制模式
#define Joystick_Switch_SemiAuto_Mode   			 0xb5				//操纵杆控制：切换到半自动控制模式
#define Joystick_Open_Motor                    0xc0				//操纵杆控制：开启电机
#define Joystick_Close_Motor                   0xc5				//操纵杆控制：关闭电机
#define Send_Pump_Speed                        0x67				//发送泵速（洒水）
#define Calibration_Speed_PWM_1000             0x7b				//校准速度控制器PWM = 1000
#define Calibration_Speed_PWM_2000   					 0x7c				//校准速度控制器PWM = 2000
#define Start_Calibration_PWM             		 0x7f				//开始校准输入PWM
#define Finish_Calibration_PWM         				 0x8a				//完成输入PWM的校准
#define Joystick_Control                       0xaa				//操纵杆控制
#define Open_Joystick                 		     0xbb				//激活操纵杆
#define Telemetry_Package_OSN_BOL              0xcc				//OSN+BOL型遥测包
#define Telemetry_Package_OSN_MAL              0xdd				//OSN+MAL型遥测包
#define Telemetry_Package_OSN                  0xae				//OSN型遥测包
#define Timestape_5S                           0xee				//5s时间戳



//1.单命令包
typedef struct
{
    quint8 StartByte[3];		//起始字节 0x24
    quint8 TX_CMD_ID;		//命令ID，参考表1.2
    quint8 TX_PAY_DATA_ID;		//系数数据ID
    quint8 TX_Length;		//[EndByte]的地址 0x0e
    quint8 Data[8];		//1个系数数据
    quint8 High_CRC;		//校验和高4位
    quint8 Low_CRC;		//校验和低4位
    quint8 EndByte[2];		//结束字节 0x00
}Command_TypeDef;


//2.飞行任务包
typedef struct
{
    quint8 StartByte[3];		//0x24
    quint8 TX_CMD_ID;		//设置航点并发送FM命令 0x10
    quint8 TX_PAY_DATA_ID;		//航点编号
    quint8 TX_Length;		//[EndByte]的地址 0x1f
    quint8 TypeCom;		//FM类型（自行定义）
    quint8 Data[24];		//速度、高度、经纬度等FM数据
    quint8 CRC_TX[2];		//校验和，CRC_TX[1]为高半字节，CRC_TX[0]为低半字节
    quint8 EndByte[2];		//0x00
}FM_TypeDef;


//3.遥测包-基本包
typedef struct
{
    quint8 HeaderByte[3];		//帧头	0x4e 0x41 0x56
    quint8 TX_Length;		//[CRC_TX]的地址	0x83 / 0x4d
    quint8 FlagByte[3];		//服务字节,FlagByte[0]--FlagByte_1
    quint8 MainData[61];		//主要数据
    quint8 LData[8];		//附加数据1
    quint8 DataEndByte;		//有效数据结束符	0x55
    quint8 CRC_TX;		//校验和
    quint8 EndByte[2];		//帧尾	0xd3 0x0a
}Telemetry_BASE_TypeDef;


//4.遥测包-附加包
typedef struct
{
    quint8 HeaderByte[3];		//帧头	0x4e 0x41 0x56
    quint8 TX_Length;		//[CRC_TX]的地址	0x83 / 0x4d
    quint8 FlagByte[3];		//服务字节
    quint8 MainData[61];		//主要数据
    quint8 HData[62];		//附加数据2
    quint8 DataEndByte;		//有效数据结束符	0x55
    quint8 CRC_TX;		//校验和
    quint8 EndByte[2];		//帧尾	0xd3 0x0a
}Telemetry_ADD_TypeDef;


#endif

