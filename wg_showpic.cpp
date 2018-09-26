#include "wg_showpic.h"
#include "ui_wg_showpic.h"

Wg_ShowPic::Wg_ShowPic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wg_ShowPic)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    ui->setupUi(this);

    //lable中图片自适应
    ui->l_left->setScaledContents(true);
    ui->label->setScaledContents(true);

}

Wg_ShowPic::~Wg_ShowPic()
{
    delete ui;
}

void Wg_ShowPic::set_pic(bool pa_type, QPixmap &pa_pix)
{
    //总宽是980*656
    //左图617 * 139 --> 980 * 221
    //右图2480 * 1748 -->931 * 656
    if(!pa_type)
        ui->l_left->setPixmap(pa_pix);
    else
        ui->label->setPixmap(pa_pix);
}

void Wg_ShowPic::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    hide();
}
