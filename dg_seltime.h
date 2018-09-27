#ifndef DG_SELTIME_H
#define DG_SELTIME_H

#include <QDialog>
#include<QPalette>
#include<QDebug>

namespace Ui {
class Dg_SelTime;
}

class Dg_SelTime : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_SelTime(QWidget *parent = 0);
    ~Dg_SelTime();

private slots:


    void on_bt_cancel_clicked();

    void on_bt_today_clicked();

    void on_bt_select_clicked();

private:
    void init_Calendar();

    QDate last_Date();//获取三个月前日期
private:
    Ui::Dg_SelTime *ui;
};

#endif // DG_SELTIME_H
