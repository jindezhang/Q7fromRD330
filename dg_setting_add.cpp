#include "dg_setting_add.h"
#include "ui_dg_setting_add.h"

Dg_Setting_add::Dg_Setting_add(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Setting_add)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    ui->l_card->setText(id);

}

Dg_Setting_add::~Dg_Setting_add()
{
    delete ui;
}

void Dg_Setting_add::set_CardID(QString id)
{
    ui->l_card->setText(id);
}

void Dg_Setting_add::on_pushButton_2_clicked()
{
    hide();
}

void Dg_Setting_add::on_bt_canal_setting_clicked()
{
    hide();
}

void Dg_Setting_add::on_bt_save_setting_clicked()
{


    hide();
}
