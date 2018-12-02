#include "wavethread.h"

Wavethread::Wavethread()
{
    plot_thread = new Wavesetting;
    sensordatabase = new Database;
    //connect(plot_thread->serial_setting->serial_thread,SIGNAL(data_progressfinished()),this,SLOT(addpoints_color_signal()));
    //connect(plot_thread->serial_setting->serial_thread, SIGNAL(data_progressfinished()), this, SLOT(emit_addpoints()));
}

void Wavethread::run()
{
   connect(this,SIGNAL(addpoints_thread()),this,SLOT(addpoints_color_signal()));
}

void Wavethread::disconnect_thread()
{
    disconnect(plot_thread->serial_setting->serial_thread, SIGNAL(data_progressfinished()), this, SLOT(emit_addpoints()));
}

void Wavethread::connect_thread()
{
    connect(plot_thread->serial_setting->serial_thread, SIGNAL(data_progressfinished()), this, SLOT(emit_addpoints()));
}
void Wavethread::emit_addpoints()
{
    emit(addpoints_thread());
}
//draw points of waveforms
void Wavethread::addpoints_color_signal()
{
    for(int i=0;i<3;i++){
        if(check_flag[i]){//只有当该信号的复选框选择了，才绘制波形
            WAVE index = (WAVE)index_signal[i];
            plot_thread->append(AP_DATA2GCS,index);
        }
    }
}


//set color of signal
void Wavethread::set_color(int index[3],QColor color[3])
{
    for(int i=0;i<3;i++){
        index_signal[i] = index[i];
    }
    //define three brushes
    QPen pen_wave[3];
    pen_wave[0] = plot_thread->chart_plot->_series_AP[index[0]]->pen();
    pen_wave[1] = plot_thread->chart_plot->_series_AP[index[1]]->pen();
    pen_wave[2] = plot_thread->chart_plot->_series_AP[index[2]]->pen();
    //setting of pen
    pen_wave[0].setColor(color[0]);
    pen_wave[1].setColor(color[1]);
    pen_wave[2].setColor(color[2]);
    //set color for three signal
    for(int i=0;i<3;i++){
        plot_thread->chart_plot->_series_AP[index[i]]->setPen(pen_wave[i]);
    }
}


