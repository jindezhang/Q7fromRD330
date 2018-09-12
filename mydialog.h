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
