#include "widget_progress.h"
#include "ui_widget_progress.h"

widget_progress::widget_progress(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widget_progress)
{
    ui->setupUi(this);
    m_level = 0;
}

widget_progress::~widget_progress()
{
    delete ui;
}

void widget_progress::set_level(int level)
{
    m_level = level > 100 ? 100 : level;//最大值不得大于100
    qDebug()<<"level:"<<m_level;
    this->repaint();
}

//进度条宽3，间隔3
void widget_progress::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);//该变量不在函数体内使用，用于抑制编译器警告。
    QPainter pa(this);

    pa.setPen(QColor(0,0,0));
   // pa.setBrush(QColor(0,0,0));
    pa.setBrush(QColor(153,255,0));
    //一个进度条的框大小3*25，框之间宽度为2，总长度610。610/5 = 122，所以百分之一：1.22
    for(int i = 0; i <= (m_level*1.22); i++)
        pa.drawRect(i*5,0,3,25);

}
