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

}

Dg_SelTime::~Dg_SelTime()
{
    delete ui;
}



void Dg_SelTime::on_bt_cancel_clicked()
{
    ui->wg_calendar->show();
}



void Dg_SelTime::init_Calendar()
{
    ui->wg_calendar->hide();

    ui->calendar_start->setMaximumDate(QDate::currentDate());
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

void Dg_SelTime::on_bt_select_clicked()
{
    QDate date = ui->calendar_start->selectedDate();
    qDebug()<<date;
    ui->wg_calendar->hide();
}
