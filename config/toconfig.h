#ifndef TOCONFIG_H
#define TOCONFIG_H
#include <QSettings>
#include <QThread>
#include "serial/packet.h"

extern QString datafromini[num_para];

class Toconfig : public QThread {

    Q_OBJECT
public:
    Toconfig();
    void creatini(double datafromlineedit[]);
    void getsavename(QString savename);
    void readfromini(QString path);

private:
    QSettings *setting;
    QString configsavename = "CONFIG.ini";
};

#endif // TOCONFIG_H
