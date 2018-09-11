#ifndef WIDGET_PROGRESS_H
#define WIDGET_PROGRESS_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class widget_progress;
}

//510,30
class widget_progress : public QWidget
{
    Q_OBJECT

public:
    explicit widget_progress(QWidget *parent = 0);
    ~widget_progress();
    void set_level(int level);//设置层级。

private:
    Ui::widget_progress *ui;
    int m_level;
protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // WIDGET_PROGRESS_H
