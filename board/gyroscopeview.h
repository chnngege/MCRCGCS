#ifndef HORIZONTE_ARTIFICIAL_H
#define HORIZONTE_ARTIFICIAL_H

#include <QWidget>
#include <QtGui>


namespace Ui {
class Gyroscopeview;
}

class Gyroscopeview : public QWidget
{
    Q_OBJECT

public:
    explicit Gyroscopeview(QWidget *parent = 0);
    ~Gyroscopeview();
    void setRoll(int value);
    void setPitch(int value);

public slots:
    void paint_display(int start_x,int start_y,int width,int heigth,int other);


private:
    Ui::Gyroscopeview *ui;
protected:
    void paintEvent(QPaintEvent *e);
private:
    qreal roll;
    qreal pitch;
    int value_set;
    int START_X,START_Y,WIDTH,HEIGTH,OTHER;
};

#endif // HORIZONTE_ARTIFICIAL_H
