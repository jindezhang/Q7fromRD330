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
    void on_pushButton_16_clicked();//退出

    void changePic(bool b);//改变按钮的图片；
    void on_bt_jiaozhen_clicked();//扫描仪校正
    void on_weihui(bool b); //维护的确认。
    void on_bt_canshu_clicked();

    void on_bt_weihu_clicked();

private:
    Ui::Win_Canshu *ui;
};

#endif // WIN_CANSHU_H
