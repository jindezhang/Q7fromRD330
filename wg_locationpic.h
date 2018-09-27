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


//★★★★★不再使用该类，转为L_Pic.class

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
    long double common;//缩放因子
};

#endif // WG_LOCATIONPIC_H
