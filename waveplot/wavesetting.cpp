#include "wavesetting.h"

Wavesetting::Wavesetting()
{
    serial_setting = new Serialsetting;
    serial_setting->hide();
}

void Wavesetting::set_ranges(int xmin, int xmax, int ymin, int ymax) {
    _x_min = xmin;
    _x_max = xmax;
    _y_min = ymin;
    _y_max = ymax;
    chart_plot->chart()->axisX()->setRange(_x_min, _x_max);
    chart_plot->chart()->axisY()->setRange(_y_min, _y_max);
}

void Wavesetting::set_axis_names(QString x, QString y) {
    _title_y = y;
    chart_plot->chart()->axisX()->setTitleText(x);
    chart_plot->chart()->axisY()->setTitleText(y);
}

void Wavesetting::append(AP_DATA2GCS_struct sensor_data,WAVE type_series,int currenttime) {

    int dy_max=0,dy_min=0;
    qreal data_plot = 0;
    //init time value
    if(_t_0==0) {
        _t_0 = currenttime;
        _x_min = 0;
        _x_max = 10000;
        chart_plot->chart()->axisX()->setRange(_x_min, _x_max);
    }
    currenttime-=_t_0 ;

    //choose the series
    switch(type_series) {
    case INS_ROLL:
        chart_plot->_series = chart_plot->_series_AP[INS_ROLL];
        data_plot = (qreal)sensor_data.UAV_INS_Attitude[2];
        break;

    case INS_YAW:
        chart_plot->_series = chart_plot->_series_AP[INS_YAW];
        data_plot = (qreal)sensor_data.UAV_INS_Attitude[0];
        break;

    case INS_PITCH:
        chart_plot->_series = chart_plot->_series_AP[INS_PITCH];
        data_plot = (qreal)sensor_data.UAV_INS_Attitude[1];
        break;
    case INS_HEIGHT:
        chart_plot->_series = chart_plot->_series_AP[INS_HEIGHT];
        data_plot = (qreal)sensor_data.UAV_INS_Height;
        break;
    case SET_YAW:
        chart_plot->_series = chart_plot->_series_AP[SET_YAW];
        data_plot = (qreal)sensor_data.UAV_Attitude[0];
        break;
    case SET_ROLL:
        chart_plot->_series = chart_plot->_series_AP[SET_ROLL];
        data_plot = (qreal)sensor_data.UAV_Attitude[2];
        break;
    case SET_PITCH:
        chart_plot->_series = chart_plot->_series_AP[SET_PITCH];
        data_plot = (qreal)sensor_data.UAV_Attitude[1];
        break;
    case SET_HEIGHT:
        chart_plot->_series = chart_plot->_series_AP[SET_HEIGHT];
        data_plot = (qreal)sensor_data.UAV_Height;
        break;
    case GPS_HEIGHT:
        chart_plot->_series = chart_plot->_series_AP[GPS_HEIGHT];
        data_plot = (qreal)sensor_data.UAV_GPS_Height;
        break;
    case GPS_SPEED:
        chart_plot->_series = chart_plot->_series_AP[GPS_SPEED];
        data_plot = (qreal)sensor_data.UAV_GPS_Vel;
        break;
    case GPS_YAW:
        chart_plot->_series = chart_plot->_series_AP[GPS_YAW];
        data_plot = (qreal)sensor_data.UAV_GPS_Yaw;
        break;
    case SPEED_OX:
        chart_plot->_series = chart_plot->_series_AP[SPEED_OX];
        data_plot = (qreal)sensor_data.UAV_BCS_Vel[0];
        break;
    case SPEED_OY:
        chart_plot->_series = chart_plot->_series_AP[SPEED_OY];
        data_plot = (qreal)sensor_data.UAV_BCS_Vel[1];
        break;
    case SPEED_OZ:
        chart_plot->_series = chart_plot->_series_AP[SPEED_OZ];
        data_plot = (qreal)sensor_data.UAV_BCS_Vel[2];
        break;
    }
    //draw wave!!!!!!!!!!!!!!!!!!!!!!
    chart_plot->_series->append(currenttime, data_plot);

/*------------------Move the graph with the data---------------------*/
    if(currenttime >= _x_max - 100) {
        int dx = currenttime - _x_max + 100;
        _x_max += dx;
        //_x_min += dx;
        chart_plot->chart()->axisX()->setRange(_x_min, _x_max);
        while(chart_plot->_series->at(0).x() < _x_min)
            chart_plot->_series->remove(0);
    }

    //first draw wave
    if(flag_chart == 0){
        flag_chart = 1;

        if(data_plot >= _y_max - 20) {
            dy_max = (int)data_plot - (_y_max - 20);
            _y_max += dy_max;
            chart_plot->chart()->axisY()->setRange(_y_min, _y_max);

        } else if(data_plot <= _y_min + 20) {
            dy_min = (_y_min + 20) - (int)data_plot;
            _y_min -= dy_min;
            chart_plot->chart()->axisY()->setRange(_y_min, _y_max);
        }

        if(data_plot > _y_min + 25)  {
            dy_min = (int)data_plot - (_y_min + 25);
            _y_min += dy_min;
            chart_plot->chart()->axisY()->setRange(_y_min, _y_max);
        }
        if(data_plot < _y_max - 25)  {
            dy_max = (_y_max - 25) - (int)data_plot;
            _y_max -= dy_max;
            chart_plot->chart()->axisY()->setRange(_y_min, _y_max);
        }
    }
    // not first draw wave
    // Rescale y axis if values goes too high
    if(data_plot >= _y_max - 20) {
        dy_max = (int)data_plot - (_y_max - 20);
        _y_max += dy_max;
        chart_plot->chart()->axisY()->setRange(_y_min, _y_max);

    } else if(data_plot <= _y_min + 20) {
        dy_min = (_y_min + 20) - (int)data_plot;
        _y_min -= dy_min;
        chart_plot->chart()->axisY()->setRange(_y_min, _y_max);
    }
}

void Wavesetting::clear_data() {
    chart_plot->_series_AP[INS_ROLL]->clear();
    chart_plot->_series_AP[INS_PITCH]->clear();
    chart_plot->_series_AP[INS_YAW]->clear();
    chart_plot->_series_AP[INS_HEIGHT]->clear();
    chart_plot->_series_AP[SET_YAW]->clear();
    chart_plot->_series_AP[SET_ROLL]->clear();
    chart_plot->_series_AP[SET_PITCH]->clear();
    chart_plot->_series_AP[SET_HEIGHT]->clear();
    chart_plot->_series_AP[GPS_HEIGHT]->clear();
    chart_plot->_series_AP[GPS_SPEED]->clear();
    chart_plot->_series_AP[GPS_YAW]->clear();
    chart_plot->_series_AP[SPEED_OX]->clear();
    chart_plot->_series_AP[SPEED_OY]->clear();
    chart_plot->_series_AP[SPEED_OZ]->clear();
    _t_0 = 0;//restart draw
}
