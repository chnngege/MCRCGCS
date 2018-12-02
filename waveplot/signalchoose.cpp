#include "signalchoose.h"
#include "ui_signalchoose.h"
bool check_flag[3] = {0,0,0};

Signalchoose::Signalchoose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signalchoose)
{
    ui->setupUi(this);
    wave_thread = new Wavethread;
    fillColorList(ui->comboBox_color);
    fillColorList(ui->comboBox_color_2);
    fillColorList(ui->comboBox_color_3);
    signallist(ui->comboBox_signal);
    signallist(ui->comboBox_signal_2);
    signallist(ui->comboBox_signal_3);
}


Signalchoose::~Signalchoose()
{
    delete ui;
}

//init colorlist conbox
void Signalchoose::fillColorList( QComboBox * combobox )
{
    QStringList colorList = QColor::colorNames();
    QString color;

    foreach( color, colorList )
    {
        QPixmap pix(QSize( 20, 20));
        pix.fill( QColor( color ) );
        combobox->addItem( QIcon( pix ), NULL );
        //combobox->setIconSize( QSize( 20, 20 ) );
        combobox->setSizeAdjustPolicy( QComboBox::AdjustToContents );
    }
}

//init signallist conbox
void Signalchoose::signallist(QComboBox * combobox)
{
    QStringList list;
    list << "INS_YAW" << "INS_ROLL" << "INS_PITCH" << "INS_HEIGHT"
         << "SET_YAW" << "SET_ROLL" << "SET_PITCH" << "SET_HEIGHT"
         << "GPS_HEIGHT"  << "GPS_SPEED" << "GPS_YAW"
         << "SPEED_OX" << "SPEED_OY" << "SPEED_OZ" ;
    combobox->addItems(list);
}


//get color and signal from comboxes
void Signalchoose::get_color_signal()
{
    QStringList colorList = QColor::colorNames();
    //get signal
    index_signal[0] = ui->comboBox_signal->currentIndex();
    index_signal[1] = ui->comboBox_signal_2->currentIndex();
    index_signal[2] = ui->comboBox_signal_3->currentIndex();
    //get color
    color[0] = QColor( colorList[ ui->comboBox_color->currentIndex() ] );
    color[1] = QColor( colorList[ ui->comboBox_color_2->currentIndex() ] );
    color[2] = QColor( colorList[ ui->comboBox_color_3->currentIndex() ] );   
}

void Signalchoose::on_buttonBox_accepted()
{
    get_color_signal();//get color and signal from comboxes
    hide();//exit signalchoose ui
    wave_thread->connect_thread();
    wave_thread->start();
    wave_thread->set_color(index_signal,color);
}

void Signalchoose::on_buttonBox_rejected()
{
    hide();
    wave_thread->disconnect_thread();
}

void Signalchoose::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){ // "选中"
           check_flag[0] = true;
    }
    else{ // 未选中 - Qt::Unchecked
           check_flag[0] = false;
    }
}

void Signalchoose::on_checkBox_2_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){ // "选中"
           check_flag[1] = true;
    }
    else{ // 未选中 - Qt::Unchecked
           check_flag[1] = false;
    }
}

void Signalchoose::on_checkBox_3_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked){ // "选中"
           check_flag[2] = true;
    }
    else{ // 未选中 - Qt::Unchecked
           check_flag[2] = false;
    }
}

