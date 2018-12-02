#ifndef FLIGHTPARA_H
#define FLIGHTPARA_H

#include <QDialog>

namespace Ui {
class Flightpara;
}

class Flightpara : public QDialog
{
    Q_OBJECT

public:
    explicit Flightpara(QWidget *parent = nullptr);
    ~Flightpara();

private:
    Ui::Flightpara *ui;
};

#endif // FLIGHTPARA_H
