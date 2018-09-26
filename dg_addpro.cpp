#include "dg_addpro.h"
#include "ui_dg_addpro.h"

Dg_AddPro::Dg_AddPro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_AddPro)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());


}

Dg_AddPro::~Dg_AddPro()
{
    delete ui;
}

void Dg_AddPro::on_pushButton_2_clicked()
{
    hide();
}

void Dg_AddPro::on_bt_canal_clicked()
{
    hide();
}

void Dg_AddPro::on_bt_ok_clicked()
{

    hide();
}
