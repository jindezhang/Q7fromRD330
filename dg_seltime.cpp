#include "dg_seltime.h"
#include "ui_dg_seltime.h"

Dg_SelTime::Dg_SelTime(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_SelTime)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    setAttribute(Qt::WA_TranslucentBackground, true);
    QPalette pal = palette();
    pal.setColor(QPalette::Background, QColor(0,0,0,100));
    setPalette(pal);

    init_Calendar();

    connect(ui->ed_start, SIGNAL(bt_click(QString)), this, SLOT(click_Start()));
    connect(ui->ed_end, SIGNAL(bt_click(QString)), this, SLOT(click_End()));
    bt_type = false;
    m_date.clear();
    mpshade = init_Shade(this);

}

Dg_SelTime::~Dg_SelTime()
{
    delete mpshade;
    delete ui;
}

QDate Dg_SelTime::str_toDate(QString& str)
{
    //yyyy-mm-dd
    QString year = str.mid(0,4);
    QString m = str.mid(5,2);
    QString d = str.mid(8);

    return QDate(year.toInt(), m.toInt(), d.toInt());
}

QStringList Dg_SelTime::get_Date()
{
    return m_date;
}



void Dg_SelTime::on_bt_cancel_clicked()
{
    hide();
}

void Dg_SelTime::init_Calendar()
{
    ui->wg_calendar->hide();
    QDate current_date =QDate::currentDate();
    ui->calendar_start->setMaximumDate(current_date);
    ui->ed_end->setText(current_date.toString("yyyy-MM-dd"));
    current_date = last_Date();
    ui->ed_start->setText(current_date.toString("yyyy-MM-dd"));
    back_Sheet();
}

void Dg_SelTime::changeSheet()
{
    back_Sheet();
    if(bt_type){
        ui->ed_end->setStyleSheet("background-color: rgb(52, 178, 237);color: rgb(255,255,255);");
    }else{
        ui->ed_start->setStyleSheet("background-color: rgb(52, 178, 237);color: rgb(255,255,255);");
    }
}

void Dg_SelTime::back_Sheet()
{
    ui->ed_end->setStyleSheet("background-color: rgb(255,255,255);color: rgb(0,0,0);");
    ui->ed_start->setStyleSheet("background-color: rgb(255,255,255);color: rgb(0,0,0);");
}

QDate Dg_SelTime::last_Date()
{
    QDate current_date =QDate::currentDate();
    int month = current_date.month();
    int year = current_date.year();
    month -= 3;
    if(month <= 0){
        month += 12;
        year -= 1;
    }
    current_date.setDate(year, month, current_date.day());

    return current_date;
}



void Dg_SelTime::on_bt_today_clicked()
{
    ui->calendar_start->setSelectedDate(QDate::currentDate());

}

void Dg_SelTime::click_Start()
{
    QDate date = str_toDate(ui->ed_start->text());
    qDebug()<<date;
    ui->calendar_start->setSelectedDate(date);
    ui->wg_calendar->show();
    bt_type = false;
    changeSheet();
}

void Dg_SelTime::click_End()
{
    QDate date = str_toDate(ui->ed_end->text());
    qDebug()<<date;
    ui->calendar_start->setSelectedDate(date);
    ui->wg_calendar->show();
    bt_type = true;
    changeSheet();
}

void Dg_SelTime::on_bt_select_clicked()
{
    QDate date = ui->calendar_start->selectedDate();
    qDebug()<<date;
    ui->wg_calendar->hide();
    QDate date_start = str_toDate(ui->ed_start->text());
    QDate date_end = str_toDate(ui->ed_end->text());
    WG_Shade shade(mpshade);
    myDialog dialog;
    if(bt_type){
        if(date < date_start){
            dialog.set_icon_info(0, QString("终止日期不能小于起始日期"));
            dialog.exec();
            date = date_start;
        }

        ui->ed_end->setText(date.toString("yyyy-MM-dd"));
    }
    else{
        if(date > date_end){
            dialog.set_icon_info(0, QString("起始日期不能大于终止日期"));
            dialog.exec();
            date = date_end;
        }
        ui->ed_start->setText(date.toString("yyyy-MM-dd"));
    }
    back_Sheet();
}

void Dg_SelTime::on_bt_select_cancel_clicked()
{
    back_Sheet();
    ui->wg_calendar->hide();
}

void Dg_SelTime::on_bt_ok_clicked()
{
    m_date.clear();
    m_date.push_back(ui->ed_start->text());
    m_date.push_back(ui->ed_end->text());
    WG_Shade shade(mpshade);
    myDialog dialog;
    connect(&dialog, SIGNAL(sel_State(bool)), this, SLOT(is_Del(bool)));
    QString info = QString("确认删除%1至%2的全部数据吗？【不可恢复】").arg(m_date[0]).arg(m_date[1]);
    dialog.set_info(info);
    dialog.exec();

    //hide();
}

void Dg_SelTime::on_pushButton_3_clicked()
{
    hide();
}

void Dg_SelTime::is_Del(bool b)
{
    qDebug()<<"delete time";

    hide();

}
