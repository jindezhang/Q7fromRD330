#include "mydialog.h"
#include "ui_mydialog.h"

myDialog::myDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::myDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//窗体无边框，无法移动。
    //背景色透明
//    QPalette pal = palette();
//    pal.setColor(QPalette::Background, QColor(0x00,0xff,0x00,0x00));
//    setPalette(pal);

    //会自动调用paintEvent();
    this->repaint();

    //QLabel 自动换行
    //ui->l_tips->setGeometry(QRect(328, 240, 329, 27*4)); //四倍行距
    ui->l_tips->setWordWrap(true);
    ui->l_tips->setAlignment(Qt::AlignTop);
}

myDialog::~myDialog()
{
    delete ui;
}


void myDialog::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);//该变量不在函数体内使用，用于抑制编译器警告。

    //画框框
    QPainter painter(this);
    painter.setPen(QColor(52, 178, 237));

    QRectF rec(20,80,348,152);
    painter.drawRoundedRect(rec, 20.0, 20.0);

}

void myDialog::on_pushButton_2_clicked()
{
    this->close();
}

void myDialog::on_bt_ok_clicked()
{
    emit sel_State(true);
}

void myDialog::on_bt_cancel_clicked()
{
    emit sel_State(false);
}
