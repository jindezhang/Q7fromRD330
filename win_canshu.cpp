#include "win_canshu.h"
#include "ui_win_canshu.h"

Win_Canshu::Win_Canshu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win_Canshu)
{
    ui->setupUi(this);
    ui->widget_2->hide();
    this->setStyleSheet("#Win_Canshu{background-color: rgb(255, 255, 255);}");
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
}

Win_Canshu::~Win_Canshu()
{
    delete ui;
}

void Win_Canshu::on_pushButton_5_clicked()
{
    Dg_Login dg_login(this);

    dg_login.exec();
    qDebug()<<"weihui out";
}

void Win_Canshu::on_pushButton_16_clicked()
{
    this->parentWidget()->show();
    this->close();
}



void Win_Canshu::on_pushButton_3_clicked()
{
    qDebug()<<"weihui out";
}

void Win_Canshu::on_bt_jiaozhen_clicked()
{
    qDebug()<<"weihui out";
}
