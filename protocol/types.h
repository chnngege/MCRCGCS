#ifndef TYPES_H_
#define TYPES_H_

#include "stdint.h"
#include <QtGui>

//�����Ǳ�1.2�е�ID����
#define Set_PPM                       				 0x10				//���ú���
#define Return_Home                     			 0x15				//һ������
#define Canel_Return_Home                			 0x16				//ȡ��һ������
#define Emergency_Landing                      0x21				//��������
#define Release_Parachute                      0x21				//�ͷŽ���ɡ
#define Close_Parachute_Cabin                  0x22				//�رս���ɡ��
#define Open_Motor                             0x23				//�������
#define Close_Motor                            0x26				//�رյ��
#define Test_Motor                             0x27				//���Ե�������٣�
#define Send_PWM_Duty_Cycle              		   0x30       //����PWMռ�ձ�
#define Open_Camera                            0x31				//�������
#define Full_Calibration_MagCompass            0x32 			//ȫ��У׼������
#define Restart_Autopilot                      0x41				//�����Զ���ʻ��
#define Re_Perform_Flight_Mission     		     0x45				//�ٴ�ִ�з�������
#define Single_Calibration_MagCompass          0x4a				//����У׼������
#define Stop_Calibration_MagCompass            0x4b				//ֹͣУ׼������
#define Calibration_Acc                 			 0x4c				//У׼���ٶȼ����
#define AP_Hover                                  0x4d				//��ͣ
#define AP_Hover_8_shape                          0x4d				//����
#define None_Flight_Mission	                   0x4e				//�޷����������
#define Autopilot_Save_Data                    0x52				//�Զ���ʻ�Ǳ�������
#define Flight_Sim_mode                        0x6f       //����ģ��ģʽ
#define Disable_Correction_INS                 0x85	 		  //����INSУ��
#define Enable_Correction_INS                  0x86			  //����INSУ��
#define Send_MR_Feedback_Coefficient           0x8c				//���Ͷ�����(MR) �ķ���ϵ��
#define Send_Flight_Feedback_Coefficient       0x8d				//���ͷɻ��ķ���ϵ��
#define Send_INS_Coefficient                   0x8e				//����INSϵ��
#define Send_Coordinate_and_Height					   0x50				//��������͸߶�У������
#define Send_Parameters_RotatingDevice_1       0x51				//������תװ�õĲ���
#define Send_Parameters_RotatingDevice_2       0x52				//
#define Send_Parameters_RotatingDevice_3       0x53				//
#define Send_Parameters_RotatingDevice_4       0x54				//
#define Send_Parameters_RotatingDevice_5       0x55				//
#define Joystick_Return                        0x60				//���ݸˣ�����
#define Joystick_Repeat_Route                  0x62				//���ݸˣ��ظ�·��
#define Joystick_Emergency_Landing             0x64				//���ݸˣ���������
#define Joystick_Open_Parachute                0x64				//���ݸˣ���������ɡ
#define Joystick_CameraZoom                    0x65				//���ݸ˿���:����佹
#define Camera_Zoom                            0x66				//����佹����Զ��ͷ��
#define Joystick_Switch_Manual_Mode      			 0xb3				//���ݸ˿��ƣ��л����ֶ�����ģʽ
#define Joystick_Switch_Auto_Mode        			 0xb0				//���ݸ˿��ƣ��л����Զ�����ģʽ
#define Joystick_Switch_SemiAuto_Mode   			 0xb5				//���ݸ˿��ƣ��л������Զ�����ģʽ
#define Joystick_Open_Motor                    0xc0				//���ݸ˿��ƣ��������
#define Joystick_Close_Motor                   0xc5				//���ݸ˿��ƣ��رյ��
#define Send_Pump_Speed                        0x67				//���ͱ��٣���ˮ��
#define Calibration_Speed_PWM_1000             0x7b				//У׼�ٶȿ�����PWM = 1000
#define Calibration_Speed_PWM_2000   					 0x7c				//У׼�ٶȿ�����PWM = 2000
#define Start_Calibration_PWM             		 0x7f				//��ʼУ׼����PWM
#define Finish_Calibration_PWM         				 0x8a				//�������PWM��У׼
#define Joystick_Control                       0xaa				//���ݸ˿���
#define Open_Joystick                 		     0xbb				//������ݸ�
#define Telemetry_Package_OSN_BOL              0xcc				//OSN+BOL��ң���
#define Telemetry_Package_OSN_MAL              0xdd				//OSN+MAL��ң���
#define Telemetry_Package_OSN                  0xae				//OSN��ң���
#define Timestape_5S                           0xee				//5sʱ���



//1.�������
typedef struct
{
    quint8 StartByte[3];		//��ʼ�ֽ� 0x24
    quint8 TX_CMD_ID;		//����ID���ο���1.2
    quint8 TX_PAY_DATA_ID;		//ϵ������ID
    quint8 TX_Length;		//[EndByte]�ĵ�ַ 0x0e
    quint8 Data[8];		//1��ϵ������
    quint8 High_CRC;		//У��͸�4λ
    quint8 Low_CRC;		//У��͵�4λ
    quint8 EndByte[2];		//�����ֽ� 0x00
}Command_TypeDef;


//2.���������
typedef struct
{
    quint8 StartByte[3];		//0x24
    quint8 TX_CMD_ID;		//���ú��㲢����FM���� 0x10
    quint8 TX_PAY_DATA_ID;		//������
    quint8 TX_Length;		//[EndByte]�ĵ�ַ 0x1f
    quint8 TypeCom;		//FM���ͣ����ж��壩
    quint8 Data[24];		//�ٶȡ��߶ȡ���γ�ȵ�FM����
    quint8 CRC_TX[2];		//У��ͣ�CRC_TX[1]Ϊ�߰��ֽڣ�CRC_TX[0]Ϊ�Ͱ��ֽ�
    quint8 EndByte[2];		//0x00
}FM_TypeDef;


//3.ң���-������
typedef struct
{
    quint8 HeaderByte[3];		//֡ͷ	0x4e 0x41 0x56
    quint8 TX_Length;		//[CRC_TX]�ĵ�ַ	0x83 / 0x4d
    quint8 FlagByte[3];		//�����ֽ�,FlagByte[0]--FlagByte_1
    quint8 MainData[61];		//��Ҫ����
    quint8 LData[8];		//��������1
    quint8 DataEndByte;		//��Ч���ݽ�����	0x55
    quint8 CRC_TX;		//У���
    quint8 EndByte[2];		//֡β	0xd3 0x0a
}Telemetry_BASE_TypeDef;


//4.ң���-���Ӱ�
typedef struct
{
    quint8 HeaderByte[3];		//֡ͷ	0x4e 0x41 0x56
    quint8 TX_Length;		//[CRC_TX]�ĵ�ַ	0x83 / 0x4d
    quint8 FlagByte[3];		//�����ֽ�
    quint8 MainData[61];		//��Ҫ����
    quint8 HData[62];		//��������2
    quint8 DataEndByte;		//��Ч���ݽ�����	0x55
    quint8 CRC_TX;		//У���
    quint8 EndByte[2];		//֡β	0xd3 0x0a
}Telemetry_ADD_TypeDef;


#endif

