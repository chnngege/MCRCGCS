#include "databasethread.h"

void Databasethread::run()
{
    connect(this,SIGNAL(thread_createAnewDatabase()),this,SLOT(createAnewDatabase()));
    connect(this,SIGNAL(thread_insertdata()),this,SLOT(insertdata()));
    connect(this,SIGNAL(thread_database2GCS()),this,SLOT(database2GCS()));
}

void Databasethread::sendsignal_database2GCS(quint8 id_sig)
{
    i_database2GCS = id_sig;
    emit(thread_database2GCS());
}

void Databasethread::sendsignal_insertdata(quint16 id_)
{
    id_insertdata = id_;
    emit(thread_insertdata());
}

void Databasethread::sendsignal_createAnewDatabase()
{
    emit(thread_createAnewDatabase());
}

void Databasethread::getsavenamefromdialog(QString savenamefromdialog)
{
    fileName = savenamefromdialog;
}

//creat a new database
void Databasethread::createAnewDatabase()
{
    QSqlDatabase database;

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName(fileName);
    database.setUserName("MCRC");
    database.setPassword("123456");

    if(!database.open())
    {
        qDebug()<<database.lastError();
        qFatal("failed to connect.") ;
    }
        //creat
    QSqlQuery sql_query;
    QString create_sql = "create table data (id int,UAV_Active_PPM_num int,UAV_AP_Seconds int,\
                          UAV_INS_YAW int,UAV_INS_PITCH int,UAV_INS_ROLL int,UAV_GPS_Satellite_num int,\
                          UAV_Current int,UAV_INS_Height int,UAV_GPS_Height int,UAV_BCS_Vel_X int,UAV_BCS_Vel_Y int,\
                          UAV_BCS_Vel_Z int,UAV_Lat int,UAV_Lon int,UAV_GPS_Yaw int,UAV_GPS_Vel int,UAV_YAW int,\
                          UAV_PITCH int,UAV_ROLL int,UAV_GPS_HDOP int,UAV_Voltage int,UAV_Height int,UAV_Distance int,\
                          UAV_Vertical_Yaw_Parameter int,UAV_Displacement_to_PPM int,UAV_Bump_Flag int)";//26
    sql_query.prepare(create_sql);
    if(!sql_query.exec()){
        qDebug() << "Error: Fail to create table." << sql_query.lastError();
    }
    else{
        qDebug() << "Table created!";
    }
}

void Databasethread::insertdata()//click the button to insert data
{
    QMessageBox mb;
    QSqlQuery query("insert into data (id,UAV_Active_PPM_num,UAV_AP_Seconds,\
                    UAV_INS_YAW,UAV_INS_PITCH,UAV_INS_ROLL,UAV_GPS_Satellite_num,\
                    UAV_Current,UAV_INS_Height,UAV_GPS_Height,UAV_BCS_Vel_X,UAV_BCS_Vel_Y,\
                    UAV_BCS_Vel_Z,UAV_Lat,UAV_Lon,UAV_GPS_Yaw,UAV_GPS_Vel,UAV_YAW,\
                    UAV_PITCH,UAV_ROLL,UAV_GPS_HDOP,UAV_Voltage,UAV_Height,UAV_Distance,\
                    UAV_Vertical_Yaw_Parameter,UAV_Displacement_to_PPM,UAV_Bump_Flag) values(?,?,?,?,?,?,?,?\
                    ,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,id_insertdata);//index of data
    query.bindValue(1,AP_DATA2GCS.UAV_Active_PPM_num);
    query.bindValue(2,AP_DATA2GCS.UAV_AP_Seconds);
    query.bindValue(3,AP_DATA2GCS.UAV_INS_Attitude[0]);
    query.bindValue(4,AP_DATA2GCS.UAV_INS_Attitude[1]);
    query.bindValue(5,AP_DATA2GCS.UAV_INS_Attitude[2]);
    query.bindValue(6,AP_DATA2GCS.UAV_GPS_Satellite_num);
    query.bindValue(7,AP_DATA2GCS.UAV_Current);
    query.bindValue(8,AP_DATA2GCS.UAV_INS_Height);
    query.bindValue(9,AP_DATA2GCS.UAV_GPS_Height);
    query.bindValue(10,AP_DATA2GCS.UAV_BCS_Vel[0]);
    query.bindValue(11,AP_DATA2GCS.UAV_BCS_Vel[1]);
    query.bindValue(12,AP_DATA2GCS.UAV_BCS_Vel[2]);
    query.bindValue(13,AP_DATA2GCS.UAV_Lat);
    query.bindValue(14,AP_DATA2GCS.UAV_Lon);
    query.bindValue(15,AP_DATA2GCS.UAV_GPS_Yaw);
    query.bindValue(16,AP_DATA2GCS.UAV_GPS_Vel);
    query.bindValue(17,AP_DATA2GCS.UAV_Attitude[0]);
    query.bindValue(18,AP_DATA2GCS.UAV_Attitude[1]);
    query.bindValue(19,AP_DATA2GCS.UAV_Attitude[2]);
    query.bindValue(20,AP_DATA2GCS.UAV_GPS_HDOP);
    query.bindValue(21,AP_DATA2GCS.UAV_Voltage);
    query.bindValue(22,AP_DATA2GCS.UAV_Height);
    query.bindValue(23,AP_DATA2GCS.UAV_Distance);
    query.bindValue(24,AP_DATA2GCS.UAV_Vertical_Yaw_Parameter);
    query.bindValue(25,AP_DATA2GCS.UAV_Displacement_to_PPM);
    query.bindValue(26,AP_DATA2GCS.UAV_Bump_Flag);


    if(!query.exec()){
        //printf("%s: insert fail\n",__PRETTY_FUNCTION__);
        mb.setText(query.lastError().text());
        mb.exec();
        return;
    }

    //printf("%s: insert succeed\n",__PRETTY_FUNCTION__);
    //mb.setText("Insert successful!");
    //mb.exec();
}

void Databasethread::database2GCS()//data from database to GCS
{
    QMessageBox mb;

        QSqlQuery query("select UAV_Active_PPM_num,UAV_AP_Seconds,\
                        UAV_INS_YAW,UAV_INS_PITCH,UAV_INS_ROLL,UAV_GPS_Satellite_num,\
                        UAV_Current,UAV_INS_Height,UAV_GPS_Height,UAV_BCS_Vel_X,UAV_BCS_Vel_Y,\
                        UAV_BCS_Vel_Z,UAV_Lat,UAV_Lon,UAV_GPS_Yaw,UAV_GPS_Vel,UAV_YAW,\
                        UAV_PITCH,UAV_ROLL,UAV_GPS_HDOP,UAV_Voltage,UAV_Height,UAV_Distance,\
                        UAV_Vertical_Yaw_Parameter,UAV_Displacement_to_PPM,UAV_Bump_Flag from data where id=?");//26
        query.bindValue(0,i_database2GCS);

        if(!query.exec()){
            printf("%s: query fail\n",__PRETTY_FUNCTION__);
            mb.setText(query.lastError().text());
            mb.exec();
            return;
        }
        //printf("%s: query succeed\n",__PRETTY_FUNCTION__);
        qDebug() << "query succeed";
        while (query.next()){
            //qDebug() << query.value(i).toInt();
            AP_DATA2GCS.UAV_Active_PPM_num = (quint8)query.value(0).toInt();
            AP_DATA2GCS.UAV_AP_Seconds = query.value(1).toFloat();
            AP_DATA2GCS.UAV_INS_Attitude[0] = (short)query.value(2).toInt();
            AP_DATA2GCS.UAV_INS_Attitude[1] = (short)query.value(3).toInt();
            AP_DATA2GCS.UAV_INS_Attitude[2] = (short)query.value(4).toInt();
            AP_DATA2GCS.UAV_GPS_Satellite_num = (quint16)query.value(5).toInt();
            AP_DATA2GCS.UAV_Current = (short)query.value(6).toInt();
            AP_DATA2GCS.UAV_INS_Height = (short)query.value(7).toInt();
            AP_DATA2GCS.UAV_GPS_Height = (short)query.value(8).toInt();
            AP_DATA2GCS.UAV_BCS_Vel[0] = (short)query.value(9).toInt();
            AP_DATA2GCS.UAV_BCS_Vel[1] = (short)query.value(10).toInt();
            AP_DATA2GCS.UAV_BCS_Vel[2] = (short)query.value(11).toInt();
            AP_DATA2GCS.UAV_Lat = query.value(12).toFloat();
            AP_DATA2GCS.UAV_Lon = query.value(13).toFloat();
            AP_DATA2GCS.UAV_GPS_Yaw = (short)query.value(14).toInt();
            AP_DATA2GCS.UAV_GPS_Vel = (quint16)query.value(15).toInt();
            AP_DATA2GCS.UAV_Attitude[0] = (short)query.value(16).toInt();
            AP_DATA2GCS.UAV_Attitude[1] = (short)query.value(17).toInt();
            AP_DATA2GCS.UAV_Attitude[2] = (short)query.value(18).toInt();
            AP_DATA2GCS.UAV_GPS_HDOP = (short)query.value(19).toInt();
            AP_DATA2GCS.UAV_Voltage = (short)query.value(20).toInt();
            AP_DATA2GCS.UAV_Height = (short)query.value(21).toInt();
            AP_DATA2GCS.UAV_Distance = (short)query.value(22).toInt();
            AP_DATA2GCS.UAV_Vertical_Yaw_Parameter = (short)query.value(23).toInt();
            AP_DATA2GCS.UAV_Displacement_to_PPM = (quint16)query.value(24).toInt();
            AP_DATA2GCS.UAV_Bump_Flag = (quint16)query.value(25).toInt();
            emit(data2GCSfinished());
        }
}



