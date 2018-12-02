#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    database = new Database;
    setWindowIcon(QIcon(":/icons/images/ic_launcher.png"));
    setWindowTitle("MCRC Ground Control Station");
    //3D
    ui->visualization_3D->setVisible(false);

    //graph view
    DISPLAY_gyroscope = new Gyroscopeview(ui->graphicsView);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(set_start()));
    DISPLAY_mg = new Magview(ui->magView);
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(set_start()));
    setpoint = new Setpoint(ui->widget_map);

    ui->view_GPSlabel->setText("0.23");
    ui->view_GPStext->setText("GPS:");

    //signal plot
    signal_choose = new Signalchoose;
    //signal_choose->start();
    signal_choose->hide();
    signal_choose->wave_thread->plot_thread->chart_plot = ui->waveplotchart;

    //connect(ui->clearbutton,SIGNAL(clicked()),signal_choose->plot_thread,SLOT(clear_data()));

    QFileInfo file("./resource/map/offlinemap_demo/demo/1_11.html");//1_11 :/html/map/offlinemap_demo/demo/1_11.html   /home/chnn/MCRC/offlinemap_demo/demo/520.html
    QString url = "file:///";
    url += file.absoluteFilePath();
    ui->widget_map->setUrl(QUrl(url));
    //ui->widget_map->hide();
   // ui->widget_la_long->hide();
   // ui->widget_map_data->hide();
   // ui->widget_map_rightcommand->hide();

    connect(signal_choose->wave_thread->plot_thread->serial_setting->serial_thread,
            SIGNAL(data_progressfinished()), this, SLOT(display_dashboard()));//serial receive finished--display dash board
    connect(database->databasethread,SIGNAL(data2GCSfinished()), this, SLOT(display_dashboard()));//serial receive finished--display dash board
    connect(database->databasethread,SIGNAL(data2GCSfinished()), signal_choose->wave_thread, SLOT(emit_addpoints()));

    m_jsContext = new Document(ui->stackedWidget_rightmap);
    m_webChannel = new QWebChannel(ui->stackedWidget_rightmap);
    m_webChannel->registerObject("context", m_jsContext);
    ui->widget_map->page()->setWebChannel(m_webChannel);
    connect(m_jsContext, &Document::recvdMsg, this, [this](const QString &msg1,const QString &msg2) {
        ui->label_Latitude->setText(QString("%1").arg(msg1));
        ui->label_longitude->setText(QString("%1").arg(msg2));
        //qDebug()<<fixed<<qSetRealNumberPrecision(7)<<msg2.toDouble();
        m_jsContext->savepoints(msg2.toDouble(),msg1.toDouble());
    });

    connect(m_jsContext, &Document::recvdMsg_newpoint, this, [this](const QString &msg1,const QString &msg2,quint8 index_point) {
        ui->label_Latitude->setText(QString("%1").arg(msg1));
        ui->label_longitude->setText(QString("%1").arg(msg2));
        m_jsContext->changepoints(msg2.toDouble(),msg1.toDouble(),index_point);
    });

//map----set point & clear & move flag
    connect(ui->btnSend, &QPushButton::clicked, this, [this]() {
            m_jsContext->sendMsg(ui->widget_map->page(), "clear");
            m_jsContext->uiclear_init();map_Progress_Bar.MAP_POINTS = 0;});

    connect(ui->toolButton_setpoint, &QToolButton::clicked, this, [this]() {
            m_jsContext->sendMsg(ui->widget_map->page(), "setpoint");});


    connect(ui->toolButton_moveflag, &QToolButton::clicked, this, [this]() {
            m_jsContext->sendMsg(ui->widget_map->page(), "moveflag"); });

    connect(signal_choose->wave_thread->plot_thread->serial_setting->serial_thread,
            SIGNAL(data_progressfinished()), this, SLOT(labei_display()));
    connect(database->databasethread,SIGNAL(data2GCSfinished()), this, SLOT(labei_display()));
    connect(signal_choose->wave_thread->plot_thread->serial_setting->serial_thread,
            SIGNAL(data_progressfinished()), this, SLOT(display_3D()));
    connect(database->databasethread,SIGNAL(data2GCSfinished()), this, SLOT(display_3D()));

    ui->pushButton->setStyleSheet("QPushButton{background-color:black;color: white;   border-radius: 10px;  border: 2px groove gray;border-style: outset;}"

                                 "QPushButton:hover{background-color:white; color: black;}"

                                 "QPushButton:pressed{background-color:rgb(85, 170, 255);border-style: inset; }");

    protocolsetting = new Setting();

    protocolsetting->package_command->serial_protocol = signal_choose->wave_thread->plot_thread->serial_setting;
    connect(protocolsetting->package_command,&Package::map_progressbar,this,[this]() {
        if(map_Progress_Bar.MAP_POINTS < 100) ui->progressBar_mappoints->setValue(map_Progress_Bar.MAP_POINTS);
        else{
            ui->progressBar_mappoints->setValue(100);
            ui->progressBar_mappoints->setValue(0);
        }
    });
    //signal_choose->wave_thread->sensordatabase = database;
    ui->toolButton_setpoint->setCheckable(true);
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::display_3D()
{
    ui->visualization_3D->update_angles(AP_DATA2GCS);//3D view
}

void MainWindow::labei_display()
{
    ui->label_acc_x->setText(QString::number(AP_DATA2GCS.UAV_INS_Attitude[2]));
    ui->label_acc_y->setText(QString::number(AP_DATA2GCS.UAV_INS_Attitude[1]));
    ui->label_acc_z->setText(QString::number(AP_DATA2GCS.UAV_INS_Attitude[0]));
}


void MainWindow::display_dashboard()
{
    DISPLAY_gyroscope->setRoll(AP_DATA2GCS.UAV_INS_Attitude[2]);
    ui->label_roll->setText(QString::number(AP_DATA2GCS.UAV_INS_Attitude[2]));
    DISPLAY_gyroscope->setPitch(AP_DATA2GCS.UAV_INS_Attitude[1]);
    ui->label_pitch->setText(QString::number(AP_DATA2GCS.UAV_INS_Attitude[1]));
    DISPLAY_mg->setmagyaw(AP_DATA2GCS.UAV_INS_Attitude[0]);

}

void MainWindow::on_button_3D_clicked()
{
    static bool c ;
    c = !c;
    ui->visualization_3D->setVisible(c);
    ui->visualization_3D->visualization_state(c);
}

//debug
void MainWindow::set_start()
{
    QString str_x = ui->start_x->text();
    int start_x = str_x.toInt();

    QString str_y = ui->start_y->text();
    int start_y = str_y.toInt();

    QString str_width = ui->width->text();
    int width = str_width.toInt();

    QString str_height = ui->height->text();
    int height = str_height.toInt();

    QString str_other = ui->other->text();
    int other = str_other.toInt();

    DISPLAY_gyroscope->paint_display(start_x,start_y,width,height,other);
    DISPLAY_mg->set_mag(start_x,start_y,width,height,other);

}

void MainWindow::on_toolButton_serial_clicked()
{
    signal_choose->wave_thread->plot_thread->serial_setting->show();
}

void MainWindow::on_verticalSlider_pitch_valueChanged(int value)
{
    DISPLAY_gyroscope->setPitch(value);
    ui->label_pitch->setText(QString::number(value));
}

void MainWindow::on_dial_pitch_valueChanged(int value)
{
    DISPLAY_gyroscope->setRoll(value);
    ui->label_roll->setText(QString::number(value));
}

void MainWindow::on_signal_choose_clicked()
{
    signal_choose->show();
}


void MainWindow::on_clearbutton_clicked()
{
    signal_choose->wave_thread->plot_thread->clear_data();
}


void MainWindow::on_toolButton_9_clicked()
{
    ui->stackedWidget_rightmap->setCurrentIndex(1);
}

void MainWindow::on_toolButton_8_clicked()
{
    ui->stackedWidget_rightmap->setCurrentIndex(0);
}

void MainWindow::on_toolButton_mappoints_clicked()
{
    m_jsContext->mappoints->show_hide();
}

void MainWindow::on_toolButton_setting_clicked()
{
    protocolsetting->show_hide();
}

void MainWindow::on_toolButton_13_clicked()
{
    protocolsetting->AP_Command(0);
}

void MainWindow::on_toolButton_12_clicked()
{
    database->dialogshowhide();
}

void MainWindow::on_toolButton_14_clicked()
{
    database->readdatafromdatabase();
}

void MainWindow::on_toolButton_mappoints_send_clicked()
{
    protocolsetting->package_command->AP_Trajectory_Planning();//发送地图航点轨迹规划到无人机
}
