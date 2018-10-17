#include "dg_piclocation.h"
#include "ui_dg_piclocation.h"

Dg_PicLocation::Dg_PicLocation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_PicLocation)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    ui->l_pic_piclocation->set_type(1);
    load_Pixmap();

    //按钮长按也可以移动。原生态的按钮没有这个功能，但是可以通过pressed + click + QTimer来设置。
//    connect(ui->pushButton, SIGNAL(pressed()), this, SLOT(on_pushButton_clicked()));

}

Dg_PicLocation::~Dg_PicLocation()
{
    delete ui;
}

void Dg_PicLocation::load_Pixmap()
{
    QPixmap tmp_pix(":/new/home/home/q7.bmp");
    ui->l_pic_piclocation->setScaledContents(true);
    ui->l_pic_piclocation->setPixmap(tmp_pix);
}

void Dg_PicLocation::on_bt_up_clicked()
{
    ui->l_pic_piclocation->move_Top();
}

void Dg_PicLocation::on_pushButton_2_clicked()
{
    ui->l_pic_piclocation->move_Down();
}

void Dg_PicLocation::on_pushButton_16_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void Dg_PicLocation::on_pushButton_3_clicked()
{
    ui->l_pic_piclocation->move_Left();
}

void Dg_PicLocation::on_pushButton_4_clicked()
{
    ui->l_pic_piclocation->move_Right();
}



void Dg_PicLocation::on_bt_down_clicked()
{
    on_pushButton_2_clicked();
}

void Dg_PicLocation::on_bt_left_clicked()
{
    on_pushButton_3_clicked();
}

void Dg_PicLocation::on_bt_right_clicked()
{
    on_pushButton_4_clicked();
}
