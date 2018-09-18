#include "wg_kuaisu.h"
#include "ui_wg_kuaisu.h"

wg_kuaisu::wg_kuaisu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wg_kuaisu)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//窗体无边框，无法移动。
    //实现窗体模拟态
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    setWindowModality(Qt::WindowModal);
    v_ed.push_back(ui->name);v_ed.push_back(ui->age);v_ed.push_back(ui->checker);
    v_ed.push_back(ui->doctoe);
    v_ed.push_back(ui->type_card);
    v_ed.push_back(ui->type_people);v_ed.push_back(ui->bed_num);v_ed.push_back(ui->class_num);
    v_ed.push_back(ui->classroom);

    ui->age->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
}

wg_kuaisu::~wg_kuaisu()
{
    delete ui;
}

void wg_kuaisu::on_bt_ok_clicked()
{
    close();
}

void wg_kuaisu::on_bt_cancel_clicked()
{

    close();
}

void wg_kuaisu::on_bt_cancel_2_clicked()
{
    ui->age->clear();
    ui->bed_num->clear();
    ui->checker->clear();
    ui->name->clear();
    ui->doctoe->clear();
    ui->type_card->clear();
    ui->type_people->clear();
    ui->classroom->clear();
    ui->class_num->clear();
}
