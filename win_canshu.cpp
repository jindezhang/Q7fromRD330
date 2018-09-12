#include "win_canshu.h"
#include "ui_win_canshu.h"

Win_Canshu::Win_Canshu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win_Canshu)
{
    ui->setupUi(this);
    ui->widget_2->hide();
    this->setStyleSheet("#Win_Canshu{background-color: rgb(255, 255, 255);}");
}

Win_Canshu::~Win_Canshu()
{
    delete ui;
}

void Win_Canshu::on_pushButton_5_clicked()
{
    Dg_Login* dg_login = new Dg_Login();
    dg_login->exec();
}
