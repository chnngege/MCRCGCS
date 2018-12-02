#ifndef WAVEVIEW_H
#define WAVEVIEW_H

#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include "serial/packet.h"



using namespace QtCharts;

class Waveview : public QChartView {
    Q_OBJECT
public:
    Waveview(QWidget* parent = 0);
    void wave_init();
    QLineSeries *_series_AP[14];
    QLineSeries *_series;

private:

};

#endif
