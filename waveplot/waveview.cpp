#include "waveview.h"

Waveview::Waveview(QWidget* parent) : QChartView(parent) {
    quint8 number=0;
    while(number < WAVENUMBER){
        _series_AP[number] = new QLineSeries;
        number++;
    }
    _series = new QLineSeries;
    wave_init();
}

void Waveview::wave_init()
{
    WAVE wave_name = INS_YAW;
    while(wave_name < WAVENUMBER){
        _series_AP[wave_name]->setUseOpenGL(true);//OpenGL acceleration : more fast
        wave_name = (WAVE)(wave_name + 1);
    }
    wave_name = INS_YAW;
    //OpenGL acceleration : more fast
    _series->setUseOpenGL(true);
   // QChartView *chartview = new QChartView;
    while(wave_name < WAVENUMBER){
        chart()->addSeries(_series_AP[wave_name]);
        wave_name = (WAVE)(wave_name + 1);
    }
    wave_name = INS_YAW;
    chart()->setAnimationOptions(QChart::NoAnimation);
    setRenderHint(QPainter::Antialiasing);//set fan zou yang
    QValueAxis *axisX = new QValueAxis;
    axisX->setLabelFormat("%u");   //设置刻度的格式
    axisX->setGridLineVisible(true);   //网格线可见
    axisX->setTickCount(2);       //设置多少格
    axisX->setMinorTickCount(3);   //设置每格小刻度线的数目
    while(wave_name < WAVENUMBER){
        chart()->setAxisX(axisX, _series_AP[wave_name]);
        wave_name = (WAVE)(wave_name + 1);
    }
    wave_name = INS_YAW;
    QValueAxis *axisY = new QValueAxis;
    axisY->setLabelFormat("%g");   //设置刻度的格式
    axisY->setGridLineVisible(true);   //网格线可见
    axisY->setTickCount(2);       //设置多少格
    axisY->setMinorTickCount(5);   //设置每格小刻度线的数目
    while(wave_name < WAVENUMBER){
        chart()->setAxisY(axisY, _series_AP[wave_name]);
        wave_name = (WAVE)(wave_name + 1);
    }
    //chart()->createDefaultAxes();
    chart()->axisX()->setGridLineVisible(false);
    chart()->axisY()->setGridLineVisible(false);
    chart()->axisX()->setRange(0, 10000);
    chart()->axisY()->setRange(-90, 90);
    chart()->legend()->hide();
    chart()->setTheme(QChart::ChartThemeDark);//switch theme

    // Important to avoid our graph to look weird when optimizing memory usage later
    disconnect(_series, SIGNAL(pointRemoved(int)), this, SLOT(update()));
}
