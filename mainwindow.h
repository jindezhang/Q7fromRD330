#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTimer>
#include <QDebug>
#include <QFile>
#include <data.h>

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
    void on_bt_shutup_clicked();
    void fuhua_show(bool b);
    void on_bt_fuhua_clicked();

    void on_bt_quxiao_clicked();
    void timer_Out();
    QString toStr(int i);
    void on_bt_liulan_clicked();

private:
    Ui::MainWindow *ui;
    QTimer* t;
    int t_value;
    Data *ui_data;
};

#endif // MAINWINDOW_H
