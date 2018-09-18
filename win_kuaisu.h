#ifndef WIN_KUAISU_H
#define WIN_KUAISU_H

#include <QDebug>
#include <QMainWindow>
#include <QSize>
#include "wg_pic.h"

#pragma execution_character_set("utf-8")
namespace Ui {
class Win_Kuaisu;
}



//"导出  "
//"卡编号 "
//"测试卡 "
//"项目名称"
//"结果  "
//"参考区间"
//"样品编号"
//"备注"
//"批次"

class Win_Kuaisu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win_Kuaisu(QWidget *parent = 0);
    ~Win_Kuaisu();

private slots:
    void on_pushButton_16_clicked();

private:
    Ui::Win_Kuaisu *ui;
};

#endif // WIN_KUAISU_H
