#include "setting.h"
#include "ui_setting.h"

float valuefromsetting;//extern---get value from LineEdit,then send them to AP

Setting::Setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    Qt::WindowFlags flags = this->windowFlags();
    this->setWindowFlags(flags | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);

    //timer
    m_pTimer = new QTimer(this);
    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(handleTimeout()));

    package_command = new Package;
    toconfig = new Toconfig;
    ui->lineEdit_configname->setPlaceholderText("xxx.ini");
}

Setting::~Setting()
{
    delete ui;
}

//single command--send
void Setting::AP_Command(quint8 id)
{
    typedef void (Package::*AP_Command_TypeDef)(void);
    AP_Command_TypeDef AP_Command[] ={
        &Package::FM_Task,
        &Package::One_button_return,
        &Package::Cancel_onebuttonreturn,
        &Package::Emergency_APlanding,
        &Package::Open_APmotor,
        &Package::Close_APmotor,
        &Package::Test_APmotor,
        &Package::Send_PWM,
        &Package::Open_APcamera,
        &Package::Calibrate_MC,
        &Package::Restart_AP,
        &Package::Execution_FM,
        &Package::Calibrate_APMC,
        &Package::Stop_Calibrate_APMC,
        &Package::Calibrate_Accelerometer_Zero,
        &Package::Hover_AP,
        &Package::Circle_AP,
        &Package::No_FM_Flight,
        &Package::Savedata_AP,
        &Package::Flight_Simulation,
        &Package::Disable_INS_Correction,
        &Package::Enable_INS_Correction,
        &Package::MR_FB,
        &Package::Send_FB_Coefficient,
        &Package::Send_APINS_Coefficient,
        &Package::Send_Coordinates_Height,
        &Package::Joystick_APreturn,
        &Package::Joystick_APrepeat,
        &Package::Joystick_EmergencyLanding,
        &Package::Joystick_Manual_Control,
        &Package::Joystick_Automatic_Control,
        &Package::Joystick_Semi_automatic_Control,
        &Package::Joystick_Open_APmotor,
        &Package::Joystick_Close_APmotor,
        &Package::Send_APpump_Speed,
        &Package::CalibrationPWM_1000,
        &Package::CalibrationPWM_2000,
        &Package::Start_CalibrationPWM,
        &Package::Finish_CalibrationPWM,
        &Package::Joystick_APcontrol,
        &Package::Activate_joystick,
        &Package::OSN_BOL,
        &Package::OSN_MAL,
        &Package::OSN_Telemetry_package,
        &Package::_5S_Timestamp
    };
    AP_Command_TypeDef fun_choose = AP_Command[id];
    (package_command->*fun_choose)();
}

void Setting::paintEvent(QPaintEvent *e)
{
    QPainter painter(ui->widget_leftbutton);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
   // painter.translate(input, 0);
}

void Setting::show_hide()
{
    static bool flag;
    if(flag){
        hide();
        flag = !flag;
    }
    else {
        show();
        flag = !flag;
    }
}

void Setting::on_pushButton_input_clicked()
{
    m_pTimer->start(7);
}

void Setting::handleTimeout()
{
    static int time_count=0;
    if(m_pTimer->isActive()){
        m_pTimer->stop();
    }

    if(databasename_showhide_flag){
        ui->lineEdit_configname->setGeometry(330+time_count,40,113,25);//hide
    }
    else ui->lineEdit_configname->setGeometry(445-time_count,40,113,25);//show

    time_count = time_count + 1;
    if(time_count >= 115){
        m_pTimer->stop();
        time_count = 0;
        databasename_showhide_flag = !databasename_showhide_flag;
    }
    else m_pTimer->start(7);
}

void Setting::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void Setting::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx,y()+dy);
}

void Setting::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx,y()+dy);
}

void Setting::on_toolButton_exit_clicked()
{
    hide();
}
//save name
void Setting::on_lineEdit_configname_returnPressed()
{
    databasename_showhide_flag = 1;//hide
    m_pTimer->start(7);
    QString configname = ui->lineEdit_configname->text();

    if(configname == "")
        return;
    else
        toconfig->getsavename(configname);
}
//load setting ini
void Setting::on_toolButton_load_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
         tr("Select config"), "./");    //init the path of file
    toconfig->readfromini(path);
    displaydatafromini();
}
//send parmaters to AP-----save value in valuefromsetting
void Setting::on_pushButton_send_clicked()
{
    switch(id_lineedit){
        case 1:valuefromsetting = ui->lineEdit_1->text().toFloat();break;
        case 2:valuefromsetting = ui->lineEdit_2->text().toFloat();break;
        case 3:valuefromsetting = ui->lineEdit_3->text().toFloat();break;
        case 4:valuefromsetting = ui->lineEdit_4->text().toFloat();break;
        case 5:valuefromsetting = ui->lineEdit_5->text().toFloat();break;
        case 6:valuefromsetting = ui->lineEdit_6->text().toFloat();break;
        case 7:valuefromsetting = ui->lineEdit_7->text().toFloat();break;
        case 8:valuefromsetting = ui->lineEdit_8->text().toFloat();break;
        case 9:valuefromsetting = ui->lineEdit_9->text().toFloat();break;
        case 10:valuefromsetting = ui->lineEdit_10->text().toFloat();break;
        case 11:valuefromsetting = ui->lineEdit_11->text().toFloat();break;
        case 12:valuefromsetting = ui->lineEdit_12->text().toFloat();break;
        case 13:valuefromsetting = ui->lineEdit_13->text().toFloat();break;
        case 14:valuefromsetting = ui->lineEdit_14->text().toFloat();break;
        case 15:valuefromsetting = ui->lineEdit_15->text().toFloat();break;
        case 16:valuefromsetting = ui->lineEdit_16->text().toFloat();break;
        case 17:valuefromsetting = ui->lineEdit_17->text().toFloat();break;
        case 18:valuefromsetting = ui->lineEdit_18->text().toFloat();break;
        case 19:valuefromsetting = ui->lineEdit_19->text().toFloat();break;
        case 20:valuefromsetting = ui->lineEdit_20->text().toFloat();break;
        case 21:valuefromsetting = ui->lineEdit_21->text().toFloat();break;
        case 22:valuefromsetting = ui->lineEdit_22->text().toFloat();break;
        case 23:valuefromsetting = ui->lineEdit_23->text().toFloat();break;
        case 24:valuefromsetting = ui->lineEdit_24->text().toFloat();break;
        case 25:valuefromsetting = ui->lineEdit_25->text().toFloat();break;
        case 26:valuefromsetting = ui->lineEdit_26->text().toFloat();break;
        case 27:valuefromsetting = ui->lineEdit_27->text().toFloat();break;
        case 28:valuefromsetting = ui->lineEdit_28->text().toFloat();break;
        case 29:valuefromsetting = ui->lineEdit_29->text().toFloat();break;
        case 30:valuefromsetting = ui->lineEdit_30->text().toFloat();break;
        case 31:valuefromsetting = ui->lineEdit_31->text().toFloat();break;
        case 32:valuefromsetting = ui->lineEdit_32->text().toFloat();break;
        case 33:valuefromsetting = ui->lineEdit_33->text().toFloat();break;
        case 34:valuefromsetting = ui->lineEdit_34->text().toFloat();break;
        case 35:valuefromsetting = ui->lineEdit_35->text().toFloat();break;
        case 36:valuefromsetting = ui->lineEdit_36->text().toFloat();break;
        case 37:valuefromsetting = ui->lineEdit_37->text().toFloat();break;
        case 38:valuefromsetting = ui->lineEdit_38->text().toFloat();break;
        case 39:valuefromsetting = ui->lineEdit_39->text().toFloat();break;
        case 40:valuefromsetting = ui->lineEdit_40->text().toFloat();break;
        case 41:valuefromsetting = ui->lineEdit_41->text().toFloat();break;
        case 42:valuefromsetting = ui->lineEdit_42->text().toFloat();break;
        case 43:valuefromsetting = ui->lineEdit_43->text().toFloat();break;
        case 44:valuefromsetting = ui->lineEdit_44->text().toFloat();break;
        case 45:valuefromsetting = ui->lineEdit_45->text().toFloat();break;
        case 46:valuefromsetting = ui->lineEdit_46->text().toFloat();break;
        case 47:valuefromsetting = ui->lineEdit_47->text().toFloat();break;
        case 48:valuefromsetting = ui->lineEdit_48->text().toFloat();break;
        case 49:valuefromsetting = ui->lineEdit_49->text().toFloat();break;
        case 50:valuefromsetting = ui->lineEdit_50->text().toFloat();break;
        case 51:valuefromsetting = ui->lineEdit_51->text().toFloat();break;
        case 52:valuefromsetting = ui->lineEdit_52->text().toFloat();break;
        case 53:valuefromsetting = ui->lineEdit_53->text().toFloat();break;
        case 54:valuefromsetting = ui->lineEdit_54->text().toFloat();break;
        case 55:valuefromsetting = ui->lineEdit_55->text().toFloat();break;
        case 56:valuefromsetting = ui->lineEdit_56->text().toFloat();break;
        case 57:valuefromsetting = ui->lineEdit_57->text().toFloat();break;
        case 58:valuefromsetting = ui->lineEdit_58->text().toFloat();break;
        case 59:valuefromsetting = ui->lineEdit_59->text().toFloat();break;
        case 60:valuefromsetting = ui->lineEdit_60->text().toFloat();break;
        case 61:valuefromsetting = ui->lineEdit_61->text().toFloat();break;
        case 62:valuefromsetting = ui->lineEdit_62->text().toFloat();break;
        case 63:valuefromsetting = ui->lineEdit_63->text().toFloat();break;
        case 64:valuefromsetting = ui->lineEdit_64->text().toFloat();break;
        case 65:valuefromsetting = ui->lineEdit_65->text().toFloat();break;
        case 66:valuefromsetting = ui->lineEdit_66->text().toFloat();break;
        case 67:valuefromsetting = ui->lineEdit_67->text().toFloat();break;
        case 68:valuefromsetting = ui->lineEdit_68->text().toFloat();break;
        case 69:valuefromsetting = ui->lineEdit_69->text().toFloat();break;

        default:break;
    }
}
//******************************************************//
void Setting::on_lineEdit_1_editingFinished()
{
    ui->pushButton_send->setGeometry(370,40,41,21);
    id_lineedit = 1;
}

void Setting::on_lineEdit_2_editingFinished()
{
    ui->pushButton_send->setGeometry(370,60,41,21);
    id_lineedit = 2;
}

void Setting::on_lineEdit_3_editingFinished()
{
    ui->pushButton_send->setGeometry(370,80,41,21);
    id_lineedit = 3;
}

void Setting::on_lineEdit_4_editingFinished()
{
    ui->pushButton_send->setGeometry(370,100,41,21);
    id_lineedit = 4;
}

void Setting::on_lineEdit_5_editingFinished()
{
    ui->pushButton_send->setGeometry(370,120,41,21);
    id_lineedit = 5;
}

void Setting::on_lineEdit_6_editingFinished()
{
    ui->pushButton_send->setGeometry(370,140,41,21);
    id_lineedit = 6;
}

void Setting::on_lineEdit_7_editingFinished()
{
    ui->pushButton_send->setGeometry(370,180,41,21);
    id_lineedit = 7;
}

void Setting::on_lineEdit_8_editingFinished()
{
    ui->pushButton_send->setGeometry(370,200,41,21);
    id_lineedit = 8;
}

void Setting::on_lineEdit_9_editingFinished()
{
    ui->pushButton_send->setGeometry(370,220,41,21);
    id_lineedit = 9;
}

void Setting::on_lineEdit_10_editingFinished()
{
    ui->pushButton_send->setGeometry(370,240,41,21);
    id_lineedit = 10;
}

void Setting::on_lineEdit_11_editingFinished()
{
    ui->pushButton_send->setGeometry(370,260,41,21);
    id_lineedit = 11;
}

void Setting::on_lineEdit_12_editingFinished()
{
    ui->pushButton_send->setGeometry(370,280,41,21);
    id_lineedit = 12;
}

void Setting::on_lineEdit_13_editingFinished()
{
    ui->pushButton_send->setGeometry(370,320,41,21);
    id_lineedit = 13;
}

void Setting::on_lineEdit_14_editingFinished()
{
    ui->pushButton_send->setGeometry(370,340,41,21);
    id_lineedit = 14;
}

void Setting::on_lineEdit_15_editingFinished()
{
    ui->pushButton_send->setGeometry(370,360,41,21);
    id_lineedit = 15;
}

void Setting::on_lineEdit_16_editingFinished()
{
    ui->pushButton_send->setGeometry(370,380,41,21);
    id_lineedit = 16;
}

void Setting::on_lineEdit_17_editingFinished()
{
    ui->pushButton_send->setGeometry(370,400,41,21);
    id_lineedit = 17;
}

void Setting::on_lineEdit_18_editingFinished()
{
    ui->pushButton_send->setGeometry(370,420,41,21);
    id_lineedit = 18;
}

void Setting::on_lineEdit_19_editingFinished()
{
    ui->pushButton_send->setGeometry(370,440,41,21);
    id_lineedit = 19;
}

void Setting::on_lineEdit_20_editingFinished()
{
    ui->pushButton_send->setGeometry(370,460,41,21);
    id_lineedit = 20;
}

void Setting::on_lineEdit_21_editingFinished()
{
    ui->pushButton_send->setGeometry(370,480,41,21);
    id_lineedit = 21;
}

void Setting::on_lineEdit_22_editingFinished()
{
    ui->pushButton_send->setGeometry(370,520,41,21);
    id_lineedit = 22;
}

void Setting::on_lineEdit_23_editingFinished()
{
    ui->pushButton_send->setGeometry(370,540,41,21);
    id_lineedit = 23;
}

void Setting::on_lineEdit_24_editingFinished()
{
    ui->pushButton_send->setGeometry(370,560,41,21);
    id_lineedit = 24;
}

void Setting::on_lineEdit_25_editingFinished()
{
    ui->pushButton_send->setGeometry(370,580,41,21);
    id_lineedit = 25;
}

void Setting::on_lineEdit_26_editingFinished()
{
    ui->pushButton_send->setGeometry(370,620,41,21);
    id_lineedit = 26;
}

void Setting::on_lineEdit_27_editingFinished()
{
    ui->pushButton_send->setGeometry(370,640,41,21);
    id_lineedit = 27;
}

void Setting::on_lineEdit_28_editingFinished()
{
    ui->pushButton_send->setGeometry(370,660,41,21);
    id_lineedit = 28;
}
void Setting::on_lineEdit_29_editingFinished()
{
    ui->pushButton_send->setGeometry(370,680,41,21);
    id_lineedit = 29;
}
void Setting::on_lineEdit_30_editingFinished()
{
    ui->pushButton_send->setGeometry(370,700,41,21);
    id_lineedit = 30;
}
void Setting::on_lineEdit_31_editingFinished()
{
    ui->pushButton_send->setGeometry(370,720,41,21);
    id_lineedit = 31;
}
void Setting::on_lineEdit_32_editingFinished()
{
    ui->pushButton_send->setGeometry(370,740,41,21);
    id_lineedit = 32;
}
void Setting::on_lineEdit_33_editingFinished()
{
    ui->pushButton_send->setGeometry(370,760,41,21);
    id_lineedit = 33;
}
void Setting::on_lineEdit_34_editingFinished()
{
    ui->pushButton_send->setGeometry(370,780,41,21);
    id_lineedit = 34;
}
void Setting::on_lineEdit_35_editingFinished()
{
    ui->pushButton_send->setGeometry(370,800,41,21);
    id_lineedit = 35;
}
void Setting::on_lineEdit_36_editingFinished()
{
    ui->pushButton_send->setGeometry(370,840,41,21);
    id_lineedit = 36;
}
void Setting::on_lineEdit_37_editingFinished()
{
    ui->pushButton_send->setGeometry(370,860,41,21);
    id_lineedit = 37;
}
void Setting::on_lineEdit_38_editingFinished()
{
    ui->pushButton_send->setGeometry(370,880,41,21);
    id_lineedit = 38;
}
void Setting::on_lineEdit_39_editingFinished()
{
    ui->pushButton_send->setGeometry(370,900,41,21);
    id_lineedit = 39;
}
void Setting::on_lineEdit_40_editingFinished()
{
    ui->pushButton_send->setGeometry(370,920,41,21);
    id_lineedit = 40;
}
void Setting::on_lineEdit_41_editingFinished()
{
    ui->pushButton_send->setGeometry(370,940,41,21);
    id_lineedit = 41;
}
void Setting::on_lineEdit_42_editingFinished()
{
    ui->pushButton_send->setGeometry(370,960,41,21);
    id_lineedit = 42;
}
void Setting::on_lineEdit_43_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1000,41,21);
    id_lineedit = 43;
}
void Setting::on_lineEdit_44_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1020,41,21);
    id_lineedit = 44;
}
void Setting::on_lineEdit_45_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1040,41,21);
    id_lineedit = 45;
}
void Setting::on_lineEdit_46_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1060,41,21);
    id_lineedit = 46;
}
void Setting::on_lineEdit_47_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1080,41,21);
    id_lineedit = 47;
}
void Setting::on_lineEdit_48_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1100,41,21);
    id_lineedit = 48;
}
void Setting::on_lineEdit_49_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1120,41,21);
    id_lineedit = 49;
}
void Setting::on_lineEdit_50_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1140,41,21);
    id_lineedit = 50;
}
void Setting::on_lineEdit_51_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1160,41,21);
    id_lineedit = 51;
}
void Setting::on_lineEdit_52_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1180,41,21);
    id_lineedit = 52;
}
void Setting::on_lineEdit_53_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1200,41,21);
    id_lineedit = 53;
}
void Setting::on_lineEdit_54_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1220,41,21);
    id_lineedit = 54;
}
void Setting::on_lineEdit_55_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1240,41,21);
    id_lineedit = 55;
}
void Setting::on_lineEdit_56_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1260,41,21);
    id_lineedit = 56;
}
void Setting::on_lineEdit_57_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1280,41,21);
    id_lineedit = 57;
}
void Setting::on_lineEdit_58_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1300,41,21);
    id_lineedit = 58;
}
void Setting::on_lineEdit_59_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1320,41,21);
    id_lineedit = 59;
}
void Setting::on_lineEdit_60_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1340,41,21);
    id_lineedit = 60;
}
void Setting::on_lineEdit_61_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1360,41,21);
    id_lineedit = 61;
}
void Setting::on_lineEdit_62_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1380,41,21);
    id_lineedit = 62;
}
void Setting::on_lineEdit_63_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1400,41,21);
    id_lineedit = 63;
}
void Setting::on_lineEdit_64_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1420,41,21);
    id_lineedit = 64;
}
void Setting::on_lineEdit_65_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1440,41,21);
    id_lineedit = 65;
}
void Setting::on_lineEdit_66_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1460,41,21);
    id_lineedit = 66;
}
void Setting::on_lineEdit_67_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1500,41,21);
    id_lineedit = 67;
}
void Setting::on_lineEdit_68_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1520,41,21);
    id_lineedit = 68;
}
void Setting::on_lineEdit_69_editingFinished()
{
    ui->pushButton_send->setGeometry(370,1540,41,21);
    id_lineedit = 69;
}


void Setting::on_toolButton_save_clicked()
{
    datafromlineedit[0] = ui->lineEdit_1->text().toDouble();
    datafromlineedit[1] = ui->lineEdit_2->text().toDouble();
    datafromlineedit[2] = ui->lineEdit_3->text().toDouble();
    datafromlineedit[3] = ui->lineEdit_4->text().toDouble();
    datafromlineedit[4] = ui->lineEdit_5->text().toDouble();
    datafromlineedit[5] = ui->lineEdit_6->text().toDouble();
    datafromlineedit[6] = ui->lineEdit_7->text().toDouble();
    datafromlineedit[7] = ui->lineEdit_8->text().toDouble();
    datafromlineedit[8] = ui->lineEdit_9->text().toDouble();
    datafromlineedit[9] = ui->lineEdit_10->text().toDouble();
    datafromlineedit[10] = ui->lineEdit_11->text().toDouble();
    datafromlineedit[11] = ui->lineEdit_12->text().toDouble();
    datafromlineedit[12] = ui->lineEdit_13->text().toDouble();
    datafromlineedit[13] = ui->lineEdit_14->text().toDouble();
    datafromlineedit[14] = ui->lineEdit_15->text().toDouble();
    datafromlineedit[15] = ui->lineEdit_16->text().toDouble();
    datafromlineedit[16] = ui->lineEdit_17->text().toDouble();
    datafromlineedit[17] = ui->lineEdit_18->text().toDouble();
    datafromlineedit[18] = ui->lineEdit_19->text().toDouble();
    datafromlineedit[19] = ui->lineEdit_20->text().toDouble();
    datafromlineedit[20] = ui->lineEdit_21->text().toDouble();
    datafromlineedit[21] = ui->lineEdit_22->text().toDouble();
    datafromlineedit[22] = ui->lineEdit_23->text().toDouble();
    datafromlineedit[23] = ui->lineEdit_24->text().toDouble();
    datafromlineedit[24] = ui->lineEdit_25->text().toDouble();
    datafromlineedit[25] = ui->lineEdit_26->text().toDouble();
    datafromlineedit[26] = ui->lineEdit_27->text().toDouble();
    datafromlineedit[27] = ui->lineEdit_28->text().toDouble();
    datafromlineedit[28] = ui->lineEdit_29->text().toDouble();
    datafromlineedit[29] = ui->lineEdit_30->text().toDouble();
    datafromlineedit[30] = ui->lineEdit_31->text().toDouble();
    datafromlineedit[31] = ui->lineEdit_32->text().toDouble();
    datafromlineedit[32] = ui->lineEdit_33->text().toDouble();
    datafromlineedit[33] = ui->lineEdit_34->text().toDouble();
    datafromlineedit[34] = ui->lineEdit_35->text().toDouble();
    datafromlineedit[35] = ui->lineEdit_36->text().toDouble();
    datafromlineedit[36] = ui->lineEdit_37->text().toDouble();
    datafromlineedit[37] = ui->lineEdit_38->text().toDouble();
    datafromlineedit[38] = ui->lineEdit_39->text().toDouble();
    datafromlineedit[39] = ui->lineEdit_40->text().toDouble();
    datafromlineedit[40] = ui->lineEdit_41->text().toDouble();
    datafromlineedit[41] = ui->lineEdit_42->text().toDouble();
    datafromlineedit[42] = ui->lineEdit_43->text().toDouble();
    datafromlineedit[43] = ui->lineEdit_44->text().toDouble();
    datafromlineedit[44] = ui->lineEdit_45->text().toDouble();
    datafromlineedit[45] = ui->lineEdit_46->text().toDouble();
    datafromlineedit[46] = ui->lineEdit_47->text().toDouble();
    datafromlineedit[47] = ui->lineEdit_48->text().toDouble();
    datafromlineedit[48] = ui->lineEdit_49->text().toDouble();
    datafromlineedit[49] = ui->lineEdit_50->text().toDouble();
    datafromlineedit[50] = ui->lineEdit_51->text().toDouble();
    datafromlineedit[51] = ui->lineEdit_52->text().toDouble();
    datafromlineedit[52] = ui->lineEdit_53->text().toDouble();
    datafromlineedit[53] = ui->lineEdit_54->text().toDouble();
    datafromlineedit[54] = ui->lineEdit_55->text().toDouble();
    datafromlineedit[55] = ui->lineEdit_56->text().toDouble();
    datafromlineedit[56] = ui->lineEdit_57->text().toDouble();
    datafromlineedit[57] = ui->lineEdit_58->text().toDouble();
    datafromlineedit[58] = ui->lineEdit_59->text().toDouble();
    datafromlineedit[59] = ui->lineEdit_60->text().toDouble();
    datafromlineedit[60] = ui->lineEdit_61->text().toDouble();
    datafromlineedit[61] = ui->lineEdit_62->text().toDouble();
    datafromlineedit[62] = ui->lineEdit_63->text().toDouble();
    datafromlineedit[63] = ui->lineEdit_64->text().toDouble();
    datafromlineedit[64] = ui->lineEdit_65->text().toDouble();
    datafromlineedit[65] = ui->lineEdit_66->text().toDouble();
    datafromlineedit[66] = ui->lineEdit_67->text().toDouble();
    datafromlineedit[67] = ui->lineEdit_68->text().toDouble();
    datafromlineedit[68] = ui->lineEdit_69->text().toDouble();

    toconfig->creatini(datafromlineedit);
}




void Setting::displaydatafromini()
{
    ui->lineEdit_1->setText(QString("%1").arg(datafromini[0]));
    ui->lineEdit_2->setText(QString("%1").arg(datafromini[1]));
    ui->lineEdit_3->setText(QString("%1").arg(datafromini[2]));
    ui->lineEdit_4->setText(QString("%1").arg(datafromini[3]));
    ui->lineEdit_5->setText(QString("%1").arg(datafromini[4]));
    ui->lineEdit_6->setText(QString("%1").arg(datafromini[5]));
    ui->lineEdit_7->setText(QString("%1").arg(datafromini[6]));
    ui->lineEdit_8->setText(QString("%1").arg(datafromini[7]));
    ui->lineEdit_9->setText(QString("%1").arg(datafromini[8]));
    ui->lineEdit_10->setText(QString("%1").arg(datafromini[9]));
    ui->lineEdit_11->setText(QString("%1").arg(datafromini[10]));
    ui->lineEdit_12->setText(QString("%1").arg(datafromini[11]));
    ui->lineEdit_13->setText(QString("%1").arg(datafromini[12]));
    ui->lineEdit_14->setText(QString("%1").arg(datafromini[13]));
    ui->lineEdit_15->setText(QString("%1").arg(datafromini[14]));
    ui->lineEdit_16->setText(QString("%1").arg(datafromini[15]));
    ui->lineEdit_17->setText(QString("%1").arg(datafromini[16]));
    ui->lineEdit_18->setText(QString("%1").arg(datafromini[17]));
    ui->lineEdit_19->setText(QString("%1").arg(datafromini[18]));
    ui->lineEdit_20->setText(QString("%1").arg(datafromini[19]));
    ui->lineEdit_21->setText(QString("%1").arg(datafromini[20]));
    ui->lineEdit_22->setText(QString("%1").arg(datafromini[21]));
    ui->lineEdit_23->setText(QString("%1").arg(datafromini[22]));
    ui->lineEdit_24->setText(QString("%1").arg(datafromini[23]));
    ui->lineEdit_25->setText(QString("%1").arg(datafromini[24]));
    ui->lineEdit_26->setText(QString("%1").arg(datafromini[25]));
    ui->lineEdit_27->setText(QString("%1").arg(datafromini[26]));
    ui->lineEdit_28->setText(QString("%1").arg(datafromini[27]));
    ui->lineEdit_29->setText(QString("%1").arg(datafromini[28]));
    ui->lineEdit_30->setText(QString("%1").arg(datafromini[29]));
    ui->lineEdit_31->setText(QString("%1").arg(datafromini[30]));
    ui->lineEdit_32->setText(QString("%1").arg(datafromini[31]));
    ui->lineEdit_33->setText(QString("%1").arg(datafromini[32]));
    ui->lineEdit_34->setText(QString("%1").arg(datafromini[33]));
    ui->lineEdit_35->setText(QString("%1").arg(datafromini[34]));
    ui->lineEdit_36->setText(QString("%1").arg(datafromini[35]));
    ui->lineEdit_37->setText(QString("%1").arg(datafromini[36]));
    ui->lineEdit_38->setText(QString("%1").arg(datafromini[37]));
    ui->lineEdit_39->setText(QString("%1").arg(datafromini[38]));
    ui->lineEdit_40->setText(QString("%1").arg(datafromini[39]));
    ui->lineEdit_41->setText(QString("%1").arg(datafromini[40]));
    ui->lineEdit_42->setText(QString("%1").arg(datafromini[41]));
    ui->lineEdit_43->setText(QString("%1").arg(datafromini[42]));
    ui->lineEdit_44->setText(QString("%1").arg(datafromini[43]));
    ui->lineEdit_45->setText(QString("%1").arg(datafromini[44]));
    ui->lineEdit_46->setText(QString("%1").arg(datafromini[45]));
    ui->lineEdit_47->setText(QString("%1").arg(datafromini[46]));
    ui->lineEdit_48->setText(QString("%1").arg(datafromini[47]));
    ui->lineEdit_49->setText(QString("%1").arg(datafromini[48]));
    ui->lineEdit_50->setText(QString("%1").arg(datafromini[49]));
    ui->lineEdit_51->setText(QString("%1").arg(datafromini[50]));
    ui->lineEdit_52->setText(QString("%1").arg(datafromini[51]));
    ui->lineEdit_53->setText(QString("%1").arg(datafromini[52]));
    ui->lineEdit_54->setText(QString("%1").arg(datafromini[53]));
    ui->lineEdit_55->setText(QString("%1").arg(datafromini[54]));
    ui->lineEdit_56->setText(QString("%1").arg(datafromini[55]));
    ui->lineEdit_57->setText(QString("%1").arg(datafromini[56]));
    ui->lineEdit_58->setText(QString("%1").arg(datafromini[57]));
    ui->lineEdit_59->setText(QString("%1").arg(datafromini[58]));
    ui->lineEdit_60->setText(QString("%1").arg(datafromini[59]));
    ui->lineEdit_61->setText(QString("%1").arg(datafromini[60]));
    ui->lineEdit_62->setText(QString("%1").arg(datafromini[61]));
    ui->lineEdit_63->setText(QString("%1").arg(datafromini[62]));
    ui->lineEdit_64->setText(QString("%1").arg(datafromini[63]));
    ui->lineEdit_65->setText(QString("%1").arg(datafromini[64]));
    ui->lineEdit_66->setText(QString("%1").arg(datafromini[65]));
    ui->lineEdit_67->setText(QString("%1").arg(datafromini[66]));
    ui->lineEdit_68->setText(QString("%1").arg(datafromini[67]));
    ui->lineEdit_69->setText(QString("%1").arg(datafromini[68]));
}



void Setting::on_pushButton_APparameter_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Setting::on_pushButton_singlecommand_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
