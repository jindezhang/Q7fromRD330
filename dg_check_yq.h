#ifndef DG_CHECK_YQ_H
#define DG_CHECK_YQ_H

#include <QDialog>

namespace Ui {
class Dg_Check_yq;
}
#pragma execution_character_set("utf-8")
class Dg_Check_yq : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Check_yq(QWidget *parent = 0);
    ~Dg_Check_yq();
private slots:
    void on_pushButton_2_clicked();

    void on_bt_collect_clicked();

    void on_bt_start_clicked();

private:
    void init_Table();
private:
    Ui::Dg_Check_yq *ui;
};

#endif // DG_CHECK_YQ_H
