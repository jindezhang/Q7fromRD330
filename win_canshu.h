#ifndef WIN_CANSHU_H
#define WIN_CANSHU_H

#include <QMainWindow>
#include<customtabstyle.h>
#include <dg_login.h>
#include <QDebug>
#include<QDialog>

namespace Ui {
class Win_Canshu;
}

class Win_Canshu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win_Canshu(QWidget *parent = 0);
    ~Win_Canshu();

private slots:
    void on_pushButton_5_clicked();//维护

    void on_pushButton_16_clicked();//退出


    void on_pushButton_3_clicked();//参数


    void on_bt_jiaozhen_clicked();//扫描仪校正

private:
    Ui::Win_Canshu *ui;
};

#endif // WIN_CANSHU_H
