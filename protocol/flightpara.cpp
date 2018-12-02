#include "flightpara.h"
#include "ui_flightpara.h"

Flightpara::Flightpara(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Flightpara)
{
    ui->setupUi(this);
}

Flightpara::~Flightpara()
{
    delete ui;
}
