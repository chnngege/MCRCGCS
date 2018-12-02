#ifndef SIGNALCHOOSE_H
#define SIGNALCHOOSE_H

#include <QDialog>
#include <QComboBox>
#include "wavesetting.h"
#include "QThread"
#include "wavethread.h"

namespace Ui {
class Signalchoose;
}

class Signalchoose : public QDialog
{
    Q_OBJECT

public:
    explicit Signalchoose(QWidget *parent = nullptr);
    ~Signalchoose();
    void fillColorList( QComboBox * combobox );
    void signallist(QComboBox * combobox);
    void  get_color_signal();
    Wavethread *wave_thread;

private slots:
    void on_buttonBox_accepted();
    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_buttonBox_rejected();

private:
    Ui::Signalchoose *ui;    
    int index_signal[3];
    QColor color[3];


};

#endif // SIGNALCHOOSE_H
