#include "l_pic.h"

L_Pic::L_Pic( QWidget *widget): QLabel(widget)
{
    m_index = -1;
    m_x = 0;
    m_y = 0;
    m_type = 0;

    m_common = (long double)size().height() / 1003;
    repaint();
}

void L_Pic::set_type(int pa_type)
{
    m_type = pa_type;
}

void L_Pic::set_Index(int pa_index)
{
    m_index = pa_index;
}

void L_Pic::label_Update()
{
    update();
}

void L_Pic::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    update();
}

void L_Pic::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    QPainter painter(this);
    int tmp_x;
    int tmp_y;
    int tmp_w;
    int tmp_h;
    long double common = m_common;//缩放因子
    //右图才会画框
    if((-1 != m_index)){
        //画框
//        qDebug() << "m_index" << m_index;
//        long double common = m_common;//缩放因子
//        common = (long double)size().height() / 1003;

        painter.setPen(QColor(Qt::red));

        tmp_x = (m_index * 139 + 166) * common;
        tmp_y = 353 * common;
        tmp_w = 139 * common;
        tmp_h = 617 * common;
//        qDebug() << "tmp_x" << tmp_x;
//        qDebug() <<"tmp_y" <<tmp_y;

        painter.drawRect(tmp_x, tmp_y, tmp_w, tmp_h);
    }

    if(m_type == 1){
        //画框 1144 * 624
    //        qDebug() << "m_index" << m_index;

        painter.setPen(QColor(Qt::red));
        tmp_x = 166 * common + m_x;
        tmp_y = 353 * common + m_y;
        tmp_w = 1144 * common;
        tmp_h = 624 * common;
        m_rect.setRect(tmp_x, tmp_y, tmp_w, tmp_h);
//        qDebug()<<"pic rect"<<m_rect;
        painter.drawRect(tmp_x, tmp_y, tmp_w, tmp_h);
    }
}

void L_Pic::move_Top()
{
    m_y--;
    update();
}

void L_Pic::move_Left()
{
    m_x--;
    update();
}

void L_Pic::move_Down()
{
    m_y++;
    update();
}

void L_Pic::move_Right()
{
    m_x++;
    update();
}

QRectF L_Pic::get_Rect()
{
    return m_rect;
}
