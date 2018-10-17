#include "wg_canshu.h"
#include "ui_wg_canshu.h"

Wg_canshu::Wg_canshu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wg_canshu)
{
    ui->setupUi(this);
    set_cbb(false);
    mpShade = init_Shade(parent);
    mpShade->resize(1024, 700);
}

Wg_canshu::~Wg_canshu()
{
    delete mpShade;
    delete ui;
}

void Wg_canshu::set_cbb(bool b)
{

    ui->cbb_bit->setEnabled(b);
    ui->cbb_data->setEnabled(b);
    ui->cbb_rate->setEnabled(b);
    ui->cbb_serial->setEnabled(b);
    ui->cbb_stop->setEnabled(b);
}


void Wg_canshu::on_bt_file_clicked()
{
    //QFileDialog* fileDialog = new QFileDialog();
    //fileDialog->open();
    QString fileName = QFileDialog::getExistingDirectory(this);
    ui->ed_file->setText(fileName);
}

void Wg_canshu::on_bt_savePath_clicked()
{
    QString fileName = QFileDialog::getExistingDirectory(this);
    ui->ed_savePath->setText(fileName);
}

void Wg_canshu::on_pushButton_clicked()
{
    WG_Shade shade(mpShade);
    Dg_OutSetting dialog;
    dialog.exec();
}

void Wg_canshu::on_checkBox_5_clicked(bool checked)
{
    set_cbb(checked);
}

#include "wg_shade.h"


void Wg_canshu::on_bt_print_canshu_clicked()
{
    WG_Shade shade(mpShade);
    Dg_OutSetting dialog;
    dialog.exec();
    qDebug()<<"print";
}
