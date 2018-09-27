#ifndef WG_SEARCHLINE_H
#define WG_SEARCHLINE_H

#include <QWidget>
#include<QPushButton>
#include<QLineEdit>
#include<QMargins>
#include<QHBoxLayout>
#include<QMessageBox>

class Wg_SearchLine : public QLineEdit
{
    Q_OBJECT
public:
    explicit Wg_SearchLine(QWidget *parent = nullptr);

signals:
    void bt_click(QString info);//按钮被点击；
private slots:
    void search();//点击按钮
private:

};

#endif // WG_SEARCHLINE_H
