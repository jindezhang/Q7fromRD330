#ifndef WG_CANSHU_H
#define WG_CANSHU_H

#include <QWidget>
#include<QFileDialog>

namespace Ui {
class Wg_canshu;
}

class Wg_canshu : public QWidget
{
    Q_OBJECT

public:
    explicit Wg_canshu(QWidget *parent = 0);
    ~Wg_canshu();

private slots:


    void on_bt_file_clicked();

    void on_bt_savePath_clicked();

private:
    Ui::Wg_canshu *ui;
};

#endif // WG_CANSHU_H
