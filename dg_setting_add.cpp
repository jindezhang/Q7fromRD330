#include "dg_setting_add.h"
#include "ui_dg_setting_add.h"

Dg_Setting_add::Dg_Setting_add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Setting_add)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    set_CardID(QString("no card id"));
    va = new QRegExpValidator(QRegExp("[0-9]+$"));
    ui->ed_prob1_setting->setValidator(va);
    ui->ed_prob2_setting->setValidator(va);
    ui->ed_prob3_setting->setValidator(va);
    ui->ed_prok1_setting->setValidator(va);
    ui->ed_prok2_setting->setValidator(va);
    ui->ed_prok3_setting->setValidator(va);

    m_x = 1;
    m_value.clear();
}

Dg_Setting_add::~Dg_Setting_add()
{
    delete va;
    delete ui;
}

void Dg_Setting_add::set_CardID(QString id)
{
    qDebug()<<"cardID:"<<id;
    ui->l_card->setText(id);
}

void Dg_Setting_add::set_X(int x)
{
    m_x = x;
}

QList<QString> Dg_Setting_add::get_Value()
{
    return m_value;
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
    save_Value();

    hide();
}

/***
  *判断一个字符串是否为纯数字,不兼容存在小数点
  */
bool Dg_Setting_add::isDigitStr(QString src)
{
    QByteArray ba = src.toLatin1();//QString 转换为 char*
     const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return false;
    }
    else
    { //纯数字
        return true;
    }
}


void Dg_Setting_add::save_Value()
{
    m_value.push_back(ui->ed_pnum_setting->text());

    int value;
    value = ui->ed_prok1_setting->text().toInt() * m_x + ui->ed_prob1_setting->text().toInt();
    QString str;

    str = QString("%1").arg(value);
    //qDebug()<<value;
    if(isDigitStr(str) && value != 0)
        m_value.push_back(str);
    else
        m_value.push_back(QString(""));

    value = ui->ed_prok2_setting->text().toInt() * m_x + ui->ed_prob2_setting->text().toInt();
    str = QString("%1").arg(value);
    //qDebug()<<value;
    if(isDigitStr(str) && value != 0)
        m_value.push_back(str);
    else
        m_value.push_back(QString(""));

    value = ui->ed_prok3_setting->text().toInt() * m_x + ui->ed_prob3_setting->text().toInt();
    str = QString("%1").arg(value);
    //qDebug()<<value;
    if(isDigitStr(str) && value != 0)
        m_value.push_back(str);
    else
        m_value.push_back(QString(""));



    emit get_Value(m_value);
    qDebug()<<"m_value"<<m_value;
}
