#ifndef WAVETHREAD_H
#define WAVETHREAD_H
#include "QThread"
#include "wavesetting.h"
#include "serial/packet.h"
#include "database/database.h"

class Wavethread : public QThread
{
    Q_OBJECT
public:
    Wavethread();
    void set_color(int index_signal[3],QColor color[3]);
    void connect_thread();
    void disconnect_thread();
    Wavesetting *plot_thread;
    Database *sensordatabase;
protected:
    void run();

signals:
    void addpoints_thread();

public slots:
    void addpoints_color_signal();
    void emit_addpoints();

private:
    int index_signal[3];//save index of choosed sigal

};

#endif // WAVETHREAD_H
