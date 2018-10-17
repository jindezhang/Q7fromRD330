#ifndef DG_PICLOCATION_H
#define DG_PICLOCATION_H

#include <QDialog>

namespace Ui {
class Dg_PicLocation;
}

class Dg_PicLocation : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_PicLocation(QWidget *parent = 0);
    ~Dg_PicLocation();
public slots:
    void load_Pixmap();//加载图片
private slots:

    void on_bt_up_clicked();//上

    void on_pushButton_2_clicked();//下

    void on_pushButton_16_clicked();

    void on_pushButton_3_clicked();//左

    void on_pushButton_4_clicked();//右


    void on_bt_down_clicked();

    void on_bt_left_clicked();

    void on_bt_right_clicked();

private:
    Ui::Dg_PicLocation *ui;
};

#endif // DG_PICLOCATION_H
