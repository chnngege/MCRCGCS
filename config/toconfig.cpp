#include "toconfig.h"
#include "ui_toconfig.h"
QString datafromini[num_para];
Toconfig::Toconfig()
{

}

void Toconfig::creatini(double datafromlineedit[])
{
    QString fileName = configsavename;
    setting = new QSettings(fileName, QSettings::IniFormat);
    setting->beginGroup("ROLL_CONTROL");
    setting->setValue("P", datafromlineedit[0]);
    qDebug() << datafromlineedit[0];
    //qDebug() << datafromlineedit[0];
    setting->setValue("I", datafromlineedit[1]);
    setting->setValue("D", datafromlineedit[2]);
    setting->setValue("DD", datafromlineedit[3]);
    setting->setValue("LIMIT_UP", datafromlineedit[4]);
    setting->setValue("LIMIT_DOWN", datafromlineedit[5]);
    setting->endGroup();

    setting->beginGroup("PITCH_CONTROL");
    setting->setValue("P", datafromlineedit[6]);
    setting->setValue("I", datafromlineedit[7]);
    setting->setValue("D", datafromlineedit[8]);
    setting->setValue("DD", datafromlineedit[9]);
    setting->setValue("LIMIT_UP", datafromlineedit[10]);
    setting->setValue("LIMIT_DOWN", datafromlineedit[11]);
    setting->endGroup();

    setting->beginGroup("MOTOR");
    setting->setValue("P", datafromlineedit[12]);
    setting->setValue("I", datafromlineedit[13]);
    setting->setValue("D", datafromlineedit[14]);
    setting->setValue("DIFFERENCE", datafromlineedit[15]);
    setting->setValue("LIMIT_PWM_UP", datafromlineedit[16]);
    setting->setValue("LIMIT_PWM_DOWN", datafromlineedit[17]);
    setting->setValue("LIMIT_UP", datafromlineedit[18]);
    setting->setValue("LIMIT_DOWN", datafromlineedit[19]);
    setting->setValue("MOTOR_STOP_TIME", datafromlineedit[20]);
    setting->endGroup();

    setting->beginGroup("YAW_CONTROL");
    setting->setValue("P", datafromlineedit[21]);
    setting->setValue("I", datafromlineedit[22]);
    setting->setValue("D", datafromlineedit[23]);
    setting->setValue("LIMIT_UP", datafromlineedit[24]);
    setting->endGroup();
}

void Toconfig::readfromini(QString path)
{
    //setting = new QSettings(path,QSettings::IniFormat);
    QString fileName = configsavename;
    setting = new QSettings(path, QSettings::IniFormat);
    setting->beginGroup("ROLL_CONTROL");
    qDebug() << setting->value("P").toString();
    datafromini[0] = setting->value("P").toString();
    datafromini[1] = setting->value("I").toString();
    datafromini[2] = setting->value("D").toString();
    datafromini[3] = setting->value("DD").toString();
    datafromini[4] = setting->value("LIMIT_UP").toString();
    datafromini[5] = setting->value("LIMIT_DOWN").toString();
    setting->endGroup();

    setting->beginGroup("PITCH_CONTROL");
    datafromini[6] = setting->value("P").toString();
    datafromini[7] = setting->value("I").toString();
    datafromini[8] = setting->value("D").toString();
    datafromini[9] = setting->value("DD").toString();
    datafromini[10] = setting->value("LIMIT_UP").toString();
    datafromini[11] = setting->value("LIMIT_DOWN").toString();
    setting->endGroup();

    setting->beginGroup("MOTOR");
    datafromini[12] = setting->value("P").toString();
    datafromini[13] = setting->value("I").toString();
    datafromini[14] = setting->value("D").toString();
    datafromini[15] = setting->value("DIFFERENCE").toString();
    datafromini[16] = setting->value("LIMIT_PWM_UP").toString();
    datafromini[17] = setting->value("LIMIT_PWM_DOWN").toString();
    datafromini[18] = setting->value("LIMIT_UP").toString();
    datafromini[19] = setting->value("LIMIT_DOWN").toString();
    datafromini[20] = setting->value("MOTOR_STOP_TIME").toString();
    setting->endGroup();

    setting->beginGroup("YAW_CONTROL");
    datafromini[21] = setting->value("P").toString();
    datafromini[22] = setting->value("I").toString();
    datafromini[23] = setting->value("D").toString();
    datafromini[24] = setting->value("LIMIT_UP").toString();
    setting->endGroup();
}

void Toconfig::getsavename(QString savename)
{
    if(savename == "")
        return;
    else
        configsavename = savename;
}

