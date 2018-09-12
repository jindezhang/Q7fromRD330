#include "dg_login.h"
#include "ui_dg_login.h"

Dg_Login::Dg_Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Login)
{
    ui->setupUi(this);

    //生成随机数
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    ui->ed_num->setText(QString("%1").arg((qrand()%100+50) * 77));

}

Dg_Login::~Dg_Login()
{
    delete ui;
}

void Dg_Login::on_pushButton_2_clicked()
{
    this->close();
}

void Dg_Login::on_bt_cancel_clicked()
{
    emit sel_bt(false);
    this->close();
}

void Dg_Login::on_bt_ok_clicked()
{

    emit sel_bt(true);
}
