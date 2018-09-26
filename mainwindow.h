#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <win_kuaisu.h>
#include <QMainWindow>
#include<QTimer>
#include <QDebug>
#include <QFile>
#include <data.h>
#include "mydialog.h"
#include "win_canshu.h"
#include "dg_login.h"
#include "dg_progress.h"
#include<dg_input.h>
#include<wg_kuaisu.h>
#include<QSqlDatabase>
#include<QSqlError>
#include<dg_addproject.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_bt_shutup_clicked();//关闭软件
    void fuhua_show(bool b);//孵化检测功能
    void on_bt_fuhua_clicked();//孵化按钮

    void on_bt_quxiao_clicked();//取消孵化
    void timer_Out();//孵化时间计算槽函数
    QString toStr(int i);//整数十进制格式化
    void on_bt_liulan_clicked();//浏览数据

    void on_bt_help_clicked();//帮助按钮

    void on_bt_canshu_clicked();//参数按钮

    void on_bt_saomiao_clicked();//扫描按钮

    void on_bt_kuaisu_clicked();//快速扫描的按钮
    void init_SQLite();

private:
    Ui::MainWindow *ui;
    QTimer* t;
    int t_value;
    Data *ui_data;
    Win_Kuaisu* ui_kuaisu;
    Win_Canshu* ui_canshu;
    wg_kuaisu dg_login;
};

#endif // MAINWINDOW_H
