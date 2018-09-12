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
    m_level = level;
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
    for(int i = 0; i <= m_level; i++)
        pa.drawRect(i*5,0,3,25);


}
