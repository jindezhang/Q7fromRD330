#ifndef DG_SETTING_LONG_H
#define DG_SETTING_LONG_H

#include <QDialog>
#include<QPoint>
#include<QMenu>
#include<QAction>
#include<QTableWidgetItem>
#include<dg_setting_add.h>

namespace Ui {
class Dg_Setting_Long;
}
#pragma execution_character_set("utf-8")

class Dg_Setting_Long : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Setting_Long(QWidget *parent = 0);
    ~Dg_Setting_Long();

private slots:
    void on_pushButton_2_clicked();
    void init_Table();
    void show_contextMenu(QPoint pos);//右键菜单
    void action_mod();
    void action_add();
    QTableWidgetItem* add_row(QString &info);
    void action_del();

    void on_bt_canal_setting_clicked();

private:
    Ui::Dg_Setting_Long *ui;
    QMenu* cmenu;
};

#endif // DG_SETTING_LONG_H
