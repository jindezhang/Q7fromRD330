#ifndef DG_LOGIN_H
#define DG_LOGIN_H

#include <QDialog>
#include <QtGlobal>
#include<QTime>
#include<mydialog.h>


namespace Ui {
class Dg_Login;
}
#pragma execution_character_set("utf-8")

class Dg_Login : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Login(int type = 0, QWidget *parent = 0);
    ~Dg_Login();
    void set_Type(int type);//设置密码类型。0是默认，用于登录维护界面。
signals:
    void sel_bt(bool b);//确认的信号
private slots:
    void on_pushButton_2_clicked();//关闭

    void on_bt_cancel_clicked();//取消

    void on_bt_ok_clicked();//确认,密码是1+随机码
private:
    int get_pw();//获取密码
private:
    Ui::Dg_Login *ui;
    int m_type;//密码类型
};

#endif // DG_LOGIN_H
