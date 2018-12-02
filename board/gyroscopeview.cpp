#include "gyroscopeview.h"
#include "ui_gyroscopeview.h"
#include "iostream"

using namespace std;

Gyroscopeview::Gyroscopeview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Gyroscopeview)
{
    ui->setupUi(this);
    roll = 0.0;
    pitch = 0.0;
}

Gyroscopeview::~Gyroscopeview()
{
    delete ui;
}

void Gyroscopeview::setRoll(int value)
{
    roll = value;
    update();
}


void Gyroscopeview::setPitch(int value)
{
    pitch = value*54/20;
    update();
}

void Gyroscopeview::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    painter.translate(width()/2,height()/2);//translate the coordinate syetem by the given offset

    QRectF target_board(-100,-1000,200,2000);//84 168  START_X, START_Y, WIDTH, HEIGTH
    //QRectF source_board(0.0, 80, 168, altura);
    QImage image_board(":/icons/gyro_mag/zemnebo.bmp");

    QRectF target_scale(-60,-250,120,500);//176
    QImage image_scale(":/icons/gyro_mag/vshk.png");

    QRectF target_greenpointer(-100,-5,202,27);
    QImage image_greenpointer(":/icons/gyro_mag/kren_zad.png");

    QRectF target_yellowpointer(-100,-5,202,27);
    QImage image_yellowpointer(":/icons/gyro_mag/plane.png");

    QRectF target_leftscale(-103,-7,64,104);
    QImage image_leftscle(":/icons/gyro_mag/shkrenal.png");

    QRectF target_rightscale(39,-7,64,104);
    QImage image_rightscle(":/icons/gyro_mag/shkrenar.png");

    painter.translate(0, pitch);
    painter.drawImage(target_board,image_board);
    painter.drawImage(target_scale, image_scale);
    painter.drawImage(target_greenpointer, image_greenpointer);
    painter.translate(0, -pitch);

    painter.drawImage(target_leftscale, image_leftscle);
    painter.drawImage(target_rightscale, image_rightscle);

    painter.rotate(-qRound((qreal)roll));//roll
    painter.drawImage(target_yellowpointer, image_yellowpointer);
    painter.rotate(qRound((qreal)roll));//roll

}

void Gyroscopeview::paint_display(int start_x,int start_y,int width,int heigth,int other)
{
    START_X = start_x;
    START_Y = start_y;
    WIDTH = width;
    HEIGTH = heigth;
    OTHER = other;
    update();
}
