﻿#include "dg_input.h"
#include "ui_dg_input.h"

Dg_Input::Dg_Input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Input)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//窗体无边框，无法移动。

    v_ed.push_back(ui->name);v_ed.push_back(ui->age);v_ed.push_back(ui->checker);
    v_ed.push_back(ui->doctoe);
    v_ed.push_back(ui->type_card);
    v_ed.push_back(ui->type_people);v_ed.push_back(ui->bed_num);v_ed.push_back(ui->class_num);
    v_ed.push_back(ui->classroom);

    ui->age->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
}

Dg_Input::~Dg_Input()
{
    delete ui;
}

void Dg_Input::on_bt_ok_clicked()
{
    close();
}

void Dg_Input::on_bt_cancel_clicked()
{

    hide();
}

void Dg_Input::on_bt_cancel_2_clicked()
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