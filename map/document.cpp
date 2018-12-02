#include "document.h"

struct Trajectory_Planning MAP_PLANNING;//地图航点轨迹规划的结构体

Document::Document(QObject *parent) :
      QObject(parent) {
    mappoints = new Mappoints;
}

void Document::onMsg(const QString &msg1,const QString& msg2)
{
    emit recvdMsg(msg1,msg2);
}
void Document::onMsg_newpoint(const QString &msg1,const QString& msg2,quint8 index_point)
{
    emit recvdMsg_newpoint(msg1,msg2,index_point);
}
void Document::sendMsg(QWebEnginePage* page, const QString& msg)
{
    page->runJavaScript(QString("recvMessage('%1');").arg(msg));
}

void Document::savepoints(double lng,double lat)
{  
    MAP_PLANNING.lnglat_array[MAP_PLANNING.num_points][0] = lng;
    MAP_PLANNING.lnglat_array[MAP_PLANNING.num_points][1] = lat;
    MAP_PLANNING.num_points = MAP_PLANNING.num_points + 1;//the number of points

    Calculated_distance(MAP_PLANNING.lnglat_array,MAP_PLANNING.num_points);
    mappoints->display_savepoints(MAP_PLANNING.lnglat_array,MAP_PLANNING.distance,MAP_PLANNING.num_points);
}

void Document::changepoints(double lng,double lat,quint8 index_point)
{
    MAP_PLANNING.lnglat_array[index_point-1][1] = lng;//序号变成数组索引要-1
    MAP_PLANNING.lnglat_array[index_point-1][0] = lat;
    Calculated_distance(MAP_PLANNING.lnglat_array,MAP_PLANNING.num_points);
    mappoints->display_savepoints(MAP_PLANNING.lnglat_array,MAP_PLANNING.distance,MAP_PLANNING.num_points);
}

void Document::uiclear_init()
{
    mappoints->clear_init(MAP_PLANNING.num_points);
    MAP_PLANNING.num_points = 0;
    MAP_PLANNING.num_points = 0;
}

void Document::Calculated_distance(double points[30][2],quint8 nums)
{
    MAP_PLANNING.distance[0] = 0;
    for(quint8 i = 1;i < nums;i++)
    {
        MAP_PLANNING.distance[i] = MAP_PLANNING.distance[i-1]
                + getFlatternDistance(points[i-1][1],points[i-1][0],points[i][1],points[i][0]);
    }
}

double Document::getRad(double d){
    return d*PI/180.0;
}

double Document::getFlatternDistance(double lat1,double lng1,double lat2,double lng2)
{
    double f = getRad((lat1 + lat2)/2);
    double g = getRad((lat1 - lat2)/2);
    double l = getRad((lng1 - lng2)/2);
    double sg = sin(g);
    double sl = sin(l);
    double sf = sin(f);
    double s,c,w,r,d,h1,h2;
    double a = EARTH_RADIUS;
    double fl = 1/298.257;

    sg = sg*sg;
    sl = sl*sl;
    sf = sf*sf;
    s = sg*(1-sl) + (1-sf)*sl;
    c = (1-sg)*(1-sl) + sf*sl;

    w = atan(sqrt(s/c));
    r = sqrt(s*c)/w;
    d = 2*w*a;
    h1 = (3*r -1)/2/c;
    h2 = (3*r +1)/2/s;

    return d*(1 + fl*(h1*sf*(1-sg) - h2*(1-sf)*sg));
}

