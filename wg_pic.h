#ifndef WG_PIC_H
#define WG_PIC_H

#include <QWidget>
#include<QResizeEvent>
#include<QSize>
#include<qDebug>
#include<QRect>
#include<QPainter>
#include<QPixmap>
#include<QTransform>
#include<QLabel>
#include <QPen>
#include<QColor>
#include<Qt>
#include<wg_showpic.h>

//通过信号的方式去替换选择测试卡
//右图最大h = 174
namespace Ui {
class Wg_Pic;
}

class Wg_Pic : public QWidget
{
    Q_OBJECT

public:
    explicit Wg_Pic(bool picType = false,QWidget *parent = 0);//picType 左图为默认，右图为true；
    ~Wg_Pic();
    void setTotalwidht(int pa_widtht);//设置外围总宽度，用于图片的反向变化。x值
    void set_BackgrandColor(QString pa_color);//传入颜色即可：rgd.../十六进制值。
    void set_Pixmap(const QString &pa_path);//设置图片路径
    void show_Pixmap();
    void set_Index(int index);//第几张照片。
    int get_Index();

signals:
    void pic_index(int index);//点击了第几张图片，发送信号。从0开始
public slots:
    void index_get(int index);//选中第几张测试卡
private:
    void resizeEvent(QResizeEvent *event);//当窗体大小变化的时候，触发的槽函数。
    void paintEvent(QPaintEvent *event);//重绘窗体
    void mousePressEvent(QMouseEvent *event);//重载鼠标点击事件。
    void mouseDoubleClickEvent(QMouseEvent * e);//双击
    int select_Pic(int x, int y);//点击选图算法,非点击测试卡返回-1；其他情况返回对应的测试卡，传入点击坐标数

private:

    Ui::Wg_Pic *ui;
    bool pic_Type;//左图还是右图，右图为ture，左图默认
//    int pic_width;//
    //int pic_height;
//    QString m_backcolor;
    int m_total_widht;//外围窗体的总宽度
    int m_index;//需要显示的第几张测试卡
    QSize m_size;//窗体的大小值，用于点击选图算法。
    QPixmap *m_pix;//图片
    Wg_ShowPic m_pic;//显示窗体
};

#endif // WG_PIC_H
