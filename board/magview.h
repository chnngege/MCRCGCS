#ifndef MAGVIEW_H
#define MAGVIEW_H

#include <QWidget>
#include <QWidget>
#include <QtGui>


namespace Ui {
class Magview;
}

class Magview : public QWidget
{
    Q_OBJECT

public:
    explicit Magview(QWidget *parent = 0);
    ~Magview();

    void setmagyaw(const qreal &value);

protected:
    void paintEvent(QPaintEvent *);

public:
    void set_mag(int start_x,int start_y,int width,int heigth,int other);

private:
    Ui::Magview *ui;

    qreal yaw;

    int START_X,START_Y,WIDTH,HEIGTH,OTHER;
};

#endif // MAGVIEW_H
