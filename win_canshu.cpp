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
    changePic(true);

}

Win_Canshu::~Win_Canshu()
{
    delete ui;
}

void Win_Canshu::on_pushButton_16_clicked()
{
    on_bt_canshu_clicked();
    this->parentWidget()->show();
    this->close();
}

void Win_Canshu::changePic(bool b)
{
    if(b){
        ui->label_4->setText("参数 > 参数");
        ui->bt_canshu->setStyleSheet("border-image: url(:/new/home/home/params.png);");
        ui->bt_weihu->setStyleSheet("border-image: url(:/new/home/home/weihu_1.png);");
    }else{
        ui->label_4->setText("维护 > 维护");
        ui->bt_canshu->setStyleSheet("border-image: url(:/new/home/home/params_1.png);");
        ui->bt_weihu->setStyleSheet("border-image: url(:/new/home/home/weihu.png);");
    }
}

void Win_Canshu::on_bt_jiaozhen_clicked()
{
    qDebug()<<"weihui out";
}

void Win_Canshu::on_weihui(bool b)
{
    changePic(!b);
    if(b){

        ui->widget->hide();
        ui->widget_2->show();
    }
    else{
        ui->widget->show();
        ui->widget_2->hide();
    }

}

void Win_Canshu::on_bt_canshu_clicked()
{
    on_weihui(false);
}

void Win_Canshu::on_bt_weihu_clicked()
{
//    Dg_Login dg_login(this);
//    connect(&dg_login, SIGNAL(sel_bt(bool)), this, SLOT(on_weihui(bool)));
//    dg_login.exec();

    on_weihui(true);
}
