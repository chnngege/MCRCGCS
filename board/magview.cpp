#include "magview.h"
#include "ui_magview.h"

Magview::Magview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Magview)
{
    ui->setupUi(this);
    yaw = 0.0;
}

Magview::~Magview()
{
    delete ui;
}


void Magview::setmagyaw(const qreal &value)
{
    yaw = value;
    update();//更新窗口部件
}

void Magview::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.translate(width()/2,height()/2);

    QRectF target_magscale(-100,-102,202,202);//START_X, START_Y, WIDTH, HEIGTH
    QImage image_magscale(":/icons/gyro_mag/Kompass_back.png");
    QRectF target_greenpointer(-7,-72,15,110);
    QImage image_greenpointer(":/icons/gyro_mag/ZadanniyKurs.png");
    QRectF target_whitepointer(-20,-62,41,120);
    QImage image_whitepointer(":/icons/gyro_mag/kompass_plane.png");
    QRectF target_centerpoint(-7,-8,16,16);
    QImage image_centerpoint(":/icons/gyro_mag/point.png");
    QRectF target_needle(-9,-80,20,19);
    QImage image_needle(":/icons/gyro_mag/strelka.png");
    painter.drawImage(target_magscale,image_magscale);
    painter.drawImage(target_greenpointer, image_greenpointer);
    painter.rotate(-qRound((qreal)yaw));
    painter.drawImage(target_whitepointer, image_whitepointer);
    painter.drawImage(target_needle, image_needle);
    painter.rotate(qRound((qreal)yaw));
    painter.drawImage(target_centerpoint, image_centerpoint);

}



void Magview::set_mag(int start_x,int start_y,int width,int heigth,int other)
{
    START_X = start_x;
    START_Y = start_y;
    WIDTH = width;
    HEIGTH = heigth;
    OTHER = other;
    update();
}
