#ifndef WG_WEIHU_H
#define WG_WEIHU_H

#include<mydialog.h>

#include <QWidget>
#include<QSqlQuery>
#include<QStandardItemModel>
#include<QStandardItem>
#include<QDebug>
#include<QSqlDatabase>
#include<QFont>
#include<dg_piclocation.h>
#include<dg_check_yq.h>
#include<dg_check_td.h>
#include<dg_setting_long.h>
#include<dg_addproject.h>

namespace Ui {
class Wg_WeiHu;
}

class Wg_WeiHu : public QWidget
{
    Q_OBJECT

public:
    explicit Wg_WeiHu(QWidget *parent = 0);
    ~Wg_WeiHu();

private slots:
    void click_List();
    void on_bt_pic_weihu_clicked();

    void on_bt_yiqi_weihu_clicked();

    void on_bt_tongdao_weihu_clicked();

    void on_bt_shezhi_weihu_clicked();

    void on_bt_add_weihu_clicked();

private:
    void init_ListView();//初始化ListView
private:
    Ui::Wg_WeiHu *ui;
    QWidget* mpShade;
};

#endif // WG_WEIHU_H
