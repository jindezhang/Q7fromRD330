#include "win_kuaisu.h"
#include "ui_win_kuaisu.h"

Win_Kuaisu::Win_Kuaisu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win_Kuaisu)
{
    ui->setupUi(this);
//    ui->wg_table->resize(QSize(750,400));
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
//    ui->wg_card->resize(QSize(140,100));

    qDebug()<<"win_kuaisu";
    //设置图片
    Wg_Pic* wg_card = new Wg_Pic(true);
    Wg_Pic* wg_card_part = new Wg_Pic();

    //三个窗体之间互相传递数据
    //wg_card is role
    connect(wg_card, SIGNAL(pic_index(int)), wg_card_part, SLOT(index_get(int)));
    connect(wg_card, SIGNAL(pic_index(int)), ui->wg_table, SLOT(sel_Value(int)));
    //table is role
    connect(ui->wg_table, SIGNAL(row_sel(int)), wg_card_part, SLOT(index_get(int)));
    connect(ui->wg_table, SIGNAL(row_sel(int)), wg_card, SLOT(index_get(int)));
    //右图
    QString path(":/new/home/home/q7.bmp");
    wg_card->set_Pixmap(path);
    wg_card->show_Pixmap();
    wg_card->setTotalwidht(966);
    QSize tmp_s;
    tmp_s.rheight() = 160;
    tmp_s.rwidth() = 7*tmp_s.height()/5;
   // wg_card->resize(tmp_s);


    wg_card_part->set_Index(0);
    wg_card_part->set_Pixmap(path);
    wg_card_part->show_Pixmap();

    ui->H_layout->addWidget(wg_card_part);
    ui->H_layout->addStretch();//添加弹簧
    ui->H_layout->addWidget(wg_card);//
    ui->wg_card->resize(tmp_s);

//    ui->wg_table->sel_Row(20);

}

Win_Kuaisu::~Win_Kuaisu()
{
    delete ui;
}

void Win_Kuaisu::on_pushButton_16_clicked()
{
    this->parentWidget()->show();
    this->close();
}

