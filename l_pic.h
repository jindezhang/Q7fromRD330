#ifndef L_PIC_H
#define L_PIC_H

#include<QLabel>
#include <QPainter>
#include <QColor>
#include<QDebug>
#include<QRectF>

class L_Pic : public QLabel
{
    Q_OBJECT
public:
    //type 默认时候，是给快速检测模块。1 是图片静态定位
    explicit L_Pic(QWidget * widget = nullptr);
    void set_type(int pa_type);
    void set_Index(int pa_index);
    void label_Update();//用于更新框框
    void move_Top();
    void move_Left();
    void move_Down();
    void move_Right();
    QRectF get_Rect();
private:
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *event);

private:
    int m_index;
    int m_x;
    int m_y;
    int m_type;
    QRectF m_rect;
    long double m_common;//缩放因子
};

#endif // L_PIC_H
