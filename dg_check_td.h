#ifndef DG_CHECK_TD_H
#define DG_CHECK_TD_H

#include <QDialog>

namespace Ui {
class Dg_Check_td;
}
#pragma execution_character_set("utf-8")
class Dg_Check_td : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Check_td(QWidget *parent = 0);
    ~Dg_Check_td();

private slots:
    void on_pushButton_2_clicked();
    void init_Table();
private:
    Ui::Dg_Check_td *ui;
};

#endif // DG_CHECK_TD_H
