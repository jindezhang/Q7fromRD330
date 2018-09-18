#ifndef WG_KUAISU_H
#define WG_KUAISU_H

#include <QWidget>
#include <QVector>
#include <QTextEdit>
#include <QLabel>
#include<QComboBox>
#include<QFormLayout>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QRegExpValidator>

namespace Ui {
class wg_kuaisu;
}

class wg_kuaisu : public QWidget
{
    Q_OBJECT

public:
    explicit wg_kuaisu(QWidget *parent = 0);
    ~wg_kuaisu();

private slots:
    void on_bt_ok_clicked();

    void on_bt_cancel_clicked();

    void on_bt_cancel_2_clicked();

private:
    QVector<QLineEdit *> v_ed;
    QComboBox* cbb_gender;
    QComboBox* cbb_age;
    Ui::wg_kuaisu *ui;
};

#endif // WG_KUAISU_H
