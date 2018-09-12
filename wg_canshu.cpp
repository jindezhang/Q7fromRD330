#include "wg_canshu.h"
#include "ui_wg_canshu.h"

Wg_canshu::Wg_canshu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wg_canshu)
{
    ui->setupUi(this);

}

Wg_canshu::~Wg_canshu()
{
    delete ui;
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
