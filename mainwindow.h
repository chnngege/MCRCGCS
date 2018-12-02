#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QList>
#include <QMessageBox>

#include "waveplot/wavesetting.h"
#include "serial/serialthread.h"
#include "board/gyroscopeview.h"
#include "board/magview.h"
#include "serial/serialsetting.h"
#include "map/setpoint.h"
#include "protocol/setting.h"
#include "protocol/types.h"
#include "protocol/checksum.h"
#include "protocol/helper.h"
#include "protocol/package.h"
#include "database/database.h"
#include "config/toconfig.h"
#include "database/databasethread.h"

#include <QWidget>
#include <QtGui>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>
#include <QRect>
#include <QRectF>
#include <QToolButton>
#include <QThread>
#include "waveplot/signalchoose.h"
#include <qwebengineview.h>
#include <QFileInfo>
#include <QtWebChannel/QtWebChannel>
#include <map/document.h>
#include <QFile>
#include <QWebChannel>
#include "iostream"

using namespace std;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void remote_sensor_infos(void);

private slots:
    void set_start();
    void on_button_3D_clicked();
    void on_toolButton_serial_clicked();
    void on_verticalSlider_pitch_valueChanged(int value);
    void on_dial_pitch_valueChanged(int value);
    void on_signal_choose_clicked();
    void display_dashboard();
    void on_clearbutton_clicked();
    void labei_display();
    void display_3D();

    void on_toolButton_9_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_mappoints_clicked();

    void on_toolButton_setting_clicked();

    void on_toolButton_13_clicked();

    void on_toolButton_12_clicked();

    void on_toolButton_14_clicked();

    void on_toolButton_mappoints_send_clicked();

private:
    Ui::MainWindow *ui;
    Gyroscopeview *DISPLAY_gyroscope;
    Magview *DISPLAY_mg;
    Signalchoose *signal_choose;
    QWebChannel *m_webChannel;
    Document *m_jsContext;
    Setpoint *setpoint;
    Setting *protocolsetting;
    Database *database;

};

#endif // MAINWINDOW_H
