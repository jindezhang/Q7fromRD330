#ifndef L_PIC_H
#define L_PIC_H

#include<QLabel>
#include <QPainter>
#include <QColor>
#include<QDebug>

class L_Pic : public QLabel
{
    Q_OBJECT
public:
    explicit L_Pic(QWidget * widget = nullptr);
    void set_Index(int pa_index);
    void label_Update();//用于更新框框
private:
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *event);

private:
    int m_index;
};

#endif // L_PIC_H
