#include "dg_login.h"
#include "ui_dg_login.h"

Dg_Login::Dg_Login(int type, QWidget *parent) :
    QDialog(parent),m_type(type),
    ui(new Ui::Dg_Login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//窗体无边框，无法移动。
    //生成随机数
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    ui->ed_num->setText(QString("%1").arg((qrand()%100+50) * 77));

    ui->bt_ok->installEventFilter(this);

    connect(ui->ed_pw, SIGNAL(returnPressed()), this, SLOT(on_bt_ok_clicked()));//按下回车键触发
    ui->ed_pw->setFocus();//控件获得焦点
}

Dg_Login::~Dg_Login()
{
    delete ui;
}

void Dg_Login::set_Type(int type)
{
    m_type = type;
}

void Dg_Login::on_pushButton_2_clicked()
{
    close();
}

void Dg_Login::on_bt_cancel_clicked()
{
    //emit sel_bt(false);
    close();
}

void Dg_Login::on_bt_ok_clicked()
{


    myDialog dia(this);
    QString in = ui->ed_pw->text();
    int pw = get_pw();
    if(pw != in.toInt()){
        dia.set_info(QString("密码错误！"));
        dia.set_icon(0);
        dia.exec();
        return;
    }else
    {
        emit sel_bt(true);
    }

    close();
}

int Dg_Login::get_pw()
{
    QString num = ui->ed_num->text();
    switch (m_type) {
    case 0:
        return num.toInt() + 1;
        break;
    default:
        break;
    }
    return -1;
}
