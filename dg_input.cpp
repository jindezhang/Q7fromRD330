#include "dg_input.h"
#include "ui_dg_input.h"

Dg_Input::Dg_Input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Input)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//窗体无边框，无法移动。

    v_ed.push_back(ui->ed_name);v_ed.push_back(ui->ed_checker);
    v_ed.push_back(ui->ed_doctor);
    v_ed.push_back(ui->ed_type_card);
    v_ed.push_back(ui->ed_type_people);v_ed.push_back(ui->ed_bed_num);v_ed.push_back(ui->ed_class_num);
    v_ed.push_back(ui->ed_classroom);

    v_ed.push_back(ui->ed_age);//年纪
    ui->ed_age->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
}

Dg_Input::~Dg_Input()
{
    delete ui;
}

void Dg_Input::on_bt_ok_clicked()
{
    l_info.clear();
    for(auto item : v_ed){
        l_info.push_back(item->text());
        qDebug()<<"item->text()"<<item->text();
    }

    l_info.push_back(ui->cbb_age2->currentText());
    l_info.push_back(ui->cbb_gender->currentText());


    hide();
}

void Dg_Input::on_bt_cancel_clicked()
{
    hide();
}

void Dg_Input::on_bt_cancel_2_clicked()
{
    ui->ed_age->clear();
    ui->ed_bed_num->clear();
    ui->ed_checker->clear();
    ui->ed_name->clear();
    ui->ed_doctor->clear();
    ui->ed_type_card->clear();
    ui->ed_type_people->clear();
    ui->ed_classroom->clear();
    ui->ed_class_num->clear();
}

void Dg_Input::on_pushButton_2_clicked()
{
    hide();
}
