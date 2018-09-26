#ifndef DG_SETTING_ADD_H
#define DG_SETTING_ADD_H

#include <QDialog>

namespace Ui {
class Dg_Setting_add;
}

class Dg_Setting_add : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Setting_add(QString id = 0000, QWidget *parent = 0);
    ~Dg_Setting_add();
    void set_CardID(QString id);//设置卡的ID；
private slots:
    void on_pushButton_2_clicked();

    void on_bt_canal_setting_clicked();

    void on_bt_save_setting_clicked();

private:
    Ui::Dg_Setting_add *ui;
};

#endif // DG_SETTING_ADD_H
