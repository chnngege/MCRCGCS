
#ifndef HELPER_H
#define HELPER_H
#include "string.h"
#include "checksum.h"
#include "types.h"
#include <QtGui>
#include "qdebug.h"

#define USART_REC_LEN  		80
#define AP_MCRC  static inline

extern quint8 function_num;		//单命令的编号
extern quint8 PPM_num;		//当前航点的编号
extern quint16 Vel;		//速度
extern quint16 H;		//高度
extern quint16 Lat;		//纬度
extern quint16 Lon;		//经度
extern quint16 Param1;		//附加参数1
extern quint16 Param2;		//附加参数2

struct AP_DATA2GCS_struct {
    quint8 UAV_FlagByte[3];
    quint8 UAV_Active_PPM_num;
    quint8 UAV_FM_Type;
    float UAV_AP_Seconds;
    short UAV_INS_Attitude[3];
    quint16 UAV_GPS_Satellite_num;
    short UAV_Current;
    short UAV_INS_Height;
    short UAV_GPS_Height;
    short UAV_BCS_Vel[3];
    float UAV_Lat;
    float UAV_Lon;
    short UAV_GPS_Yaw;
    quint16 UAV_GPS_Vel;
    short UAV_Attitude[3];
    short UAV_GPS_HDOP;
    short UAV_Voltage;
    short UAV_Height;
    short UAV_Distance;
    short UAV_Vertical_Yaw_Parameter;
    quint16 UAV_Displacement_to_PPM;
    quint16 UAV_Bump_Flag;
    quint8 UAV_LData[8];
};
extern AP_DATA2GCS_struct AP_DATA2GCS ;

extern quint8 send_flagbyte[3];
extern short send_ins_attitude[3];
extern short send_bcs_vel[3];
extern short send_attitude[3];
extern quint8 send_ldata[8] ;


extern Command_TypeDef Command;
extern Command_TypeDef Command_AP;
extern FM_TypeDef FM;
extern FM_TypeDef FM_AP;
extern Telemetry_BASE_TypeDef Telemetry_BASE;
extern Telemetry_BASE_TypeDef Telemetry_BASE_GS;
extern quint8 TX_Buffer[USART_REC_LEN];




/********************0.共用部分*******************/
/**
 * @brief 原始的浮点型数据转为4字节16进制
 **/
AP_MCRC	int Float_to_Hex(float original_data)
{
    int HEX;
  HEX = *((long*)&original_data);
    return HEX;
}


/**
 * @brief 16进制4字节转浮点型
 **/
AP_MCRC	float Hex_to_Float(int HEX)
{
    float original_data;
    memcpy((void *)&original_data, (void *)&HEX, sizeof(HEX));
    return original_data;
}


/**
 * @brief 4种消息帧结构体初始化（清零）
 **/
AP_MCRC	void Init_Command(Command_TypeDef Command)
{
    memset(Command.StartByte, 0, 3);
    Command.TX_CMD_ID = 0x00;
    Command.TX_PAY_DATA_ID = 0x00;
    Command.TX_Length = 0x00;
    memset(Command.Data, 0, 8);
    Command.High_CRC = 0x00;
    Command.Low_CRC = 0x00;
    memset(Command.EndByte, 0, 2);
}

AP_MCRC	void Init_FM(FM_TypeDef FM)
{
    memset(FM.StartByte, 0, 3);
    FM.TX_CMD_ID = 0x00;
    FM.TX_PAY_DATA_ID = 0x00;
    FM.TX_Length = 0x00;
    FM.TypeCom = 0X00;
    memset(FM.Data, 0, 24);
    memset(FM.CRC_TX, 0, 2);
    memset(FM.EndByte, 0, 2);
}

AP_MCRC void Init_Telemetry_BASE(Telemetry_BASE_TypeDef Telemetry_BASE)
{
    memset(Telemetry_BASE.HeaderByte, 0, 3);
    Telemetry_BASE.TX_Length = 0x00;
    memset(Telemetry_BASE.FlagByte, 0, 3);
    memset(Telemetry_BASE.MainData, 0, 61);
    memset(Telemetry_BASE.LData, 0, 8);
    Telemetry_BASE.DataEndByte = 0x00;
    Telemetry_BASE.CRC_TX = 0x00;
    memset(Telemetry_BASE.EndByte, 0, 2);
}

AP_MCRC void Init_Telemetry_ADD(Telemetry_ADD_TypeDef Telemetry_ADD)
{
    memset(Telemetry_ADD.HeaderByte, 0, 3);
    Telemetry_ADD.TX_Length = 0x00;
    memset(Telemetry_ADD.FlagByte, 0, 3);
    memset(Telemetry_ADD.MainData, 0, 61);
    memset(Telemetry_ADD.HData, 0, 8);
    Telemetry_ADD.DataEndByte = 0x00;
    Telemetry_ADD.CRC_TX = 0x00;
    memset(Telemetry_ADD.EndByte, 0, 2);
}



/********************1.单命令包专用*******************/
/**
 * @brief （1）GS编码float系数数据，并存入Command结构体中，会在（2）中调用
 * float型的系数数据转化为16进制是4个字节即8个半字节，利用移位等操作把其当做8个字符存放
 *
 * @param original_data float型原始系数
 * @param a[] 用于保存转化后系数数据的Data数组
 **/
AP_MCRC void Data_Code8(float original_data, quint8 a[])
{
    int data = Float_to_Hex(original_data);		//float型原始系数转化为16进制

    if(data != 0)		//如果是全0，则说明没有系数数据，填充0x30
    {
        //移位，分离出半字节，保留数值
        a[0] = (data >> 28 ) & 0x0000000f;
        a[1] = (data >> 24 ) & 0x0000000f;
        a[2] = (data >> 20 ) & 0x0000000f;
        a[3] = (data >> 16 ) & 0x0000000f;
        a[4] = (data >> 12 ) & 0x0000000f;
        a[5] = (data >> 8 ) & 0x0000000f;
        a[6] = (data >> 4 ) & 0x0000000f;
        a[7] = data & 0x0000000f;
        //加偏移量转化为字符，e.g. 3 → "3"
        for(quint8 i=0; i<8; i++)
        {
            if(a[i] < 10)		//如果是0~9，加48即为字符0~9
                a[i] +=48;
            else if(a[i] > 9)			//如果是A~F，加55即为字符A~F。暂不考虑小写字符
                a[i] +=55;
            else printf("\r\n无效数据\r\n");
        }
    }
    else
        for(quint8 i=0; i<8; i++)
                a[i] = 0x30;
}


/**
 * @brief （2）GS完善待发送的单命令帧，在主函数中调用
 *
 * @param tx_cmd_id 命令ID，对应表1.2
 * @param tx_pay_data_id 附加指令ID，这要对应地面站配置表
 * @param original_data float型系数
 * @return Command 基本完整的单命令帧结构体，除检验位
 **/
AP_MCRC Command_TypeDef Finalize_Command(quint8 tx_cmd_id, quint8 tx_pay_data_id, float original_data)
{
    Command_TypeDef Command;		//定义单命令帧结构体
    Init_Command(Command);			//初始化

    Data_Code8(original_data, Command.Data);		//编码系数数据，并存储

    Command.StartByte[0] = 0x4e;
    Command.StartByte[1] = 0x41;
    Command.StartByte[2] = 0x56;
    Command.TX_CMD_ID = tx_cmd_id;
    Command.TX_Length = 0x11;
    Command.EndByte[0] = 0xd3;
    Command.EndByte[1] = 0x0a;

    //还差两个校验位，不要急，在Buffer中计算，因为数组比结构体处理简单

    return Command;
}


/**
 * @brief （3）GS待发送的单命令帧存入TX_Buffer,等待串口发送，在主函数中调用，且在Finalize_Command之后
 *
 * @param Command 待发送的命令帧
 * @param TX_Buffer[] 缓冲区，全局变量
 **/
AP_MCRC void Command_to_TX_Buffer(Command_TypeDef Command, quint8 TX_Buffer[])
{
    memset(TX_Buffer, 0, USART_REC_LEN);		//向缓冲区存数据前要先清空

    memcpy(TX_Buffer, Command.StartByte, 3);
    TX_Buffer[3] = Command.TX_CMD_ID;
    TX_Buffer[4] = Command.TX_PAY_DATA_ID;
    TX_Buffer[5] = Command.TX_Length;
    for(quint8 i=0; i<8; i++)
        TX_Buffer[i+6] = Command.Data[i];

    quint8 tx_crc = Get_CRC(TX_Buffer, 1);		//计算校验和，1表示Command帧

    //下面回过头来完善Command帧中的两个校验位。注意不用再进行字节拆分转化
    Command.High_CRC = (tx_crc >> 4) & 0x0f;
    Command.Low_CRC = tx_crc & 0x0f;


    //然后再将两个新鲜的校验位存入TX_Buffer中
    TX_Buffer[14] = Command.High_CRC;
    TX_Buffer[15] = Command.Low_CRC;
    memcpy(TX_Buffer+16, Command.EndByte, 2);
}



/**
 * @brief （4）AP解码并返回RX_Buffer中的系数数据，在Decode_Command_AP中调用
 * @param RX_Buffer[] AP端接收数据的缓冲区
 * @return original_data float型系数数据
 **/
AP_MCRC float Data_Decode8(quint8 RX_Buffer[])
{
    //先字符转数字
    for(quint8 i=0; i<8; i++)
        {
            if(RX_Buffer[i+6] < 0x40)						//如果是字符0~9，-48即为0~9
                RX_Buffer[i+6] -=48;
            else if(RX_Buffer[i+6] > 0x40)			//如果是字符A~F，-55即为A~F。不考虑小写字符
                RX_Buffer[i+6] -=55;
        }
    //组合得到32位，先强制转换为int型
    int HEX = (((int)RX_Buffer[6]) << 28) + (((int)RX_Buffer[7]) << 24) + (((int)RX_Buffer[8]) << 20) + \
        (((int)RX_Buffer[9]) << 16) + (((int)RX_Buffer[10]) << 12) + (((int)RX_Buffer[11]) << 8) + \
        (((int)RX_Buffer[12]) << 4) + ((int)RX_Buffer[13]);
    //得到float型数据
    float original_data = Hex_to_Float(HEX);

    return original_data;
}


/**
 * @brief （5）AP将RX_Buffer中的数据存到后缀为AP的结构体中，用于发送遥测包时的参考。在Decode_Command_AP中调用
 *
 * @param Command_AP 数据保存区
 * @param RX_Buffer[]
 * @return Command_AP
 **/
AP_MCRC Command_TypeDef RX_Buffer_to_Command_AP(quint8 RX_Buffer[])
{
    Command_TypeDef Command_AP;
    Init_Command(Command_AP);		//保存数据之前先初始化，清空

    memcpy(Command_AP.StartByte, RX_Buffer, 3);
    Command_AP.TX_CMD_ID = RX_Buffer[3];
    Command_AP.TX_PAY_DATA_ID = RX_Buffer[4];
    Command_AP.TX_Length = RX_Buffer[5];
    for(quint8 i=0; i<8; i++)
        Command_AP.Data[i] = RX_Buffer[i+6];
    Command_AP.High_CRC = RX_Buffer[14];
    Command_AP.Low_CRC = RX_Buffer[15];
    memcpy(Command_AP.EndByte, RX_Buffer+16, 2);

    return Command_AP;
}


/**
 * @brief （6）AP解析RX_Buffer中的单命令帧，在主函数中调用
 *
 * @param RX_Buffer 单命令帧接收缓冲数组
 * @param Command_AP 存放RX_Buffer中的数据
 * @return function_num	对应通信协议表1.2中的单命令编号，可用于控制程序中switch语句执行具体功能
 **/
AP_MCRC quint8 Decode_Command_AP(quint8 RX_Buffer[], Command_TypeDef Command_AP)
{
    quint8 function_num = 0;
    if(RX_Buffer[0] == 0x4e && RX_Buffer[1] == 0x41 && RX_Buffer[2] == 0x56 \
         && RX_Buffer[16] == 0xd3 && RX_Buffer[17] == 0x0a)		//第一重检验：首尾标志符
    {
        quint8 tx_crc = ((RX_Buffer[14]) << 4) + (RX_Buffer[15]);
        printf("\r\n这是接收到的CRC=%x\r\n",tx_crc);
        printf("\r\n计算得到的CRC=%x\r\n",Get_CRC(RX_Buffer, 1));
        if(tx_crc == Get_CRC(RX_Buffer, 1))		//第二重检验：CRC
        {
            //双重检验通过
            //先提取出系数数据，然后switch(TX_CMD_ID)，赋值相应的功能编号
            float tx_data = Data_Decode8(RX_Buffer);

            switch(RX_Buffer[3])
            {
                case 0x10:
                    function_num = 1;
                    printf("\r\n向AP发送航点参数\r\n");
                    break;
                case 0x15:
                    function_num = 2;
                    printf("\r\n一键返航\r\n");
                    break;
                case 0x8c:
                    function_num = 21;
                    printf("\r\n发送MR的反馈系数\r\n");
                    break;
                case 0xcc:
                    function_num = 43;
                    printf("\r\n遥测包使用OSN+BOL\r\n");
                    break;
                case 0xae:
                    function_num = 45;
                    printf("\r\n遥测包使用OSN\r\n");
                    break;
            }
        }
        else
        {
            memset(RX_Buffer, 0, USART_REC_LEN);		//CRC错误，清零
            printf("\r\n CRC验证错误 \r\n");
        }
    }
    else
    {
        memset(RX_Buffer, 0, USART_REC_LEN);		//首或尾错误，清零
        printf("\r\n 首尾验证错误 \r\n");
    }

    memset(RX_Buffer, 0, USART_REC_LEN);	//解析完毕，清空
    return function_num;
}



/********************2.发送FM包专用*******************/
/**
 * @brief （1）GS编码double型系数数据，并存入FM结构体中，在Finalize_FM中调用
 * 区别于float，double是8字节，首先乘10的7次方，可以转化为quint32类型的数据，只用32位就够了（4个字节），再利用移位操作分成4个独立的字节存放（各8位）
 *
 * @param function_data 速度/高度/纬度/经度/附加参数1、2，共6种quint32型系数数据
 * @param a[] 用于保存转化后系数数据的Data数组
 * @param n 系数数据分区，规定速度为0区，高度为1区...取值范围为0~5
 **/
AP_MCRC void Data_Code4(double function_data, quint8 a[], quint8 n)
{
    quint32 function_data_32 = (quint32)(function_data*pow(10,7));  //乘10的7次方，转换为quint32型数据
    a[4*n+0] = (function_data_32 >> 24 ) & 0x000000ff;		//移位后分成4个字节独立保存
    a[4*n+1] = (function_data_32 >> 16 ) & 0x000000ff;
    a[4*n+2] = (function_data_32 >> 8 ) & 0x000000ff;
    a[4*n+3] = function_data_32 & 0x000000ff;
}


/**
 * @brief （2）GS完善待发送的FM帧，在主函数中调用
 *
 * @param tx_pay_data_id 附加指令ID
 * @param typecom FM类型（自行定义）
 * @param 6种quint16系数数据
 * @return FM 飞行任务帧结构体
 **/
AP_MCRC FM_TypeDef Finalize_FM(quint8 tx_pay_data_id, quint8 typecom, double Vel, double H, \
                                                double Lat, double Lon, double Param1, double Param2)
{
    FM_TypeDef FM;		//定义FM帧结构体
    Init_FM(FM);			//初始化

    Data_Code4(Vel, FM.Data, 0);
    Data_Code4(H, FM.Data, 1);
    Data_Code4(Lat, FM.Data, 2);
    Data_Code4(Lon, FM.Data, 3);
    Data_Code4(Param1, FM.Data, 4);
    Data_Code4(Param2, FM.Data, 5);

    FM.StartByte[0] = 0x4e;
    FM.StartByte[1] = 0x41;
    FM.StartByte[2] = 0x56;
    FM.TX_CMD_ID = 0x10;
    FM.TX_Length = 0x22;
    FM.TypeCom = typecom;
    FM.EndByte[0] = 0xd3;
    FM.EndByte[1] = 0x0a;

    //检验位在下面会得到

    return FM;
}


/**
 * @brief （3）GS待发送的FM帧存入TX_Buffer，在主函数中调用，且在Finalize_Command之后
 *
 * @param FM 待发送的命令帧
 * @param TX_Buffer[] 缓冲区，全局变量
 **/
AP_MCRC void FM_to_TX_Buffer(FM_TypeDef FM, quint8 TX_Buffer[])
{
    memset(TX_Buffer, 0, USART_REC_LEN);		//向缓冲区存数据前要先清空

    memcpy(TX_Buffer, FM.StartByte, 3);
    TX_Buffer[3] = FM.TX_CMD_ID;
    TX_Buffer[4] = FM.TX_PAY_DATA_ID;
    TX_Buffer[5] = FM.TX_Length;
    TX_Buffer[6] = FM.TypeCom;
    for(quint8 i=0; i<24; i++)
        TX_Buffer[i+7] = FM.Data[i];

    quint8 tx_crc = Get_CRC(TX_Buffer, 2);

    FM.CRC_TX[1] = (tx_crc >> 4) & 0x0f;
    FM.CRC_TX[0] = tx_crc & 0x0f;

    TX_Buffer[31] = FM.CRC_TX[1];
    TX_Buffer[32] = FM.CRC_TX[0];
    memcpy(TX_Buffer+33, FM.EndByte, 2);
}


/**
 * @brief （4）AP解码系数数据，并返回double型原始数据，在Decode_FM中调用
 * @param RX_Buffer[] AP端接收数据的缓冲区
 * @param n 系数数据分区
 * @return function_data double型系数数据
 **/
AP_MCRC double Data_Decode4(quint8 RX_Buffer[], quint8 n)
{
    quint32 function_data_32 = ((quint32)(RX_Buffer[4*n+7]) << 24) + ((quint32)(RX_Buffer[4*n+8]) << 16) + \
                                               ((quint32)(RX_Buffer[4*n+9]) << 8) + ((quint32)(RX_Buffer[4*n+10]));
    //double function_data = (double)(function_data_32 / (quint32)pow(10,7)) + (double)(function_data_32 % (quint32)pow(10,7));
    double function_data = (double)function_data_32 / pow(10,7);
    return function_data;
}


/**
 * @brief （5）AP将RX_Buffer中的数据存到后缀为AP的结构体中，用于发送遥测包时的参考。在Decode_FM中调用
 *
 * @param FM_AP 数据保存区
 * @param RX_Buffer[]
 * @return FM_AP
 **/
AP_MCRC FM_TypeDef RX_Buffer_to_FM_AP(quint8 RX_Buffer[])
{
    FM_TypeDef FM_AP;
    Init_FM(FM_AP);		//保存数据之前先初始化，清空

    memcpy(FM_AP.StartByte, RX_Buffer, 3);
    FM_AP.TX_CMD_ID = RX_Buffer[3];
    FM_AP.TX_PAY_DATA_ID = RX_Buffer[4];
    FM_AP.TX_Length = RX_Buffer[5];
    FM_AP.TypeCom = RX_Buffer[6];
    for(quint8 i=0; i<24; i++)
        FM_AP.Data[i+7] = RX_Buffer[i+7];
    FM_AP.CRC_TX[1] = RX_Buffer[31];
    FM_AP.CRC_TX[0] = RX_Buffer[32];
    memcpy(FM_AP.EndByte, RX_Buffer+33, 2);

    return FM_AP;
}


/**
 * @brief （6）AP解析RX_Buffer中的飞行任务帧，为对应航点设置速度等参数,在主函数中调用
 *
 * @param PPM_num	返回航点编号，然后switch(编号)，为相应航点设置飞行参数
 * @param RX_Buffer FM帧接收缓冲数组
 * @param 6种系数数据
 * @param FM_AP 存放RX_Buffer中的数据
 **/
AP_MCRC void Decode_FM_AP(quint8 RX_Buffer[], quint8 ppm_num, double vel, double h, double lat, double lon, double param1, double param2, FM_TypeDef FM_AP)
{
    if(RX_Buffer[0] == 0x4e && RX_Buffer[1] == 0x41 && RX_Buffer[2] == 0x56 && RX_Buffer[33] == 0xd3 && RX_Buffer[34] == 0x0a)		//第一重检验：首尾标志符
    {
        quint8 tx_crc = (RX_Buffer[31] << 4) + (RX_Buffer[32]);
        printf("\r\n这是接收到的CRC=%x\r\n",tx_crc);
        printf("\r\n计算得到的CRC=%x\r\n",Get_CRC(RX_Buffer, 2));
        if(tx_crc == Get_CRC(RX_Buffer, 2))		//第二重检验：CRC
        {
            //双重检验通过
            ppm_num = RX_Buffer[4];PPM_num=ppm_num;
            //提取出6种系数数据
            vel = Data_Decode4(RX_Buffer, 0);Vel = vel;
            h = Data_Decode4(RX_Buffer, 1);H=h;
            lat = Data_Decode4(RX_Buffer, 2);Lat=lat;
            lon = Data_Decode4(RX_Buffer, 3);Lon=lon;
            param1 = Data_Decode4(RX_Buffer, 4);Param1=param1;
            param2 = Data_Decode4(RX_Buffer, 5);Param2=param2;

            //得到系数数据后，判断FM命令类型
//			switch(RX_Buffer[4])
//			{
//				case 0x01:
//					printf("\r\n执行我们自定义的功能\r\n");
//					break;
//			}
        }
        else
        {
            memset(RX_Buffer, 0, USART_REC_LEN);		//CRC错误，清零
            printf("\r\n CRC验证错误 \r\n");
        }
    }
    else
    {
        memset(RX_Buffer, 0, USART_REC_LEN);		//首或尾错误，清零
        printf("\r\n 首尾验证错误 \r\n");
    }

    memset(RX_Buffer, 0, USART_REC_LEN);	//解析完毕，清空接收缓冲区
}



/********************3.发送遥测包专用*******************/
/**
 * @brief 该包中要用到的一些参数及说明如下：
 *
 * @param quint8 telemetry_type：遥测包类型-OSN-3。
 * @param quint8 tx_cmd_id：TX_CMD_ID。这里指的是单命令帧中的ID，因此需要调用Command_AP。
 * @param quint8 tx_pay_data_id：TX_PAY_DATA_ID。也是单命令帧中的。
 * @param quint8 active_PPM_num：执行FM的航点的编号。这个应该是控制程序的，实时显示当前正在前往的航点。
 * @param quint8 FM_type；执行的FM类型。这个是与航点对应的。
 * @param float AP_seconds；AP的定时器(s)。来自控制程序。
 * @param short INS_attitude[3]；INS姿态角(degree)。传感器数据。
 * @param quint16 GPS_satellite_num；GPS使用的卫星个数。传感器数据。
 * @param short current；电源的输出电流(A/10)。传感器数据。
 * @param short INS_height：INS的高度(m/10)--暂时不用
 * @param short GPS_height：GPS的高度(m/10)--暂时不用
 * @param short BCS_vel[3]；机体坐标系的三轴速度。传感器数据。
 * @param float Lat；WGS84坐标系下GPS测得的纬度(rad)。传感器数据。
 * @param float Lon；WGS84坐标系下GPS测得的经度(rad)。传感器数据。
 * @param short GPS_yaw：GPS的偏航角(degree/10)。传感器数据。
 * @param quint16 GPS_vel：GPS的速度(m/s/100)。传感器数据。
 * @param short attitude[3]：设定姿态角-yaw(degree/50),pitch(degree/100),roll(degree/100)。
 * @param short GPS_HDOP：GPS水平方向的精度因子。传感器数据。
 * @param short voltage：电压(v/10)。传感器数据。
 * @param short height：设定高度(m/10)。
 * @param short distance：里程计(m/10)。传感器数据。
 * @param short vertical_yaw_parameter：垂直yaw参数(0.1)--暂时不用
 * @param quint16 displacement_to_PPM：UAV到航点的距离(位移)(m)。控制程序计算得到。
 * @param quint16 bump_flag：水泵的开启标志。来自控制程序。
 **/


//float型4字节拆分存放,先存高位
AP_MCRC void Float_to_array(float fdata, quint8 *array)
{
    int data = Float_to_Hex(fdata);
    *array = (data >> 24) & 0x000000ff;
    *(array+1) = (data >> 16) & 0x000000ff;
    *(array+2) = (data >> 8) & 0x000000ff;
    *(array+3) = data & 0x000000ff;
}
//4字节转float，注意先进行数据类型转化
AP_MCRC float array_to_Float(quint8 *array)
{
    int HEX = ((int)(*array)) << 24 + ((int)(*(array+1))) << 16 + ((int)(*(array+2))) << 8 + ((int)(*(array+3)));
    float fdata = Hex_to_Float(HEX);
    return fdata;
}

//short型2字节拆分存放，先存高位
AP_MCRC void Short_to_array(short sdata, quint8 *array)
{
    *array = (sdata >> 8) & 0x00ff;
    *(array+1) = sdata & 0x00ff;
}
//2字节转short
AP_MCRC short array_to_Short(quint8 *array)
{
    short sdata = ((short)(*array) << 8) + ((short)(*(array+1)));
    return sdata;
}

//quint16型2字节拆分存放，先存高位
AP_MCRC void quint16_to_array(quint16 udata, quint8 *array)
{
    *array = (udata >> 8) & 0x00ff;
    *(array+1) = udata & 0x00ff;
}
//2字节转quint16
AP_MCRC quint16 array_to_quint16(quint8 *array)
{
    quint16 udata = ((quint16)(*array) << 8) + ((quint16)(*(array+1)));
    return udata;
}


/**
 * @brief （1）AP完善Telemetry_BASE帧
 * @param 各种各样的参数
 * @return Telemetry_BASE
 **/
AP_MCRC Telemetry_BASE_TypeDef Finalize_Telemetry_BASE(quint8 flagbyte[], Command_TypeDef Command_AP, quint8 active_ppm_num, quint8 FM_type,\
    float AP_seconds, short INS_attitude[], quint16 GPS_satellite_num, short current, short INS_height, short GPS_height, short BCS_vel[],\
        float lat, float lon, short GPS_yaw, quint16 GPS_vel, short attitude[], short GPS_hdop, short voltage, short height, short distance,\
            short vertical_yaw_parameter, quint16 displacement_to_ppm, quint16 bump_flag, quint8 ldata[])
{
    Telemetry_BASE_TypeDef Telemetry_BASE;		//定义结构体
    Init_Telemetry_BASE(Telemetry_BASE);			//初始化

    Telemetry_BASE.HeaderByte[0] = 0x4e;		//N
    Telemetry_BASE.HeaderByte[1] = 0x41;		//A
    Telemetry_BASE.HeaderByte[2] = 0x56;		//V
    Telemetry_BASE.TX_Length = 0x4d;		//遥测帧类型——OSN
    memcpy(Telemetry_BASE.FlagByte, flagbyte, 3);		//3个服务字节的具体值都应该是在各自相关的程序中实时更新的，所以用形参传入

    Telemetry_BASE.MainData[0] = 3;		//遥测包类型OSN
    Telemetry_BASE.MainData[1] = Command_AP.TX_CMD_ID;		//TX_CMD_ID
    Telemetry_BASE.MainData[2] = Command_AP.TX_PAY_DATA_ID;		//TX_PAY_DATA_ID
    Telemetry_BASE.MainData[3] = active_ppm_num;		//执行FM的航点的编号
    Telemetry_BASE.MainData[4] = FM_type;		//执行的FM类型，这个需要自己定义，但是具体作用还很模糊

    //AP的定时器(s)
    Float_to_array(AP_seconds, Telemetry_BASE.MainData+5);

    //INS姿态角(degree)
    Short_to_array(INS_attitude[0], Telemetry_BASE.MainData+9);
    Short_to_array(INS_attitude[1], Telemetry_BASE.MainData+11);
    Short_to_array(INS_attitude[2], Telemetry_BASE.MainData+13);

  //GPS使用的卫星个数
    quint16_to_array(GPS_satellite_num, Telemetry_BASE.MainData+15);

    //电源的输出电流(A/10)
    Short_to_array(current, Telemetry_BASE.MainData+17);

    //INS的高度(m/10)--暂时不用
    Short_to_array(INS_height, Telemetry_BASE.MainData+19);

    //GPS的高度 (m/10)--暂时不用
    Short_to_array(GPS_height, Telemetry_BASE.MainData+21);

    //机体坐标系的三轴速度xyz
    Short_to_array(BCS_vel[0], Telemetry_BASE.MainData+23);
    Short_to_array(BCS_vel[1], (quint8 *)(Telemetry_BASE.MainData+25));
    Short_to_array(BCS_vel[2], Telemetry_BASE.MainData+27);

    //WGS84坐标系下GPS测得的纬度(rad)
    Float_to_array(lat, Telemetry_BASE.MainData+29);

    //WGS84坐标系下GPS测得的经度(rad)
    Float_to_array(lon, Telemetry_BASE.MainData+33);

    //GPS的偏航角(degree/10)
    Short_to_array(GPS_yaw, Telemetry_BASE.MainData+37);

    //GPS的速度(m/s/100)
    quint16_to_array(GPS_vel, Telemetry_BASE.MainData+39);

    //设定yaw (degree/50), pitch (degree/100), roll (degree/100)
    Short_to_array(attitude[0], Telemetry_BASE.MainData+41);
    Short_to_array(attitude[1], Telemetry_BASE.MainData+43);
    Short_to_array(attitude[2], Telemetry_BASE.MainData+45);

    //GPS水平方向的精度因子(HDOP)(1/100)
    Short_to_array(GPS_hdop, Telemetry_BASE.MainData+47);

    //电压 (v/10)
    Short_to_array(voltage, Telemetry_BASE.MainData+49);

    //设定高度 (m/10)
    Short_to_array(height, Telemetry_BASE.MainData+51);

    //里程计 (m/10)
    Short_to_array(distance, Telemetry_BASE.MainData+53);

    //垂直yaw参数 (1/10)
    Short_to_array(vertical_yaw_parameter, Telemetry_BASE.MainData+55);

    //UAV到航点的距离(位移) (m)
    quint16_to_array(displacement_to_ppm, Telemetry_BASE.MainData+57);

    //水泵的开启标志
    quint16_to_array(bump_flag, Telemetry_BASE.MainData+59);

    //附加数据1，先不用
    memcpy(Telemetry_BASE.LData, ldata, 8);
    //Telemetry_BASE.LData

    Telemetry_BASE.DataEndByte = 0x55;		//有效数据结束

    //后面再弄校验和，依旧是因为数组方便
    Telemetry_BASE.EndByte[0] = 0xd3;		//帧结束
    Telemetry_BASE.EndByte[1] = 0x0a;

    return Telemetry_BASE;
}


/**
 * @brief （2）AP待发送的Telemetry_BASE帧存入TX_Buffer
 *
 * @param Telemetry_BASE
 * @param TX_Buffer[]
 **/
AP_MCRC void Telemetry_BASE_to_TX_Buffer(Telemetry_BASE_TypeDef Telemetry_BASE, quint8 TX_Buffer[])
{
    memset(TX_Buffer, 0, USART_REC_LEN);		//向缓冲区存数据前要先清空

    memcpy(TX_Buffer, Telemetry_BASE.HeaderByte, 3);
    TX_Buffer[3] = Telemetry_BASE.TX_Length;
    memcpy(TX_Buffer+4, Telemetry_BASE.FlagByte, 3);
    memcpy(TX_Buffer+7, Telemetry_BASE.MainData, 61);
    memcpy(TX_Buffer+68, Telemetry_BASE.LData, 8);
    TX_Buffer[76] = Telemetry_BASE.DataEndByte;

    Telemetry_BASE.CRC_TX = Get_CRC(TX_Buffer, 3);
    TX_Buffer[77] = Telemetry_BASE.CRC_TX;
    memcpy(TX_Buffer+78, Telemetry_BASE.EndByte, 2);
}


/**
 * @brief （3）GS将RX_Buffer中的数据存到Telemetry_BASE_GS结构体中，留待解析
 *
 * @param Telemetry_BASE_GS 数据保存区
 * @param RX_Buffer[]
 * @return Telemetry_BASE_GS
 **/
AP_MCRC Telemetry_BASE_TypeDef RX_Buffer_to_Telemetry_BASE_GS(quint8 RX_Buffer[])
{
    Telemetry_BASE_TypeDef Telemetry_BASE_GS;
    Init_Telemetry_BASE(Telemetry_BASE_GS);

    memcpy(Telemetry_BASE_GS.HeaderByte, RX_Buffer, 3);
    Telemetry_BASE_GS.TX_Length = RX_Buffer[3];
    memcpy(Telemetry_BASE_GS.FlagByte, RX_Buffer+4, 3);
    memcpy(Telemetry_BASE_GS.MainData, RX_Buffer+7, 61);
    memcpy(Telemetry_BASE_GS.LData, RX_Buffer+68, 8);
    Telemetry_BASE_GS.DataEndByte = RX_Buffer[76];
    Telemetry_BASE_GS.CRC_TX = RX_Buffer[77];
    memcpy(Telemetry_BASE_GS.EndByte, RX_Buffer+78, 2);

    return Telemetry_BASE_GS;
}


/**
 * @brief （4）GS解析RX_Buffer中的遥测帧，把各种参数赋给相应变量
 *
 * @param RX_Buffer 接收缓冲数组
 * @param Telemetry_BASE_GS
 * @param 各种数据
 **/
AP_MCRC void Decode_Telemetry_BASE(quint8 RX_Buffer[], Telemetry_BASE_TypeDef Telemetry_BASE_GS, quint8 UAV_flagbyte[], quint8 UAV_active_ppm_num,\
                                                quint8 UAV_FM_type, float UAV_AP_seconds, short UAV_INS_attitude[], quint16 UAV_GPS_satellite_num, short UAV_current,\
                                                    short UAV_INS_height, short UAV_GPS_height, short UAV_BCS_vel[], float UAV_lat, float UAV_lon,\
                                                        short UAV_GPS_yaw, quint16 UAV_GPS_vel, short UAV_attitude[], short UAV_GPS_hdop, short UAV_voltage,\
                                                            short UAV_height, short UAV_distance, short UAV_vertical_yaw_parameter, quint16 UAV_displacement_to_PPM,\
                                                                quint16 UAV_bump_flag, quint8 UAV_ldata[])
{
    //第一重检验：首尾标志符
    if(Telemetry_BASE_GS.HeaderByte[0] == 0x4e && Telemetry_BASE_GS.HeaderByte[1] == 0x41 \
        && Telemetry_BASE_GS.HeaderByte[2] == 0x56 && Telemetry_BASE_GS.EndByte[0] == 0xd3 \
        && Telemetry_BASE_GS.EndByte[1] == 0x0a)
    {
        if(Telemetry_BASE_GS.DataEndByte == 0x55)		//第二重检验：有效数据结束位
        {
            if(Telemetry_BASE_GS.CRC_TX == Get_CRC(RX_Buffer, 3))		//第三重检验：CRC
            {
                //双重检验通过
                //提取出各种参数并赋给相应变量
                memcpy(UAV_flagbyte, Telemetry_BASE_GS.FlagByte, 3);memcpy(AP_DATA2GCS.UAV_FlagByte,UAV_flagbyte,3);
                UAV_active_ppm_num = Telemetry_BASE_GS.MainData[3];AP_DATA2GCS.UAV_Active_PPM_num=UAV_active_ppm_num;
                UAV_FM_type = Telemetry_BASE_GS.MainData[4];AP_DATA2GCS.UAV_FM_Type=UAV_FM_type;
                UAV_AP_seconds = array_to_Float(Telemetry_BASE_GS.MainData+5);AP_DATA2GCS.UAV_AP_Seconds=UAV_AP_seconds;

                UAV_INS_attitude[0] = array_to_Short(Telemetry_BASE_GS.MainData+9);
                UAV_INS_attitude[1] = array_to_Short(Telemetry_BASE_GS.MainData+11);
                UAV_INS_attitude[2] = array_to_Short(Telemetry_BASE_GS.MainData+13);
                memcpy(AP_DATA2GCS.UAV_INS_Attitude,UAV_INS_attitude,3);

                UAV_GPS_satellite_num = array_to_quint16(Telemetry_BASE_GS.MainData+15);AP_DATA2GCS.UAV_GPS_Satellite_num=UAV_GPS_satellite_num;
                UAV_current = array_to_Short(Telemetry_BASE_GS.MainData+17);AP_DATA2GCS.UAV_Current=UAV_current;
                UAV_INS_height = array_to_Short(Telemetry_BASE_GS.MainData+19);AP_DATA2GCS.UAV_INS_Height=UAV_INS_height;
                UAV_GPS_height = array_to_Short(Telemetry_BASE_GS.MainData+21);AP_DATA2GCS.UAV_GPS_Height=UAV_GPS_height;

                UAV_BCS_vel[0] = array_to_Short(Telemetry_BASE_GS.MainData+23);
                UAV_BCS_vel[1] = array_to_Short(Telemetry_BASE_GS.MainData+25);
                UAV_BCS_vel[2] = array_to_Short(Telemetry_BASE_GS.MainData+27);
                memcpy(AP_DATA2GCS.UAV_BCS_Vel,UAV_BCS_vel,3);

                UAV_lat = array_to_Float(Telemetry_BASE_GS.MainData+29);AP_DATA2GCS.UAV_Lat=UAV_lat;
                UAV_lon = array_to_Float(Telemetry_BASE_GS.MainData+33);AP_DATA2GCS.UAV_Lon=UAV_lon;
                UAV_GPS_yaw = array_to_Short(Telemetry_BASE_GS.MainData+37);AP_DATA2GCS.UAV_GPS_Yaw=UAV_GPS_yaw;
                UAV_GPS_vel = array_to_quint16(Telemetry_BASE_GS.MainData+39);AP_DATA2GCS.UAV_GPS_Vel=UAV_GPS_vel;

                UAV_attitude[0] = array_to_Short(Telemetry_BASE_GS.MainData+41);
                UAV_attitude[1] = array_to_Short(Telemetry_BASE_GS.MainData+43);
                UAV_attitude[2] = array_to_Short(Telemetry_BASE_GS.MainData+45);
                memcpy(AP_DATA2GCS.UAV_Attitude,UAV_attitude,3);

                UAV_GPS_hdop = array_to_Short(Telemetry_BASE_GS.MainData+47);AP_DATA2GCS.UAV_GPS_HDOP=UAV_GPS_hdop;
                UAV_voltage = array_to_Short(Telemetry_BASE_GS.MainData+49);AP_DATA2GCS.UAV_Voltage=UAV_voltage;
                UAV_height = array_to_Short(Telemetry_BASE_GS.MainData+51);AP_DATA2GCS.UAV_Height=UAV_height;
                UAV_distance = array_to_Short(Telemetry_BASE_GS.MainData+53);AP_DATA2GCS.UAV_Distance=UAV_distance;
                UAV_vertical_yaw_parameter = array_to_Short(Telemetry_BASE_GS.MainData+55);AP_DATA2GCS.UAV_Vertical_Yaw_Parameter=UAV_vertical_yaw_parameter;
                UAV_displacement_to_PPM = array_to_quint16(Telemetry_BASE_GS.MainData+57);AP_DATA2GCS.UAV_Displacement_to_PPM=UAV_displacement_to_PPM;
                UAV_bump_flag = array_to_quint16(Telemetry_BASE_GS.MainData+59);AP_DATA2GCS.UAV_Bump_Flag=UAV_bump_flag;
                memcpy(UAV_ldata, Telemetry_BASE_GS.LData, 8);memcpy(AP_DATA2GCS.UAV_LData,UAV_ldata,8);
            }
            else
            {
                memset(RX_Buffer, 0, USART_REC_LEN);		//CRC错误，清零
                printf("\r\n CRC验证错误 \r\n");
            }
        }
        else
        {
            memset(RX_Buffer, 0, USART_REC_LEN);		//CRC错误，清零
            printf("\r\n 有效数据结束位验证错误 \r\n");
        }
    }
    else
    {
        memset(RX_Buffer, 0, USART_REC_LEN);		//首或尾错误，清零
        printf("\r\n 首尾验证错误 \r\n");
    }

    memset(RX_Buffer, 0, USART_REC_LEN);	//解析完毕，清空接收缓冲区
}

#endif

