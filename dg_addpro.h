#ifndef DG_ADDPRO_H
#define DG_ADDPRO_H

#include <QDialog>

namespace Ui {
class Dg_AddPro;
}

class Dg_AddPro : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_AddPro(QWidget *parent = 0);
    ~Dg_AddPro();

private slots:
    void on_pushButton_2_clicked();

    void on_bt_canal_clicked();

    void on_bt_ok_clicked();

private:
    Ui::Dg_AddPro *ui;
};

#endif // DG_ADDPRO_H
