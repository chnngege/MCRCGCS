#include "setpoint.h"
#include "ui_setpoint.h"


Setpoint::Setpoint(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Setpoint)
{
    ui->setupUi(this);
    LastPoint=QPoint(0,0);
}

Setpoint::~Setpoint()
{
    delete ui;
}

void Setpoint::mousePressEvent(QMouseEvent *event)
{
    LastPoint = NewPoint;

    if(event->button() == Qt::LeftButton)
    {
        NewPoint = event->pos();
    }
    repaint();
}


void Setpoint::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    if(LastPoint != QPoint(0,0)){
        QRect rect(LastPoint,NewPoint);
        painter.drawRect(rect);
    }

}
