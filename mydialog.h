#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include<QPalette>
#include<QPainter>
#include<QPen>
#include<QColor>
#include<QRectF>


namespace Ui {
class myDialog;
}

class myDialog : public QDialog
{
    Q_OBJECT

public:
    explicit myDialog(QWidget *parent = 0);
    ~myDialog();
    void set_info(QString& info);//提示信息。
    void set_icon(int type);//更换图标，默认是info，0是warning，1是successful；
    void set_value(QString info);//提示信息,用于表单ListView的数据显示

private slots:
    void on_pushButton_2_clicked();
    void on_bt_ok_clicked();

    void on_bt_cancel_clicked();

signals:
    void sel_State(bool b);
private:
    void paintEvent(QPaintEvent *event);


private:
    Ui::myDialog *ui;
};

#endif // MYDIALOG_H
