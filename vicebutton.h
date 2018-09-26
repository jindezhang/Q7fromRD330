#ifndef VICEBUTTON_H
#define VICEBUTTON_H

#include <QWidget>
#include<QPushButton>

//在功能模块区内的按钮，便于修改样式.参考MainButton
class ViceButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ViceButton(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // VICEBUTTON_H
