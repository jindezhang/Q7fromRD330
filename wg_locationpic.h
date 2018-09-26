#ifndef WG_LOCATIONPIC_H
#define WG_LOCATIONPIC_H

#include <QWidget>
#include <QPixmap>
#include<QPainter>
#include<QColor>
#include<QDebug>

namespace Ui {
class Wg_locationPic;
}


//返回坐标值和缩放因子给其他对象。

class Wg_locationPic : public QWidget
{
    Q_OBJECT

public:
    explicit Wg_locationPic(QWidget *parent = 0);
    ~Wg_locationPic();
    void set_Pixmap(QPixmap & pix);
    void move_Top();
    void move_Left();
    void move_Down();
    void move_Right();
private:
    void paintEvent(QPaintEvent *event);
private:
    Ui::Wg_locationPic *ui;
    int m_x;
    int m_y;
};

#endif // WG_LOCATIONPIC_H
