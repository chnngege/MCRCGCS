#ifndef WAVESETTING_H
#define WAVESETTING_H
#include <QThread>
#include "serial/serialsetting.h"
#include "serial/serialthread.h"
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include "serial/packet.h"
#include "waveview.h"

using namespace QtCharts;

class Wavesetting : public QThread
{
    Q_OBJECT
public:
    Wavesetting();
    void setcolor();
    Waveview *chart_plot;
    Serialsetting *serial_setting;
signals:
    void visual_3D();

public slots:
    void append(AP_DATA2GCS_struct x,WAVE type_series,int currenttime = (QTime::currentTime().msecsSinceStartOfDay()));
    void set_axis_names(QString x, QString y);
    void set_ranges(int xmin, int xmax, int ymin, int ymax);
    void clear_data();

private:
    int _x_min = 0;
    int _x_max = 10000;
    int _y_min = -90;
    int _y_max = 90;
    int _t_0 = 0;
    int flag_chart = 0;//first draw wave
    QString _title_y;

};

#endif // Wavesetting_H
