#include "win_kuaisu.h"
#include "ui_win_kuaisu.h"

Win_Kuaisu::Win_Kuaisu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win_Kuaisu)
{
    ui->setupUi(this);
    ui->wg_table->resize(QSize(750,400));
//    ui->wg_card->resize(QSize(140,100));

    Wg_Pic* wg_card = new Wg_Pic();
    QWidget *wg_card_part = new Wg_Pic();

    ui->H_layout->addWidget(wg_card_part,0,Qt::AlignRight);
    ui->H_layout->addWidget(wg_card,0,Qt::AlignRight);//向右边放置。
}

Win_Kuaisu::~Win_Kuaisu()
{
    delete ui;
}
