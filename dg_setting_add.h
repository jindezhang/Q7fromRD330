#ifndef DG_SETTING_ADD_H
#define DG_SETTING_ADD_H

#include <QDialog>
#include<QDebug>
#include<QList>
#include<QRegExpValidator>
#include<QRegExp>

namespace Ui {
class Dg_Setting_add;
}

//x原始浓度，默认为1；
class Dg_Setting_add : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Setting_add(QWidget *parent = 0);
    ~Dg_Setting_add();
    void set_CardID(QString id);//设置卡的ID；
    void set_X(int x);//设置初始浓度；
    QList<QString> get_Value();

signals:
    void get_Value(QList<QString>);
private slots:
    void on_pushButton_2_clicked();

    void on_bt_canal_setting_clicked();

    void on_bt_save_setting_clicked();
private:
    void save_Value();
    bool isDigitStr(QString src);//判断是否为纯数字
private:
    Ui::Dg_Setting_add *ui;
    QList<QString> m_value;//保存输入值。
    QRegExpValidator* va;//限制只能输入数字
    int m_x;
};

#endif // DG_SETTING_ADD_H
