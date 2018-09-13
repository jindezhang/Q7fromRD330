#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QObject>
#include <QWidget>
#include <QSize>
#include<QResizeEvent>

class My_Label : public QWidget
{
    Q_OBJECT
public:
    My_Label(QWidget *parent = 0);

protected:
//    void QResizeEvent()
    void resizeEvent(QResizeEvent *event);
};

#endif // MY_LABEL_H
