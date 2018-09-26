#ifndef WG_KS_TABLE_H
#define WG_KS_TABLE_H

#include <QWidget>
#include<QFont>
#include<QPushButton>
#include<QCheckBox>
#include<QVector>
#include<QDebug>
#include <QScrollBar>
#include<QTableWidgetItem>
#include<wg_kuaisu.h>
#include<dg_input.h>

namespace Ui {
class wg_ks_table;
}
#pragma execution_character_set("utf-8")

class wg_ks_table : public QWidget
{
    Q_OBJECT

public:
    explicit wg_ks_table(QWidget *parent = 0);
    ~wg_ks_table();


public slots:
    void sel_Row(int row);//定位到某一行
    void sel_Value(QString row);//通过值定位到某一行
    void sel_Value(int row);//重载

signals:
    void row_sel(int row);
private slots:
    void click_Check(int row, int col);//点击了列表复选框的槽函数,复选框用图标表示.同时表示点击某行
    void click_Item(int row);//单击选择某行
    void click_double_Item(QModelIndex item);//双击,显示样本信息
private:
    void set_value(QString &value, int row = 1, int col = 1);//设置表格内容并且居中显示
    void build_tableHead();//建立表单,并且表格初始化
    void build_tableChecked(int pa_col);//初始化表单的复选框

private:
    Ui::wg_ks_table *ui;
    QVector<bool> v_check;//用于保存选中的行数据的选中。
    Dg_Input kuai;
};

#endif // WG_KS_TABLE_H
