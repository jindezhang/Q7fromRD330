#ifndef WG_CANSHU_H
#define WG_CANSHU_H

#include <QWidget>
#include<QFileDialog>
#include<dg_outsetting.h>
#include <QDebug>

namespace Ui {
class Wg_canshu;
}

class Wg_canshu : public QWidget
{
    Q_OBJECT

public:
    explicit Wg_canshu(QWidget *parent = 0);
    ~Wg_canshu();

private slots:

    void set_cbb(bool b);//设置串口输出的选项状态
    void on_bt_file_clicked();

    void on_bt_savePath_clicked();

    void on_pushButton_clicked();

    void on_checkBox_5_clicked(bool checked);

private:
    Ui::Wg_canshu *ui;
};

#endif // WG_CANSHU_H
