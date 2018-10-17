#ifndef DG_SELTIME_H
#define DG_SELTIME_H

#include <QDialog>
#include<QPalette>
#include<QDebug>
#include<mydialog.h>
#include "wg_shade.h"

namespace Ui {
class Dg_SelTime;
}
#pragma execution_character_set("utf-8")

class Dg_SelTime : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_SelTime(QWidget *parent = 0);
    ~Dg_SelTime();
    QDate str_toDate(QString &str);//传入字符串获得日期。字符串格式yyyy-MM-dd
    QStringList get_Date();//获取日期
private slots:
    void on_bt_cancel_clicked();

    void on_bt_today_clicked();
    void click_Start();//点击了第一个日期
    void click_End();//点击第二个日期
    void on_bt_select_clicked();

    void on_bt_select_cancel_clicked();

    void on_bt_ok_clicked();

    void on_pushButton_3_clicked();
    void is_Del(bool b);//是否删除数据。
private:
    void init_Calendar();
    void changeSheet();//改变日期框的样式
    void back_Sheet();//原始日期框样式
    QDate last_Date();//获取三个月前日期
private:
    Ui::Dg_SelTime *ui;
    bool bt_type;//那个按钮点击了
    QStringList m_date;//保存选中日期
    QWidget *mpshade;
};

#endif // DG_SELTIME_H
