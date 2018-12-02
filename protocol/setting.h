#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QtGui>
#include <QTimer>
#include <QVBoxLayout>
#include "package.h"
#include "checksum.h"
#include "helper.h"
#include "types.h"
#include <QScrollArea>
#include "config/toconfig.h"
#include "serial/packet.h"

extern float valuefromsetting;//get value from lineedit--send it as single command

namespace Ui {
class Setting;
}

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();
    void show_hide();
    void switchPage();
    void AP_Command(quint8 id);
    void displaydatafromini();
    Package *package_command;

protected:
    void paintEvent(QPaintEvent *e); 
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private slots:

    void on_pushButton_input_clicked();

    void on_toolButton_exit_clicked();

    void on_lineEdit_3_editingFinished();

    void on_lineEdit_1_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_4_editingFinished();

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_6_editingFinished();

    void on_lineEdit_7_editingFinished();

    void on_lineEdit_8_editingFinished();

    void on_lineEdit_9_editingFinished();

    void on_lineEdit_10_editingFinished();

    void on_lineEdit_11_editingFinished();

    void on_lineEdit_12_editingFinished();

    void on_lineEdit_13_editingFinished();

    void on_lineEdit_14_editingFinished();

    void on_lineEdit_15_editingFinished();

    void on_lineEdit_16_editingFinished();

    void on_lineEdit_17_editingFinished();

    void on_lineEdit_18_editingFinished();

    void on_lineEdit_19_editingFinished();

    void on_lineEdit_20_editingFinished();

    void on_lineEdit_21_editingFinished();

    void on_lineEdit_22_editingFinished();

    void on_lineEdit_23_editingFinished();

    void on_lineEdit_24_editingFinished();

    void on_lineEdit_25_editingFinished();

    void on_lineEdit_26_editingFinished();

    void on_lineEdit_27_editingFinished();

    void on_lineEdit_28_editingFinished();

    void on_lineEdit_29_editingFinished();

    void on_lineEdit_30_editingFinished();

    void on_lineEdit_31_editingFinished();

    void on_lineEdit_32_editingFinished();

    void on_lineEdit_33_editingFinished();

    void on_lineEdit_34_editingFinished();

    void on_lineEdit_35_editingFinished();

    void on_lineEdit_36_editingFinished();

    void on_lineEdit_37_editingFinished();

    void on_lineEdit_38_editingFinished();

    void on_lineEdit_39_editingFinished();

    void on_lineEdit_40_editingFinished();

    void on_lineEdit_41_editingFinished();

    void on_lineEdit_42_editingFinished();

    void on_lineEdit_43_editingFinished();

    void on_lineEdit_44_editingFinished();

    void on_lineEdit_45_editingFinished();

    void on_lineEdit_46_editingFinished();

    void on_lineEdit_47_editingFinished();

    void on_lineEdit_48_editingFinished();

    void on_lineEdit_49_editingFinished();

    void on_lineEdit_50_editingFinished();

    void on_lineEdit_51_editingFinished();

    void on_lineEdit_52_editingFinished();

    void on_lineEdit_53_editingFinished();

    void on_lineEdit_54_editingFinished();

    void on_lineEdit_55_editingFinished();

    void on_lineEdit_56_editingFinished();

    void on_lineEdit_57_editingFinished();

    void on_lineEdit_58_editingFinished();

    void on_lineEdit_59_editingFinished();

    void on_lineEdit_60_editingFinished();

    void on_lineEdit_61_editingFinished();

    void on_lineEdit_62_editingFinished();

    void on_lineEdit_63_editingFinished();

    void on_lineEdit_64_editingFinished();

    void on_lineEdit_65_editingFinished();

    void on_lineEdit_66_editingFinished();

    void on_lineEdit_67_editingFinished();

    void on_lineEdit_68_editingFinished();

    void on_lineEdit_69_editingFinished();

    void on_pushButton_send_clicked();

    void on_lineEdit_configname_returnPressed();

    void on_toolButton_save_clicked();

    void on_toolButton_load_clicked();

    void on_pushButton_APparameter_clicked();

    void on_pushButton_singlecommand_clicked();

public slots:
    void handleTimeout();  //超时处理函数

private:
    Ui::Setting *ui;
    QTimer *m_pTimer;
    Toconfig *toconfig;
    QPoint last;
    quint8 id_lineedit = 0;//read value from lineedit
    bool databasename_showhide_flag = 0;//default : hide
    double datafromlineedit[num_para];
};

#endif // SETTING_H
