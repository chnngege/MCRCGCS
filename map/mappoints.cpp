#include "mappoints.h"
#include "ui_mappoints.h"

Mappoints::Mappoints(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mappoints)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
    Qt::WindowFlags flags = this->windowFlags();
    this->setWindowFlags(flags | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint);

}

Mappoints::~Mappoints()
{
    delete ui;
}

void Mappoints::mousePressEvent(QMouseEvent *e)
{
    last = e->globalPos();
}

void Mappoints::mouseMoveEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx,y()+dy);
}

void Mappoints::mouseReleaseEvent(QMouseEvent *e)
{
    int dx = e->globalX()-last.x();
    int dy = e->globalY()-last.y();

    last = e->globalPos();
    move(x()+dx,y()+dy);
}

void Mappoints::display_savepoints(double points[30][2],double distance[30],quint8 num_points)
{
    if(num_points >= 1){
        ui->label_lng1->setText(QString::number(points[0][0],'f',6));
        ui->label_lat1->setText(QString::number(points[0][1],'f',6));
        ui->label_d1->setText(QString::number(distance[0],'f',2));
        ui->lineEdit_m1->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v1->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h1->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p1->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp1->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 2){
        ui->label_lng2->setText(QString::number(points[1][0],'f',6));
        ui->label_lat2->setText(QString::number(points[1][1],'f',6));
        ui->label_d2->setText(QString::number(distance[1],'f',2));
        ui->lineEdit_m2->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v2->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h2->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p2->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp2->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 3){
        ui->label_lng3->setText(QString::number(points[2][0],'f',6));
        ui->label_lat3->setText(QString::number(points[2][1],'f',6));
        ui->label_d3->setText(QString::number(distance[2],'f',2));
        ui->lineEdit_m3->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v3->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h3->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p3->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp3->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 4){
        ui->label_lng4->setText(QString::number(points[3][0],'f',6));
        ui->label_lat4->setText(QString::number(points[3][1],'f',6));
        ui->label_d4->setText(QString::number(distance[3],'f',2));
        ui->lineEdit_m4->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v4->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h4->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p4->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp4->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 5){
        ui->label_lng5->setText(QString::number(points[4][0],'f',6));
        ui->label_lat5->setText(QString::number(points[4][1],'f',6));
        ui->label_d5->setText(QString::number(distance[4],'f',2));
        ui->lineEdit_m5->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v5->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h5->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p5->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp5->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 6){
        ui->label_lng6->setText(QString::number(points[5][0],'f',6));
        ui->label_lat6->setText(QString::number(points[5][1],'f',6));
        ui->label_d6->setText(QString::number(distance[5],'f',2));
        ui->lineEdit_m6->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v6->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h6->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p6->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp6->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 7){
        ui->label_lng7->setText(QString::number(points[6][0],'f',6));
        ui->label_lat7->setText(QString::number(points[6][1],'f',6));
        ui->label_d7->setText(QString::number(distance[6],'f',2));
        ui->lineEdit_m7->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v7->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h7->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p7->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp7->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 8){
        ui->label_lng8->setText(QString::number(points[7][0],'f',6));
        ui->label_lat8->setText(QString::number(points[7][1],'f',6));
        ui->label_d8->setText(QString::number(distance[7],'f',2));
        ui->lineEdit_m8->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v8->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h8->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p8->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp8->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 9){
        ui->label_lng9->setText(QString::number(points[8][0],'f',6));
        ui->label_lat9->setText(QString::number(points[8][1],'f',6));
        ui->label_d9->setText(QString::number(distance[8],'f',2));
        ui->lineEdit_m9->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v9->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h9->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p9->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp9->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 10){
        ui->label_lng10->setText(QString::number(points[9][0],'f',6));
        ui->label_lat10->setText(QString::number(points[9][1],'f',6));
        ui->label_d10->setText(QString::number(distance[9],'f',2));
        ui->lineEdit_m10->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v10->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h10->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p10->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp10->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 11){
        ui->label_lng11->setText(QString::number(points[10][0],'f',6));
        ui->label_lat11->setText(QString::number(points[10][1],'f',6));
        ui->label_d11->setText(QString::number(distance[10],'f',2));
        ui->lineEdit_m11->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v11->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h11->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p11->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp11->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 12){
        ui->label_lng12->setText(QString::number(points[11][0],'f',6));
        ui->label_lat12->setText(QString::number(points[11][1],'f',6));
        ui->label_d12->setText(QString::number(distance[11],'f',2));
        ui->lineEdit_m12->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v12->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h12->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p12->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp12->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 13){
        ui->label_lng13->setText(QString::number(points[12][0],'f',6));
        ui->label_lat13->setText(QString::number(points[12][1],'f',6));
        ui->label_d13->setText(QString::number(distance[12],'f',2));
        ui->lineEdit_m13->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v13->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h13->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p13->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp13->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 14){
        ui->label_lng14->setText(QString::number(points[13][0],'f',6));
        ui->label_lat14->setText(QString::number(points[13][1],'f',6));
        ui->label_d14->setText(QString::number(distance[13],'f',2));
        ui->lineEdit_m14->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v14->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h14->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p14->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp14->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 15){
        ui->label_lng15->setText(QString::number(points[14][0],'f',6));
        ui->label_lat15->setText(QString::number(points[14][1],'f',6));
        ui->label_d15->setText(QString::number(distance[14],'f',2));
        ui->lineEdit_m15->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v15->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h15->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p15->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp15->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 16){
        ui->label_lng16->setText(QString::number(points[15][0],'f',6));
        ui->label_lat16->setText(QString::number(points[15][1],'f',6));
        ui->label_d16->setText(QString::number(distance[15],'f',2));
        ui->lineEdit_m16->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v16->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h16->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p16->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp16->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 17){
        ui->label_lng17->setText(QString::number(points[16][0],'f',6));
        ui->label_lat17->setText(QString::number(points[16][1],'f',6));
        ui->label_d17->setText(QString::number(distance[16],'f',2));
        ui->lineEdit_m17->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v17->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h17->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p17->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp17->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 18){
        ui->label_lng18->setText(QString::number(points[17][0],'f',6));
        ui->label_lat18->setText(QString::number(points[17][1],'f',6));
        ui->label_d18->setText(QString::number(distance[17],'f',2));
        ui->lineEdit_m18->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v18->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h18->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p18->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp18->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 19){
        ui->label_lng19->setText(QString::number(points[18][0],'f',6));
        ui->label_lat19->setText(QString::number(points[18][1],'f',6));
        ui->label_d19->setText(QString::number(distance[18],'f',2));
        ui->lineEdit_m19->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v19->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h19->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p19->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp19->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 20){
        ui->label_lng20->setText(QString::number(points[19][0],'f',6));
        ui->label_lat20->setText(QString::number(points[19][1],'f',6));
        ui->label_d20->setText(QString::number(distance[19],'f',2));
        ui->lineEdit_m20->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v20->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h20->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p20->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp20->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 21){
        ui->label_lng21->setText(QString::number(points[20][0],'f',6));
        ui->label_lat21->setText(QString::number(points[20][1],'f',6));
        ui->label_d21->setText(QString::number(distance[20],'f',2));
        ui->lineEdit_m21->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v21->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h21->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p21->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp21->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 22){
        ui->label_lng22->setText(QString::number(points[21][0],'f',6));
        ui->label_lat22->setText(QString::number(points[21][1],'f',6));
        ui->label_d1->setText(QString::number(distance[21],'f',2));
        ui->lineEdit_m22->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v22->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h22->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p22->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp22->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 23){
        ui->label_lng23->setText(QString::number(points[22][0],'f',6));
        ui->label_lat23->setText(QString::number(points[22][1],'f',6));
        ui->label_d23->setText(QString::number(distance[22],'f',2));
        ui->lineEdit_m23->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v23->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h23->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p23->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp23->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 24){
        ui->label_lng24->setText(QString::number(points[23][0],'f',6));
        ui->label_lat24->setText(QString::number(points[23][1],'f',6));
        ui->label_d24->setText(QString::number(distance[23],'f',2));
        ui->lineEdit_m24->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v24->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h24->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p24->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp24->setText(ARRAY_INITIAL_VALUE[4]);
    }
    if(num_points >= 25){
        ui->label_lng25->setText(QString::number(points[24][0],'f',6));
        ui->label_lat25->setText(QString::number(points[24][1],'f',6));
        ui->label_d25->setText(QString::number(distance[24],'f',2));
        ui->lineEdit_m25->setText(ARRAY_INITIAL_VALUE[0]);
        ui->lineEdit_v25->setText(ARRAY_INITIAL_VALUE[1]);
        ui->lineEdit_h25->setText(ARRAY_INITIAL_VALUE[2]);
        ui->lineEdit_p25->setText(ARRAY_INITIAL_VALUE[3]);
        ui->lineEdit_pp25->setText(ARRAY_INITIAL_VALUE[4]);
    }
}

void Mappoints::clear_init(quint8 nums)
{
    if(nums >= 1){
        ui->lineEdit_m1->setText("");
        ui->lineEdit_v1->setText("");
        ui->lineEdit_h1->setText("");
        ui->label_lng1->setText("");
        ui->label_lat1->setText("");
        ui->lineEdit_p1->setText("");
        ui->lineEdit_pp1->setText("");
        ui->label_d1->setText("");
    }
    if(nums >= 2){
        ui->lineEdit_m2->setText("");
        ui->lineEdit_v2->setText("");
        ui->lineEdit_h2->setText("");
        ui->label_lng2->setText("");
        ui->label_lat2->setText("");
        ui->lineEdit_p2->setText("");
        ui->lineEdit_pp2->setText("");
        ui->label_d2->setText("");
    }
    if(nums >= 3){
        ui->lineEdit_m3->setText("");
        ui->lineEdit_v3->setText("");
        ui->lineEdit_h3->setText("");
        ui->label_lng3->setText("");
        ui->label_lat3->setText("");
        ui->lineEdit_p3->setText("");
        ui->lineEdit_pp3->setText("");
        ui->label_d3->setText("");
    }
    if(nums >= 4){
        ui->lineEdit_m4->setText("");
        ui->lineEdit_v4->setText("");
        ui->lineEdit_h4->setText("");
        ui->label_lng4->setText("");
        ui->label_lat4->setText("");
        ui->lineEdit_p4->setText("");
        ui->lineEdit_pp4->setText("");
        ui->label_d4->setText("");
    }
    if(nums >= 5){
        ui->lineEdit_m5->setText("");
        ui->lineEdit_v5->setText("");
        ui->lineEdit_h5->setText("");
        ui->label_lng5->setText("");
        ui->label_lat5->setText("");
        ui->lineEdit_p5->setText("");
        ui->lineEdit_pp5->setText("");
        ui->label_d5->setText("");
    }
    if(nums >= 6){
        ui->lineEdit_m6->setText("");
        ui->lineEdit_v6->setText("");
        ui->lineEdit_h6->setText("");
        ui->label_lng6->setText("");
        ui->label_lat6->setText("");
        ui->lineEdit_p6->setText("");
        ui->lineEdit_pp6->setText("");
        ui->label_d6->setText("");
    }
    if(nums >= 7){
        ui->lineEdit_m7->setText("");
        ui->lineEdit_v7->setText("");
        ui->lineEdit_h7->setText("");
        ui->label_lng7->setText("");
        ui->label_lat7->setText("");
        ui->lineEdit_p7->setText("");
        ui->lineEdit_pp7->setText("");
        ui->label_d7->setText("");
    }
    if(nums >= 8){
        ui->lineEdit_m8->setText("");
        ui->lineEdit_v8->setText("");
        ui->lineEdit_h8->setText("");
        ui->label_lng8->setText("");
        ui->label_lat8->setText("");
        ui->lineEdit_p8->setText("");
        ui->lineEdit_pp8->setText("");
        ui->label_d8->setText("");
    }
    if(nums >= 9){
        ui->lineEdit_m9->setText("");
        ui->lineEdit_v9->setText("");
        ui->lineEdit_h9->setText("");
        ui->label_lng9->setText("");
        ui->label_lat9->setText("");
        ui->lineEdit_p9->setText("");
        ui->lineEdit_pp9->setText("");
        ui->label_d9->setText("");
    }
    if(nums >= 10){
        ui->lineEdit_m10->setText("");
        ui->lineEdit_v10->setText("");
        ui->lineEdit_h10->setText("");
        ui->label_lng10->setText("");
        ui->label_lat10->setText("");
        ui->lineEdit_p10->setText("");
        ui->lineEdit_pp10->setText("");
        ui->label_d10->setText("");
    }
    if(nums >= 11){
        ui->lineEdit_m11->setText("");
        ui->lineEdit_v11->setText("");
        ui->lineEdit_h11->setText("");
        ui->label_lng11->setText("");
        ui->label_lat11->setText("");
        ui->lineEdit_p11->setText("");
        ui->lineEdit_pp11->setText("");
        ui->label_d11->setText("");
    }
    if(nums >= 12){
        ui->lineEdit_m12->setText("");
        ui->lineEdit_v12->setText("");
        ui->lineEdit_h12->setText("");
        ui->label_lng12->setText("");
        ui->label_lat12->setText("");
        ui->lineEdit_p12->setText("");
        ui->lineEdit_pp12->setText("");
        ui->label_d12->setText("");
    }
    if(nums >= 13){
        ui->lineEdit_m13->setText("");
        ui->lineEdit_v13->setText("");
        ui->lineEdit_h13->setText("");
        ui->label_lng13->setText("");
        ui->label_lat13->setText("");
        ui->lineEdit_p13->setText("");
        ui->lineEdit_pp13->setText("");
        ui->label_d13->setText("");
    }
    if(nums >= 14){
        ui->lineEdit_m14->setText("");
        ui->lineEdit_v14->setText("");
        ui->lineEdit_h14->setText("");
        ui->label_lng14->setText("");
        ui->label_lat14->setText("");
        ui->lineEdit_p14->setText("");
        ui->lineEdit_pp14->setText("");
        ui->label_d14->setText("");
    }
    if(nums >= 15){
        ui->lineEdit_m15->setText("");
        ui->lineEdit_v15->setText("");
        ui->lineEdit_h15->setText("");
        ui->label_lng15->setText("");
        ui->label_lat15->setText("");
        ui->lineEdit_p15->setText("");
        ui->lineEdit_pp15->setText("");
        ui->label_d15->setText("");
    }
    if(nums >= 16){
        ui->lineEdit_m16->setText("");
        ui->lineEdit_v16->setText("");
        ui->lineEdit_h16->setText("");
        ui->label_lng16->setText("");
        ui->label_lat16->setText("");
        ui->lineEdit_p16->setText("");
        ui->lineEdit_pp16->setText("");
        ui->label_d16->setText("");
    }
    if(nums >= 17){
        ui->lineEdit_m17->setText("");
        ui->lineEdit_v17->setText("");
        ui->lineEdit_h17->setText("");
        ui->label_lng17->setText("");
        ui->label_lat17->setText("");
        ui->lineEdit_p17->setText("");
        ui->lineEdit_pp17->setText("");
        ui->label_d17->setText("");
    }
    if(nums >= 18){
        ui->lineEdit_m18->setText("");
        ui->lineEdit_v18->setText("");
        ui->lineEdit_h18->setText("");
        ui->label_lng18->setText("");
        ui->label_lat18->setText("");
        ui->lineEdit_p18->setText("");
        ui->lineEdit_pp18->setText("");
        ui->label_d18->setText("");
    }
    if(nums >= 19){
        ui->lineEdit_m19->setText("");
        ui->lineEdit_v19->setText("");
        ui->lineEdit_h19->setText("");
        ui->label_lng19->setText("");
        ui->label_lat19->setText("");
        ui->lineEdit_p19->setText("");
        ui->lineEdit_pp19->setText("");
        ui->label_d19->setText("");
    }
    if(nums >= 20){
        ui->lineEdit_m20->setText("");
        ui->lineEdit_v20->setText("");
        ui->lineEdit_h20->setText("");
        ui->label_lng20->setText("");
        ui->label_lat20->setText("");
        ui->lineEdit_p20->setText("");
        ui->lineEdit_pp20->setText("");
        ui->label_d20->setText("");
    }
    if(nums >= 21){
        ui->lineEdit_m21->setText("");
        ui->lineEdit_v21->setText("");
        ui->lineEdit_h21->setText("");
        ui->label_lng21->setText("");
        ui->label_lat21->setText("");
        ui->lineEdit_p21->setText("");
        ui->lineEdit_pp21->setText("");
        ui->label_d21->setText("");
    }
    if(nums >= 22){
        ui->lineEdit_m22->setText("");
        ui->lineEdit_v22->setText("");
        ui->lineEdit_h22->setText("");
        ui->label_lng22->setText("");
        ui->label_lat22->setText("");
        ui->lineEdit_p22->setText("");
        ui->lineEdit_pp22->setText("");
        ui->label_d22->setText("");
    }
    if(nums >= 23){
        ui->lineEdit_m23->setText("");
        ui->lineEdit_v23->setText("");
        ui->lineEdit_h23->setText("");
        ui->label_lng23->setText("");
        ui->label_lat23->setText("");
        ui->lineEdit_p23->setText("");
        ui->lineEdit_pp23->setText("");
        ui->label_d23->setText("");
    }
    if(nums >= 24){
        ui->lineEdit_m24->setText("");
        ui->lineEdit_v24->setText("");
        ui->lineEdit_h24->setText("");
        ui->label_lng24->setText("");
        ui->label_lat24->setText("");
        ui->lineEdit_p24->setText("");
        ui->lineEdit_pp24->setText("");
        ui->label_d24->setText("");
    }
    if(nums >= 25){
        ui->lineEdit_m25->setText("");
        ui->lineEdit_v25->setText("");
        ui->lineEdit_h25->setText("");
        ui->label_lng25->setText("");
        ui->label_lat25->setText("");
        ui->lineEdit_p25->setText("");
        ui->lineEdit_pp25->setText("");
        ui->label_d25->setText("");
    }
}

void Mappoints::readvaluefromui(quint8 nums)
{
    if(nums >= 1){
        MAP_PLANNING.map_m[0] = ui->lineEdit_m1->text().toDouble();
        MAP_PLANNING.map_v[0] = ui->lineEdit_v1->text().toDouble();
        MAP_PLANNING.map_h[0] = ui->lineEdit_h1->text().toDouble();
        MAP_PLANNING.map_p[0] = ui->lineEdit_p1->text().toDouble();
        MAP_PLANNING.map_pp[0] = ui->lineEdit_pp1->text().toDouble();
    }
    if(nums >= 2){
        MAP_PLANNING.map_m[1] = ui->lineEdit_m2->text().toDouble();
        MAP_PLANNING.map_v[1] = ui->lineEdit_v2->text().toDouble();
        MAP_PLANNING.map_h[1] = ui->lineEdit_h2->text().toDouble();
        MAP_PLANNING.map_p[1] = ui->lineEdit_p2->text().toDouble();
        MAP_PLANNING.map_pp[1] = ui->lineEdit_pp2->text().toDouble();
    }
    if(nums >= 3){
        MAP_PLANNING.map_m[2] = ui->lineEdit_m3->text().toDouble();
        MAP_PLANNING.map_v[2] = ui->lineEdit_v3->text().toDouble();
        MAP_PLANNING.map_h[2] = ui->lineEdit_h3->text().toDouble();
        MAP_PLANNING.map_p[2] = ui->lineEdit_p3->text().toDouble();
        MAP_PLANNING.map_pp[2] = ui->lineEdit_pp3->text().toDouble();
    }
    if(nums >= 4){
        MAP_PLANNING.map_m[3] = ui->lineEdit_m4->text().toDouble();
        MAP_PLANNING.map_v[3] = ui->lineEdit_v4->text().toDouble();
        MAP_PLANNING.map_h[3] = ui->lineEdit_h4->text().toDouble();
        MAP_PLANNING.map_p[3] = ui->lineEdit_p4->text().toDouble();
        MAP_PLANNING.map_pp[3] = ui->lineEdit_pp4->text().toDouble();
    }
    if(nums >= 5){
        MAP_PLANNING.map_m[4] = ui->lineEdit_m5->text().toDouble();
        MAP_PLANNING.map_v[4] = ui->lineEdit_v5->text().toDouble();
        MAP_PLANNING.map_h[4] = ui->lineEdit_h5->text().toDouble();
        MAP_PLANNING.map_p[4] = ui->lineEdit_p5->text().toDouble();
        MAP_PLANNING.map_pp[4] = ui->lineEdit_pp5->text().toDouble();
    }
    if(nums >= 6){
        MAP_PLANNING.map_m[5] = ui->lineEdit_m6->text().toDouble();
        MAP_PLANNING.map_v[5] = ui->lineEdit_v6->text().toDouble();
        MAP_PLANNING.map_h[5] = ui->lineEdit_h6->text().toDouble();
        MAP_PLANNING.map_p[5] = ui->lineEdit_p6->text().toDouble();
        MAP_PLANNING.map_pp[5] = ui->lineEdit_pp6->text().toDouble();
    }
    if(nums >= 7){
        MAP_PLANNING.map_m[6] = ui->lineEdit_m7->text().toDouble();
        MAP_PLANNING.map_v[6] = ui->lineEdit_v7->text().toDouble();
        MAP_PLANNING.map_h[6] = ui->lineEdit_h7->text().toDouble();
        MAP_PLANNING.map_p[6] = ui->lineEdit_p7->text().toDouble();
        MAP_PLANNING.map_pp[6] = ui->lineEdit_pp7->text().toDouble();
    }
    if(nums >= 8){
        MAP_PLANNING.map_m[7] = ui->lineEdit_m8->text().toDouble();
        MAP_PLANNING.map_v[7] = ui->lineEdit_v8->text().toDouble();
        MAP_PLANNING.map_h[7] = ui->lineEdit_h8->text().toDouble();
        MAP_PLANNING.map_p[7] = ui->lineEdit_p8->text().toDouble();
        MAP_PLANNING.map_pp[7] = ui->lineEdit_pp8->text().toDouble();
    }
    if(nums >= 9){
        MAP_PLANNING.map_m[8] = ui->lineEdit_m9->text().toDouble();
        MAP_PLANNING.map_v[8] = ui->lineEdit_v9->text().toDouble();
        MAP_PLANNING.map_h[8] = ui->lineEdit_h9->text().toDouble();
        MAP_PLANNING.map_p[8] = ui->lineEdit_p9->text().toDouble();
        MAP_PLANNING.map_pp[8] = ui->lineEdit_pp9->text().toDouble();
    }
    if(nums >= 10){
        MAP_PLANNING.map_m[9] = ui->lineEdit_m10->text().toDouble();
        MAP_PLANNING.map_v[9] = ui->lineEdit_v10->text().toDouble();
        MAP_PLANNING.map_h[9] = ui->lineEdit_h10->text().toDouble();
        MAP_PLANNING.map_p[9] = ui->lineEdit_p10->text().toDouble();
        MAP_PLANNING.map_pp[9] = ui->lineEdit_pp10->text().toDouble();
    }
    if(nums >= 11){
        MAP_PLANNING.map_m[10] = ui->lineEdit_m11->text().toDouble();
        MAP_PLANNING.map_v[10] = ui->lineEdit_v11->text().toDouble();
        MAP_PLANNING.map_h[10] = ui->lineEdit_h11->text().toDouble();
        MAP_PLANNING.map_p[10] = ui->lineEdit_p11->text().toDouble();
        MAP_PLANNING.map_pp[10] = ui->lineEdit_pp11->text().toDouble();
    }
    if(nums >= 12){
        MAP_PLANNING.map_m[11] = ui->lineEdit_m12->text().toDouble();
        MAP_PLANNING.map_v[11] = ui->lineEdit_v12->text().toDouble();
        MAP_PLANNING.map_h[11] = ui->lineEdit_h12->text().toDouble();
        MAP_PLANNING.map_p[11] = ui->lineEdit_p12->text().toDouble();
        MAP_PLANNING.map_pp[11] = ui->lineEdit_pp12->text().toDouble();
    }
    if(nums >= 13){
        MAP_PLANNING.map_m[12] = ui->lineEdit_m13->text().toDouble();
        MAP_PLANNING.map_v[12] = ui->lineEdit_v13->text().toDouble();
        MAP_PLANNING.map_h[12] = ui->lineEdit_h13->text().toDouble();
        MAP_PLANNING.map_p[12] = ui->lineEdit_p13->text().toDouble();
        MAP_PLANNING.map_pp[12] = ui->lineEdit_pp13->text().toDouble();
    }
    if(nums >= 14){
        MAP_PLANNING.map_m[13] = ui->lineEdit_m14->text().toDouble();
        MAP_PLANNING.map_v[13] = ui->lineEdit_v14->text().toDouble();
        MAP_PLANNING.map_h[13] = ui->lineEdit_h14->text().toDouble();
        MAP_PLANNING.map_p[13] = ui->lineEdit_p14->text().toDouble();
        MAP_PLANNING.map_pp[13] = ui->lineEdit_pp14->text().toDouble();
    }
    if(nums >= 15){
        MAP_PLANNING.map_m[14] = ui->lineEdit_m15->text().toDouble();
        MAP_PLANNING.map_v[14] = ui->lineEdit_v15->text().toDouble();
        MAP_PLANNING.map_h[14] = ui->lineEdit_h15->text().toDouble();
        MAP_PLANNING.map_p[14] = ui->lineEdit_p15->text().toDouble();
        MAP_PLANNING.map_pp[14] = ui->lineEdit_pp15->text().toDouble();
    }
    if(nums >= 16){
        MAP_PLANNING.map_m[15] = ui->lineEdit_m16->text().toDouble();
        MAP_PLANNING.map_v[15] = ui->lineEdit_v16->text().toDouble();
        MAP_PLANNING.map_h[15] = ui->lineEdit_h16->text().toDouble();
        MAP_PLANNING.map_p[15] = ui->lineEdit_p16->text().toDouble();
        MAP_PLANNING.map_pp[15] = ui->lineEdit_pp16->text().toDouble();
    }
    if(nums >= 17){
        MAP_PLANNING.map_m[16] = ui->lineEdit_m17->text().toDouble();
        MAP_PLANNING.map_v[16] = ui->lineEdit_v17->text().toDouble();
        MAP_PLANNING.map_h[16] = ui->lineEdit_h17->text().toDouble();
        MAP_PLANNING.map_p[16] = ui->lineEdit_p17->text().toDouble();
        MAP_PLANNING.map_pp[16] = ui->lineEdit_pp17->text().toDouble();
    }
    if(nums >= 18){
        MAP_PLANNING.map_m[17] = ui->lineEdit_m18->text().toDouble();
        MAP_PLANNING.map_v[17] = ui->lineEdit_v18->text().toDouble();
        MAP_PLANNING.map_h[17] = ui->lineEdit_h18->text().toDouble();
        MAP_PLANNING.map_p[17] = ui->lineEdit_p18->text().toDouble();
        MAP_PLANNING.map_pp[17] = ui->lineEdit_pp18->text().toDouble();
    }
    if(nums >= 19){
        MAP_PLANNING.map_m[18] = ui->lineEdit_m19->text().toDouble();
        MAP_PLANNING.map_v[18] = ui->lineEdit_v19->text().toDouble();
        MAP_PLANNING.map_h[18] = ui->lineEdit_h19->text().toDouble();
        MAP_PLANNING.map_p[18] = ui->lineEdit_p19->text().toDouble();
        MAP_PLANNING.map_pp[18] = ui->lineEdit_pp19->text().toDouble();
    }
    if(nums >= 20){
        MAP_PLANNING.map_m[19] = ui->lineEdit_m20->text().toDouble();
        MAP_PLANNING.map_v[19] = ui->lineEdit_v20->text().toDouble();
        MAP_PLANNING.map_h[19] = ui->lineEdit_h20->text().toDouble();
        MAP_PLANNING.map_p[19] = ui->lineEdit_p20->text().toDouble();
        MAP_PLANNING.map_pp[19] = ui->lineEdit_pp20->text().toDouble();
    }
    if(nums >= 21){
        MAP_PLANNING.map_m[20] = ui->lineEdit_m21->text().toDouble();
        MAP_PLANNING.map_v[20] = ui->lineEdit_v21->text().toDouble();
        MAP_PLANNING.map_h[20] = ui->lineEdit_h21->text().toDouble();
        MAP_PLANNING.map_p[20] = ui->lineEdit_p21->text().toDouble();
        MAP_PLANNING.map_pp[20] = ui->lineEdit_pp21->text().toDouble();
    }
    if(nums >= 22){
        MAP_PLANNING.map_m[21] = ui->lineEdit_m22->text().toDouble();
        MAP_PLANNING.map_v[21] = ui->lineEdit_v22->text().toDouble();
        MAP_PLANNING.map_h[21] = ui->lineEdit_h22->text().toDouble();
        MAP_PLANNING.map_p[21] = ui->lineEdit_p22->text().toDouble();
        MAP_PLANNING.map_pp[21] = ui->lineEdit_pp22->text().toDouble();
    }
    if(nums >= 23){
        MAP_PLANNING.map_m[22] = ui->lineEdit_m23->text().toDouble();
        MAP_PLANNING.map_v[22] = ui->lineEdit_v23->text().toDouble();
        MAP_PLANNING.map_h[22] = ui->lineEdit_h23->text().toDouble();
        MAP_PLANNING.map_p[22] = ui->lineEdit_p23->text().toDouble();
        MAP_PLANNING.map_pp[22] = ui->lineEdit_pp23->text().toDouble();
    }
    if(nums >= 24){
        MAP_PLANNING.map_m[23] = ui->lineEdit_m24->text().toDouble();
        MAP_PLANNING.map_v[23] = ui->lineEdit_v24->text().toDouble();
        MAP_PLANNING.map_h[23] = ui->lineEdit_h24->text().toDouble();
        MAP_PLANNING.map_p[23] = ui->lineEdit_p24->text().toDouble();
        MAP_PLANNING.map_pp[23] = ui->lineEdit_pp24->text().toDouble();
    }
    if(nums >= 25){
        MAP_PLANNING.map_m[24] = ui->lineEdit_m25->text().toDouble();
        MAP_PLANNING.map_v[24] = ui->lineEdit_v25->text().toDouble();
        MAP_PLANNING.map_h[24] = ui->lineEdit_h25->text().toDouble();
        MAP_PLANNING.map_p[24] = ui->lineEdit_p25->text().toDouble();
        MAP_PLANNING.map_pp[24] = ui->lineEdit_pp25->text().toDouble();
    }

}

void Mappoints::show_hide()
{
    show();
}

void Mappoints::on_toolButton_exit_clicked()
{
    hide();
}
