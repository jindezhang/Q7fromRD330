#ifndef DG_OUTSETTING_H
#define DG_OUTSETTING_H

#include <QDialog>
#include<QMap>
#include<qDebug>

namespace Ui {
class Dg_OutSetting;
}

class Dg_OutSetting : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_OutSetting(QWidget *parent = 0);
    ~Dg_OutSetting();
    QMap<QString, int> get_Value();//获取选择的值。
private slots:
    void on_pushButton_2_clicked();

    void on_bt_cancal_clicked();

    void on_bt_ok_clicked();

private:
    Ui::Dg_OutSetting *ui;
    QMap<QString, int> m_value;//用于保存勾选的值。0 unchecked; 2 checked;
};

#endif // DG_OUTSETTING_H
