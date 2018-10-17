#ifndef DATA_H
#define DATA_H

#include <QWidget>
#include <dg_seltime.h>

namespace Ui {
class Data;
}

//"序号"
//"日期"
//"报表"
//"检验医师"
//"检验地址"
//"测试卡"
//"样品编号"
//"项目编号"
//"结果"
//"参考区间"
//"批次"
//"姓名"
//"性别"
//"年龄"
//"住院号"
//"样本类型"
//"患者类型"
//"科室"
//"床号"
//"送检医师"
//"审核者"
//"警示"
//"备注"

#include<QSqlQueryModel>
#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QMainWindow>

class Data : public QMainWindow
{
    Q_OBJECT

public:
    explicit Data(QWidget *parent = 0);
    ~Data();
private slots:
    void OnPrevButtonClick();//上一页功能
    void OnNextButtonClick();//下一页功能
    void OnSwitchPageButtonClick();//跳转页功能
    void on_pushButton_15_clicked();

    void on_bt_del_clicked();

private:
    void SetTableView();//设置表格
    void setTableHeader();//设置表头
    int  GetTotalRecordCount();//得到记录数
    int  GetPageCount();//得到页数
    void RecordQuery(int limitIndex); //记录查询
    void UpdateStatus();//刷新状态
    void SetTotalPageLabel(); //设置总数页文本
    QString toStr(int i);
private:
    Ui::Data *ui;
    QSqlQueryModel *queryModel;//查询模型
    int       currentPage;      //当前页
    int       totalPage;    //总页数
    int       totalRecrodCount;     //总记录数
    enum      {PageRecordCount = 5};//每页显示记录数
    QWidget *mpShade;
};

#endif // DATA_H
