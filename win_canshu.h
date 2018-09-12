#ifndef WIN_CANSHU_H
#define WIN_CANSHU_H

#include <QMainWindow>
#include<customtabstyle.h>
#include <dg_login.h>

namespace Ui {
class Win_Canshu;
}

class Win_Canshu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win_Canshu(QWidget *parent = 0);
    ~Win_Canshu();

private slots:
    void on_pushButton_5_clicked();

private:
    Ui::Win_Canshu *ui;
};

#endif // WIN_CANSHU_H
