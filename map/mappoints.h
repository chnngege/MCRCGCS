#ifndef MAPPOINTS_H
#define MAPPOINTS_H

#include <QDialog>
#include <QtGui>
#include "serial/packet.h"

namespace Ui {
class Mappoints;
}

class Mappoints : public QDialog
{
    Q_OBJECT

public:
    explicit Mappoints(QWidget *parent = nullptr);
    ~Mappoints();
    void display_savepoints(double points[100][2],double distance[30],quint8 num_points);
    void show_hide();
    void clear_init(quint8 nums);
    void readvaluefromui(quint8 nums);
    
private slots:
    void on_toolButton_exit_clicked();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    Ui::Mappoints *ui;
    QPoint last;
    QString ARRAY_INITIAL_VALUE[5] = {"17","0","0","0","0"};

};

#endif // MAPPOINTS_H
