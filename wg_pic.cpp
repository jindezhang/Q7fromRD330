#include "wg_pic.h"
#include "ui_wg_pic.h"

Wg_Pic::Wg_Pic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wg_Pic)
{
    ui->setupUi(this);

}

Wg_Pic::~Wg_Pic()
{
    delete ui;
}

void Wg_Pic::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    qDebug()<<size.height();

    this->resize(QSize((7*size.height()/5), size.height()));
}
