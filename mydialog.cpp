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
    ui->l_tips2->setWordWrap(true);

    //回车按键
//    QShortcut *key=new QShortcut(QKeySequence(Qt::Key_Return),this);//创建一个快捷键"Key_Return"键

//    connect(key,SIGNAL(activated()),this,SLOT(槽函数));//连接到指定槽函数
    ui->l_tips2->setFont(QFont("楷体", 11, 50));
}

myDialog::~myDialog()
{
    delete ui;
}

void myDialog::set_info(QString &info)
{
    ui->l_tips->setText(info);
}

void myDialog::set_icon(int type)
{
    switch (type) {
    case 1:
        ui->l_icon->setStyleSheet("background-image: url(:/new/home/home/sucess.png);");
        break;
    case 0:
        ui->l_icon->setStyleSheet("background-image: url(:/new/home/home/warning.png);");
        break;
    default:
        break;
    }
}

void myDialog::set_value(QString info)
{

    ui->l_tips2->setText(info);
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
    hide();
}

void myDialog::on_bt_ok_clicked()
{
    emit sel_State(true);
    hide();
}

void myDialog::on_bt_cancel_clicked()
{
    emit sel_State(false);
    hide();
}
