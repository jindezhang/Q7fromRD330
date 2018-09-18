#include "l_pic.h"

L_Pic::L_Pic(QWidget *widget): QLabel(widget)
{
    m_index = -1;
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
    update();
}

void L_Pic::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);
    //右图才会画框
    if((-1 != m_index)){
        //画框
//        qDebug() << "m_index" << m_index;
        long double common;//缩放因子
        common = (long double)size().height() / 1003;
        QPainter painter(this);
        painter.setPen(QColor(Qt::red));

        int tmp_x = (m_index * 139 + 166) * common;
        int tmp_y = 353 * common;
        int tmp_w = 139 * common;
        int tmp_h = 617 * common;
//        qDebug() << "tmp_x" << tmp_x;
//        qDebug() <<"tmp_y" <<tmp_y;

        painter.drawRect(tmp_x, tmp_y, tmp_w, tmp_h);
    }
}
