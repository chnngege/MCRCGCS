
#ifndef HELPER_H
#define HELPER_H
#include "string.h"
#include "checksum.h"
#include "types.h"
#include <QtGui>
#include "qdebug.h"

#define USART_REC_LEN  		80
#define AP_MCRC  static inline

extern quint8 function_num;		//������ı��
extern quint8 PPM_num;		//��ǰ����ı��
extern quint16 Vel;		//�ٶ�
extern quint16 H;		//�߶�
extern quint16 Lat;		//γ��
extern quint16 Lon;		//����
extern quint16 Param1;		//���Ӳ���1
extern quint16 Param2;		//���Ӳ���2

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




/********************0.���ò���*******************/
/**
 * @brief ԭʼ�ĸ���������תΪ4�ֽ�16����
 **/
AP_MCRC	int Float_to_Hex(float original_data)
{
    int HEX;
  HEX = *((long*)&original_data);
    return HEX;
}


/**
 * @brief 16����4�ֽ�ת������
 **/
AP_MCRC	float Hex_to_Float(int HEX)
{
    float original_data;
    memcpy((void *)&original_data, (void *)&HEX, sizeof(HEX));
    return original_data;
}


/**
 * @brief 4����Ϣ֡�ṹ���ʼ�������㣩
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



/********************1.�������ר��*******************/
/**
 * @brief ��1��GS����floatϵ�����ݣ�������Command�ṹ���У����ڣ�2���е���
 * float�͵�ϵ������ת��Ϊ16������4���ֽڼ�8�����ֽڣ�������λ�Ȳ������䵱��8���ַ����
 *
 * @param original_data float��ԭʼϵ��
 * @param a[] ���ڱ���ת����ϵ�����ݵ�Data����
 **/
AP_MCRC void Data_Code8(float original_data, quint8 a[])
{
    int data = Float_to_Hex(original_data);		//float��ԭʼϵ��ת��Ϊ16����

    if(data != 0)		//�����ȫ0����˵��û��ϵ�����ݣ����0x30
    {
        //��λ����������ֽڣ�������ֵ
        a[0] = (data >> 28 ) & 0x0000000f;
        a[1] = (data >> 24 ) & 0x0000000f;
        a[2] = (data >> 20 ) & 0x0000000f;
        a[3] = (data >> 16 ) & 0x0000000f;
        a[4] = (data >> 12 ) & 0x0000000f;
        a[5] = (data >> 8 ) & 0x0000000f;
        a[6] = (data >> 4 ) & 0x0000000f;
        a[7] = data & 0x0000000f;
        //��ƫ����ת��Ϊ�ַ���e.g. 3 �� "3"
        for(quint8 i=0; i<8; i++)
        {
            if(a[i] < 10)		//�����0~9����48��Ϊ�ַ�0~9
                a[i] +=48;
            else if(a[i] > 9)			//�����A~F����55��Ϊ�ַ�A~F���ݲ�����Сд�ַ�
                a[i] +=55;
            else printf("\r\n��Ч����\r\n");
        }
    }
    else
        for(quint8 i=0; i<8; i++)
                a[i] = 0x30;
}


/**
 * @brief ��2��GS���ƴ����͵ĵ�����֡�����������е���
 *
 * @param tx_cmd_id ����ID����Ӧ��1.2
 * @param tx_pay_data_id ����ָ��ID����Ҫ��Ӧ����վ���ñ�
 * @param original_data float��ϵ��
 * @return Command ���������ĵ�����֡�ṹ�壬������λ
 **/
AP_MCRC Command_TypeDef Finalize_Command(quint8 tx_cmd_id, quint8 tx_pay_data_id, float original_data)
{
    Command_TypeDef Command;		//���嵥����֡�ṹ��
    Init_Command(Command);			//��ʼ��

    Data_Code8(original_data, Command.Data);		//����ϵ�����ݣ����洢

    Command.StartByte[0] = 0x4e;
    Command.StartByte[1] = 0x41;
    Command.StartByte[2] = 0x56;
    Command.TX_CMD_ID = tx_cmd_id;
    Command.TX_Length = 0x11;
    Command.EndByte[0] = 0xd3;
    Command.EndByte[1] = 0x0a;

    //��������У��λ����Ҫ������Buffer�м��㣬��Ϊ����Ƚṹ�崦���

    return Command;
}


/**
 * @brief ��3��GS�����͵ĵ�����֡����TX_Buffer,�ȴ����ڷ��ͣ����������е��ã�����Finalize_Command֮��
 *
 * @param Command �����͵�����֡
 * @param TX_Buffer[] ��������ȫ�ֱ���
 **/
AP_MCRC void Command_to_TX_Buffer(Command_TypeDef Command, quint8 TX_Buffer[])
{
    memset(TX_Buffer, 0, USART_REC_LEN);		//�򻺳���������ǰҪ�����

    memcpy(TX_Buffer, Command.StartByte, 3);
    TX_Buffer[3] = Command.TX_CMD_ID;
    TX_Buffer[4] = Command.TX_PAY_DATA_ID;
    TX_Buffer[5] = Command.TX_Length;
    for(quint8 i=0; i<8; i++)
        TX_Buffer[i+6] = Command.Data[i];

    quint8 tx_crc = Get_CRC(TX_Buffer, 1);		//����У��ͣ�1��ʾCommand֡

    //����ع�ͷ������Command֡�е�����У��λ��ע�ⲻ���ٽ����ֽڲ��ת��
    Command.High_CRC = (tx_crc >> 4) & 0x0f;
    Command.Low_CRC = tx_crc & 0x0f;


    //Ȼ���ٽ��������ʵ�У��λ����TX_Buffer��
    TX_Buffer[14] = Command.High_CRC;
    TX_Buffer[15] = Command.Low_CRC;
    memcpy(TX_Buffer+16, Command.EndByte, 2);
}



/**
 * @brief ��4��AP���벢����RX_Buffer�е�ϵ�����ݣ���Decode_Command_AP�е���
 * @param RX_Buffer[] AP�˽������ݵĻ�����
 * @return original_data float��ϵ������
 **/
AP_MCRC float Data_Decode8(quint8 RX_Buffer[])
{
    //���ַ�ת����
    for(quint8 i=0; i<8; i++)
        {
            if(RX_Buffer[i+6] < 0x40)						//������ַ�0~9��-48��Ϊ0~9
                RX_Buffer[i+6] -=48;
            else if(RX_Buffer[i+6] > 0x40)			//������ַ�A~F��-55��ΪA~F��������Сд�ַ�
                RX_Buffer[i+6] -=55;
        }
    //��ϵõ�32λ����ǿ��ת��Ϊint��
    int HEX = (((int)RX_Buffer[6]) << 28) + (((int)RX_Buffer[7]) << 24) + (((int)RX_Buffer[8]) << 20) + \
        (((int)RX_Buffer[9]) << 16) + (((int)RX_Buffer[10]) << 12) + (((int)RX_Buffer[11]) << 8) + \
        (((int)RX_Buffer[12]) << 4) + ((int)RX_Buffer[13]);
    //�õ�float������
    float original_data = Hex_to_Float(HEX);

    return original_data;
}


/**
 * @brief ��5��AP��RX_Buffer�е����ݴ浽��׺ΪAP�Ľṹ���У����ڷ���ң���ʱ�Ĳο�����Decode_Command_AP�е���
 *
 * @param Command_AP ���ݱ�����
 * @param RX_Buffer[]
 * @return Command_AP
 **/
AP_MCRC Command_TypeDef RX_Buffer_to_Command_AP(quint8 RX_Buffer[])
{
    Command_TypeDef Command_AP;
    Init_Command(Command_AP);		//��������֮ǰ�ȳ�ʼ�������

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
 * @brief ��6��AP����RX_Buffer�еĵ�����֡�����������е���
 *
 * @param RX_Buffer ������֡���ջ�������
 * @param Command_AP ���RX_Buffer�е�����
 * @return function_num	��Ӧͨ��Э���1.2�еĵ������ţ������ڿ��Ƴ�����switch���ִ�о��幦��
 **/
AP_MCRC quint8 Decode_Command_AP(quint8 RX_Buffer[], Command_TypeDef Command_AP)
{
    quint8 function_num = 0;
    if(RX_Buffer[0] == 0x4e && RX_Buffer[1] == 0x41 && RX_Buffer[2] == 0x56 \
         && RX_Buffer[16] == 0xd3 && RX_Buffer[17] == 0x0a)		//��һ�ؼ��飺��β��־��
    {
        quint8 tx_crc = ((RX_Buffer[14]) << 4) + (RX_Buffer[15]);
        printf("\r\n���ǽ��յ���CRC=%x\r\n",tx_crc);
        printf("\r\n����õ���CRC=%x\r\n",Get_CRC(RX_Buffer, 1));
        if(tx_crc == Get_CRC(RX_Buffer, 1))		//�ڶ��ؼ��飺CRC
        {
            //˫�ؼ���ͨ��
            //����ȡ��ϵ�����ݣ�Ȼ��switch(TX_CMD_ID)����ֵ��Ӧ�Ĺ��ܱ��
            float tx_data = Data_Decode8(RX_Buffer);

            switch(RX_Buffer[3])
            {
                case 0x10:
                    function_num = 1;
                    printf("\r\n��AP���ͺ������\r\n");
                    break;
                case 0x15:
                    function_num = 2;
                    printf("\r\nһ������\r\n");
                    break;
                case 0x8c:
                    function_num = 21;
                    printf("\r\n����MR�ķ���ϵ��\r\n");
                    break;
                case 0xcc:
                    function_num = 43;
                    printf("\r\nң���ʹ��OSN+BOL\r\n");
                    break;
                case 0xae:
                    function_num = 45;
                    printf("\r\nң���ʹ��OSN\r\n");
                    break;
            }
        }
        else
        {
            memset(RX_Buffer, 0, USART_REC_LEN);		//CRC��������
            printf("\r\n CRC��֤���� \r\n");
        }
    }
    else
    {
        memset(RX_Buffer, 0, USART_REC_LEN);		//�׻�β��������
        printf("\r\n ��β��֤���� \r\n");
    }

    memset(RX_Buffer, 0, USART_REC_LEN);	//������ϣ����
    return function_num;
}



/********************2.����FM��ר��*******************/
/**
 * @brief ��1��GS����double��ϵ�����ݣ�������FM�ṹ���У���Finalize_FM�е���
 * ������float��double��8�ֽڣ����ȳ�10��7�η�������ת��Ϊquint32���͵����ݣ�ֻ��32λ�͹��ˣ�4���ֽڣ�����������λ�����ֳ�4���������ֽڴ�ţ���8λ��
 *
 * @param function_data �ٶ�/�߶�/γ��/����/���Ӳ���1��2����6��quint32��ϵ������
 * @param a[] ���ڱ���ת����ϵ�����ݵ�Data����
 * @param n ϵ�����ݷ������涨�ٶ�Ϊ0�����߶�Ϊ1��...ȡֵ��ΧΪ0~5
 **/
AP_MCRC void Data_Code4(double function_data, quint8 a[], quint8 n)
{
    quint32 function_data_32 = (quint32)(function_data*pow(10,7));  //��10��7�η���ת��Ϊquint32������
    a[4*n+0] = (function_data_32 >> 24 ) & 0x000000ff;		//��λ��ֳ�4���ֽڶ�������
    a[4*n+1] = (function_data_32 >> 16 ) & 0x000000ff;
    a[4*n+2] = (function_data_32 >> 8 ) & 0x000000ff;
    a[4*n+3] = function_data_32 & 0x000000ff;
}


/**
 * @brief ��2��GS���ƴ����͵�FM֡�����������е���
 *
 * @param tx_pay_data_id ����ָ��ID
 * @param typecom FM���ͣ����ж��壩
 * @param 6��quint16ϵ������
 * @return FM ��������֡�ṹ��
 **/
AP_MCRC FM_TypeDef Finalize_FM(quint8 tx_pay_data_id, quint8 typecom, double Vel, double H, \
                                                double Lat, double Lon, double Param1, double Param2)
{
    FM_TypeDef FM;		//����FM֡�ṹ��
    Init_FM(FM);			//��ʼ��

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

    //����λ�������õ�

    return FM;
}


/**
 * @brief ��3��GS�����͵�FM֡����TX_Buffer�����������е��ã�����Finalize_Command֮��
 *
 * @param FM �����͵�����֡
 * @param TX_Buffer[] ��������ȫ�ֱ���
 **/
AP_MCRC void FM_to_TX_Buffer(FM_TypeDef FM, quint8 TX_Buffer[])
{
    memset(TX_Buffer, 0, USART_REC_LEN);		//�򻺳���������ǰҪ�����

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
 * @brief ��4��AP����ϵ�����ݣ�������double��ԭʼ���ݣ���Decode_FM�е���
 * @param RX_Buffer[] AP�˽������ݵĻ�����
 * @param n ϵ�����ݷ���
 * @return function_data double��ϵ������
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
 * @brief ��5��AP��RX_Buffer�е����ݴ浽��׺ΪAP�Ľṹ���У����ڷ���ң���ʱ�Ĳο�����Decode_FM�е���
 *
 * @param FM_AP ���ݱ�����
 * @param RX_Buffer[]
 * @return FM_AP
 **/
AP_MCRC FM_TypeDef RX_Buffer_to_FM_AP(quint8 RX_Buffer[])
{
    FM_TypeDef FM_AP;
    Init_FM(FM_AP);		//��������֮ǰ�ȳ�ʼ�������

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
 * @brief ��6��AP����RX_Buffer�еķ�������֡��Ϊ��Ӧ���������ٶȵȲ���,���������е���
 *
 * @param PPM_num	���غ����ţ�Ȼ��switch(���)��Ϊ��Ӧ�������÷��в���
 * @param RX_Buffer FM֡���ջ�������
 * @param 6��ϵ������
 * @param FM_AP ���RX_Buffer�е�����
 **/
AP_MCRC void Decode_FM_AP(quint8 RX_Buffer[], quint8 ppm_num, double vel, double h, double lat, double lon, double param1, double param2, FM_TypeDef FM_AP)
{
    if(RX_Buffer[0] == 0x4e && RX_Buffer[1] == 0x41 && RX_Buffer[2] == 0x56 && RX_Buffer[33] == 0xd3 && RX_Buffer[34] == 0x0a)		//��һ�ؼ��飺��β��־��
    {
        quint8 tx_crc = (RX_Buffer[31] << 4) + (RX_Buffer[32]);
        printf("\r\n���ǽ��յ���CRC=%x\r\n",tx_crc);
        printf("\r\n����õ���CRC=%x\r\n",Get_CRC(RX_Buffer, 2));
        if(tx_crc == Get_CRC(RX_Buffer, 2))		//�ڶ��ؼ��飺CRC
        {
            //˫�ؼ���ͨ��
            ppm_num = RX_Buffer[4];PPM_num=ppm_num;
            //��ȡ��6��ϵ������
            vel = Data_Decode4(RX_Buffer, 0);Vel = vel;
            h = Data_Decode4(RX_Buffer, 1);H=h;
            lat = Data_Decode4(RX_Buffer, 2);Lat=lat;
            lon = Data_Decode4(RX_Buffer, 3);Lon=lon;
            param1 = Data_Decode4(RX_Buffer, 4);Param1=param1;
            param2 = Data_Decode4(RX_Buffer, 5);Param2=param2;

            //�õ�ϵ�����ݺ��ж�FM��������
//			switch(RX_Buffer[4])
//			{
//				case 0x01:
//					printf("\r\nִ�������Զ���Ĺ���\r\n");
//					break;
//			}
        }
        else
        {
            memset(RX_Buffer, 0, USART_REC_LEN);		//CRC��������
            printf("\r\n CRC��֤���� \r\n");
        }
    }
    else
    {
        memset(RX_Buffer, 0, USART_REC_LEN);		//�׻�β��������
        printf("\r\n ��β��֤���� \r\n");
    }

    memset(RX_Buffer, 0, USART_REC_LEN);	//������ϣ���ս��ջ�����
}



/********************3.����ң���ר��*******************/
/**
 * @brief �ð���Ҫ�õ���һЩ������˵�����£�
 *
 * @param quint8 telemetry_type��ң�������-OSN-3��
 * @param quint8 tx_cmd_id��TX_CMD_ID������ָ���ǵ�����֡�е�ID�������Ҫ����Command_AP��
 * @param quint8 tx_pay_data_id��TX_PAY_DATA_ID��Ҳ�ǵ�����֡�еġ�
 * @param quint8 active_PPM_num��ִ��FM�ĺ���ı�š����Ӧ���ǿ��Ƴ���ģ�ʵʱ��ʾ��ǰ����ǰ���ĺ��㡣
 * @param quint8 FM_type��ִ�е�FM���͡�������뺽���Ӧ�ġ�
 * @param float AP_seconds��AP�Ķ�ʱ��(s)�����Կ��Ƴ���
 * @param short INS_attitude[3]��INS��̬��(degree)�����������ݡ�
 * @param quint16 GPS_satellite_num��GPSʹ�õ����Ǹ��������������ݡ�
 * @param short current����Դ���������(A/10)�����������ݡ�
 * @param short INS_height��INS�ĸ߶�(m/10)--��ʱ����
 * @param short GPS_height��GPS�ĸ߶�(m/10)--��ʱ����
 * @param short BCS_vel[3]����������ϵ�������ٶȡ����������ݡ�
 * @param float Lat��WGS84����ϵ��GPS��õ�γ��(rad)�����������ݡ�
 * @param float Lon��WGS84����ϵ��GPS��õľ���(rad)�����������ݡ�
 * @param short GPS_yaw��GPS��ƫ����(degree/10)�����������ݡ�
 * @param quint16 GPS_vel��GPS���ٶ�(m/s/100)�����������ݡ�
 * @param short attitude[3]���趨��̬��-yaw(degree/50),pitch(degree/100),roll(degree/100)��
 * @param short GPS_HDOP��GPSˮƽ����ľ������ӡ����������ݡ�
 * @param short voltage����ѹ(v/10)�����������ݡ�
 * @param short height���趨�߶�(m/10)��
 * @param short distance����̼�(m/10)�����������ݡ�
 * @param short vertical_yaw_parameter����ֱyaw����(0.1)--��ʱ����
 * @param quint16 displacement_to_PPM��UAV������ľ���(λ��)(m)�����Ƴ������õ���
 * @param quint16 bump_flag��ˮ�õĿ�����־�����Կ��Ƴ���
 **/


//float��4�ֽڲ�ִ��,�ȴ��λ
AP_MCRC void Float_to_array(float fdata, quint8 *array)
{
    int data = Float_to_Hex(fdata);
    *array = (data >> 24) & 0x000000ff;
    *(array+1) = (data >> 16) & 0x000000ff;
    *(array+2) = (data >> 8) & 0x000000ff;
    *(array+3) = data & 0x000000ff;
}
//4�ֽ�תfloat��ע���Ƚ�����������ת��
AP_MCRC float array_to_Float(quint8 *array)
{
    int HEX = ((int)(*array)) << 24 + ((int)(*(array+1))) << 16 + ((int)(*(array+2))) << 8 + ((int)(*(array+3)));
    float fdata = Hex_to_Float(HEX);
    return fdata;
}

//short��2�ֽڲ�ִ�ţ��ȴ��λ
AP_MCRC void Short_to_array(short sdata, quint8 *array)
{
    *array = (sdata >> 8) & 0x00ff;
    *(array+1) = sdata & 0x00ff;
}
//2�ֽ�תshort
AP_MCRC short array_to_Short(quint8 *array)
{
    short sdata = ((short)(*array) << 8) + ((short)(*(array+1)));
    return sdata;
}

//quint16��2�ֽڲ�ִ�ţ��ȴ��λ
AP_MCRC void quint16_to_array(quint16 udata, quint8 *array)
{
    *array = (udata >> 8) & 0x00ff;
    *(array+1) = udata & 0x00ff;
}
//2�ֽ�תquint16
AP_MCRC quint16 array_to_quint16(quint8 *array)
{
    quint16 udata = ((quint16)(*array) << 8) + ((quint16)(*(array+1)));
    return udata;
}


/**
 * @brief ��1��AP����Telemetry_BASE֡
 * @param ���ָ����Ĳ���
 * @return Telemetry_BASE
 **/
AP_MCRC Telemetry_BASE_TypeDef Finalize_Telemetry_BASE(quint8 flagbyte[], Command_TypeDef Command_AP, quint8 active_ppm_num, quint8 FM_type,\
    float AP_seconds, short INS_attitude[], quint16 GPS_satellite_num, short current, short INS_height, short GPS_height, short BCS_vel[],\
        float lat, float lon, short GPS_yaw, quint16 GPS_vel, short attitude[], short GPS_hdop, short voltage, short height, short distance,\
            short vertical_yaw_parameter, quint16 displacement_to_ppm, quint16 bump_flag, quint8 ldata[])
{
    Telemetry_BASE_TypeDef Telemetry_BASE;		//����ṹ��
    Init_Telemetry_BASE(Telemetry_BASE);			//��ʼ��

    Telemetry_BASE.HeaderByte[0] = 0x4e;		//N
    Telemetry_BASE.HeaderByte[1] = 0x41;		//A
    Telemetry_BASE.HeaderByte[2] = 0x56;		//V
    Telemetry_BASE.TX_Length = 0x4d;		//ң��֡���͡���OSN
    memcpy(Telemetry_BASE.FlagByte, flagbyte, 3);		//3�������ֽڵľ���ֵ��Ӧ�����ڸ�����صĳ�����ʵʱ���µģ��������βδ���

    Telemetry_BASE.MainData[0] = 3;		//ң�������OSN
    Telemetry_BASE.MainData[1] = Command_AP.TX_CMD_ID;		//TX_CMD_ID
    Telemetry_BASE.MainData[2] = Command_AP.TX_PAY_DATA_ID;		//TX_PAY_DATA_ID
    Telemetry_BASE.MainData[3] = active_ppm_num;		//ִ��FM�ĺ���ı��
    Telemetry_BASE.MainData[4] = FM_type;		//ִ�е�FM���ͣ������Ҫ�Լ����壬���Ǿ������û���ģ��

    //AP�Ķ�ʱ��(s)
    Float_to_array(AP_seconds, Telemetry_BASE.MainData+5);

    //INS��̬��(degree)
    Short_to_array(INS_attitude[0], Telemetry_BASE.MainData+9);
    Short_to_array(INS_attitude[1], Telemetry_BASE.MainData+11);
    Short_to_array(INS_attitude[2], Telemetry_BASE.MainData+13);

  //GPSʹ�õ����Ǹ���
    quint16_to_array(GPS_satellite_num, Telemetry_BASE.MainData+15);

    //��Դ���������(A/10)
    Short_to_array(current, Telemetry_BASE.MainData+17);

    //INS�ĸ߶�(m/10)--��ʱ����
    Short_to_array(INS_height, Telemetry_BASE.MainData+19);

    //GPS�ĸ߶� (m/10)--��ʱ����
    Short_to_array(GPS_height, Telemetry_BASE.MainData+21);

    //��������ϵ�������ٶ�xyz
    Short_to_array(BCS_vel[0], Telemetry_BASE.MainData+23);
    Short_to_array(BCS_vel[1], (quint8 *)(Telemetry_BASE.MainData+25));
    Short_to_array(BCS_vel[2], Telemetry_BASE.MainData+27);

    //WGS84����ϵ��GPS��õ�γ��(rad)
    Float_to_array(lat, Telemetry_BASE.MainData+29);

    //WGS84����ϵ��GPS��õľ���(rad)
    Float_to_array(lon, Telemetry_BASE.MainData+33);

    //GPS��ƫ����(degree/10)
    Short_to_array(GPS_yaw, Telemetry_BASE.MainData+37);

    //GPS���ٶ�(m/s/100)
    quint16_to_array(GPS_vel, Telemetry_BASE.MainData+39);

    //�趨yaw (degree/50), pitch (degree/100), roll (degree/100)
    Short_to_array(attitude[0], Telemetry_BASE.MainData+41);
    Short_to_array(attitude[1], Telemetry_BASE.MainData+43);
    Short_to_array(attitude[2], Telemetry_BASE.MainData+45);

    //GPSˮƽ����ľ�������(HDOP)(1/100)
    Short_to_array(GPS_hdop, Telemetry_BASE.MainData+47);

    //��ѹ (v/10)
    Short_to_array(voltage, Telemetry_BASE.MainData+49);

    //�趨�߶� (m/10)
    Short_to_array(height, Telemetry_BASE.MainData+51);

    //��̼� (m/10)
    Short_to_array(distance, Telemetry_BASE.MainData+53);

    //��ֱyaw���� (1/10)
    Short_to_array(vertical_yaw_parameter, Telemetry_BASE.MainData+55);

    //UAV������ľ���(λ��) (m)
    quint16_to_array(displacement_to_ppm, Telemetry_BASE.MainData+57);

    //ˮ�õĿ�����־
    quint16_to_array(bump_flag, Telemetry_BASE.MainData+59);

    //��������1���Ȳ���
    memcpy(Telemetry_BASE.LData, ldata, 8);
    //Telemetry_BASE.LData

    Telemetry_BASE.DataEndByte = 0x55;		//��Ч���ݽ���

    //������ŪУ��ͣ���������Ϊ���鷽��
    Telemetry_BASE.EndByte[0] = 0xd3;		//֡����
    Telemetry_BASE.EndByte[1] = 0x0a;

    return Telemetry_BASE;
}


/**
 * @brief ��2��AP�����͵�Telemetry_BASE֡����TX_Buffer
 *
 * @param Telemetry_BASE
 * @param TX_Buffer[]
 **/
AP_MCRC void Telemetry_BASE_to_TX_Buffer(Telemetry_BASE_TypeDef Telemetry_BASE, quint8 TX_Buffer[])
{
    memset(TX_Buffer, 0, USART_REC_LEN);		//�򻺳���������ǰҪ�����

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
 * @brief ��3��GS��RX_Buffer�е����ݴ浽Telemetry_BASE_GS�ṹ���У���������
 *
 * @param Telemetry_BASE_GS ���ݱ�����
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
 * @brief ��4��GS����RX_Buffer�е�ң��֡���Ѹ��ֲ���������Ӧ����
 *
 * @param RX_Buffer ���ջ�������
 * @param Telemetry_BASE_GS
 * @param ��������
 **/
AP_MCRC void Decode_Telemetry_BASE(quint8 RX_Buffer[], Telemetry_BASE_TypeDef Telemetry_BASE_GS, quint8 UAV_flagbyte[], quint8 UAV_active_ppm_num,\
                                                quint8 UAV_FM_type, float UAV_AP_seconds, short UAV_INS_attitude[], quint16 UAV_GPS_satellite_num, short UAV_current,\
                                                    short UAV_INS_height, short UAV_GPS_height, short UAV_BCS_vel[], float UAV_lat, float UAV_lon,\
                                                        short UAV_GPS_yaw, quint16 UAV_GPS_vel, short UAV_attitude[], short UAV_GPS_hdop, short UAV_voltage,\
                                                            short UAV_height, short UAV_distance, short UAV_vertical_yaw_parameter, quint16 UAV_displacement_to_PPM,\
                                                                quint16 UAV_bump_flag, quint8 UAV_ldata[])
{
    //��һ�ؼ��飺��β��־��
    if(Telemetry_BASE_GS.HeaderByte[0] == 0x4e && Telemetry_BASE_GS.HeaderByte[1] == 0x41 \
        && Telemetry_BASE_GS.HeaderByte[2] == 0x56 && Telemetry_BASE_GS.EndByte[0] == 0xd3 \
        && Telemetry_BASE_GS.EndByte[1] == 0x0a)
    {
        if(Telemetry_BASE_GS.DataEndByte == 0x55)		//�ڶ��ؼ��飺��Ч���ݽ���λ
        {
            if(Telemetry_BASE_GS.CRC_TX == Get_CRC(RX_Buffer, 3))		//�����ؼ��飺CRC
            {
                //˫�ؼ���ͨ��
                //��ȡ�����ֲ�����������Ӧ����
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
                memset(RX_Buffer, 0, USART_REC_LEN);		//CRC��������
                printf("\r\n CRC��֤���� \r\n");
            }
        }
        else
        {
            memset(RX_Buffer, 0, USART_REC_LEN);		//CRC��������
            printf("\r\n ��Ч���ݽ���λ��֤���� \r\n");
        }
    }
    else
    {
        memset(RX_Buffer, 0, USART_REC_LEN);		//�׻�β��������
        printf("\r\n ��β��֤���� \r\n");
    }

    memset(RX_Buffer, 0, USART_REC_LEN);	//������ϣ���ս��ջ�����
}

#endif

