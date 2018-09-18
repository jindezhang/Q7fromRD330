#ifndef DG_INPUT_H
#define DG_INPUT_H

#include <QDialog>
#include <QVector>
#include <QTextEdit>
#include <QLabel>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QRegExpValidator>

namespace Ui {
class Dg_Input;
}

class Dg_Input : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Input(QWidget *parent = 0);
    ~Dg_Input();

private slots:
    void on_bt_ok_clicked();

    void on_bt_cancel_clicked();

    void on_bt_cancel_2_clicked();

private:
    Ui::Dg_Input *ui;
    QVector<QLineEdit *> v_ed;
    QComboBox* cbb_gender;
    QComboBox* cbb_age;
};

#endif // DG_INPUT_H
