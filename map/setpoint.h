#ifndef MAPPOINT_H
#define MAPPOINT_H

#include <QWidget>
#include <QtGui>
#include <QPoint>
#include <QPainter>
#include <QMouseEvent>

namespace Ui {
class Setpoint;
}


class Setpoint : public QWidget
{
    Q_OBJECT

public:
    explicit Setpoint(QWidget *parent = 0);
    ~Setpoint();

protected:
    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::Setpoint *ui;

private:
    QPoint LastPoint;
    QPoint NewPoint;
};

#endif // MAPPOINT_H
