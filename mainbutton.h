#ifndef MAINBUTTON_H
#define MAINBUTTON_H

#include <QPushButton>
#include<QWidget>

//在界面上上的按钮，便于修改样式，参考ViceButton
class MainButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MainButton(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // MAINBUTTON_H
