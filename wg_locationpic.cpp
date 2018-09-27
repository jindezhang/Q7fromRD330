#include "wg_locationpic.h"
#include "ui_wg_locationpic.h"

Wg_locationPic::Wg_locationPic(QWidget *parent) :
    QWidget(parent),m_x(0),m_y(0),
    ui(new Ui::Wg_locationPic)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);


    common = (long double)size().height() / 1003;
}

Wg_locationPic::~Wg_locationPic()
{
    delete ui;
}

void Wg_locationPic::set_Pixmap(QPixmap &pix)
{
    ui->label->setPixmap(pix);
    this->repaint();
}

void Wg_locationPic::move_Top()
{
    m_y--;
    update();
}

void Wg_locationPic::move_Left()
{
    m_x--;
    update();
}

void Wg_locationPic::move_Down()
{
    m_y++;
    update();
}

void Wg_locationPic::move_Right()
{
    m_x++;
    update();
}

void Wg_locationPic::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    //画框 1144 * 624
//        qDebug() << "m_index" << m_index;


    QPainter painter(this);
    painter.setPen(QColor(Qt::red));
    int tmp_x = 166 * common + m_x;
    int tmp_y = 353 * common + m_y;
    int tmp_w = 1144 * common;
    int tmp_h = 624 * common;
//        qDebug() << "tmp_x" << tmp_w;
//        qDebug() <<"tmp_y" <<tmp_h;

    painter.drawRect(tmp_x, tmp_y, tmp_w, tmp_h);
}
