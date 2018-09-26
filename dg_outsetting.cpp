#include "dg_outsetting.h"
#include "ui_dg_outsetting.h"

Dg_OutSetting::Dg_OutSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_OutSetting)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    m_value.clear();

}

Dg_OutSetting::~Dg_OutSetting()
{
    delete ui;
}

QMap<QString, int> Dg_OutSetting::get_Value()
{
    return m_value;
}

void Dg_OutSetting::on_pushButton_2_clicked()
{

    hide();
}

void Dg_OutSetting::on_bt_cancal_clicked()
{

    hide();
}

void Dg_OutSetting::on_bt_ok_clicked()
{
    m_value.insert("name", ui->cb_name_outset->checkState());
    m_value.insert("age", ui->cb_age_outset->checkState());
    m_value.insert("sex", ui->cbb_sex_outset->checkState());
    m_value.insert("doctor", ui->cb_doctor_outset->checkState());
    m_value.insert("addr", ui->cb_addr_outset->checkState());
    m_value.insert("class", ui->cb_class_outset->checkState());
    m_value.insert("classnum", ui->cb_classnum_outset->checkState());
    m_value.insert("testtype", ui->cb_testtype_outset->checkState());
    m_value.insert("typeman", ui->cb_typeman_outset->checkState());
    m_value.insert("testnum", ui->cbb_testnum_outset->checkState());
    m_value.insert("bednum", ui->cbb_bed_outset->checkState());
    m_value.insert("checker", ui->cb_checkman_outset->checkState());


    hide();
}
