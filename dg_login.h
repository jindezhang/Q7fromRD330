#ifndef DG_LOGIN_H
#define DG_LOGIN_H

#include <QDialog>
#include <QtGlobal>
#include<QTime>
namespace Ui {
class Dg_Login;
}

class Dg_Login : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Login(QWidget *parent = 0);
    ~Dg_Login();

signals:
    void sel_bt(bool b);
private slots:
    void on_pushButton_2_clicked();

    void on_bt_cancel_clicked();

    void on_bt_ok_clicked();

private:
    Ui::Dg_Login *ui;
};

#endif // DG_LOGIN_H
