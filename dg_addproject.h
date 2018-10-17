#ifndef DG_ADDPROJECT_H
#define DG_ADDPROJECT_H

#include <QDialog>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QStandardItemModel>
#include<QStandardItem>
#include<QModelIndexList>
#include<QDebug>
#include<QList>
#include<dg_addpro.h>
#include<mydialog.h>
#include<QRegExpValidator>
#include<QRegExp>
#include "wg_shade.h"

#pragma execution_character_set("utf-8")
namespace Ui {
class Dg_AddProject;
}

class Dg_AddProject : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_AddProject(QWidget *parent = 0);
    ~Dg_AddProject();

private slots:
    void on_pushButton_2_clicked();

    void on_bt_ok_clicked();
    void init_ListView();
    void click_list(QModelIndex model);//点击list项，可以选中，可以多选。
    void on_bt_move_clicked();//选中的都会移动过去
    void add_Text(QStringList &info);//添加项目，并且不会重复项。
    bool check_CardID();//检查卡的id
    void on_bt_clear_clicked();

    void on_bt_add_clicked();

private:
    Ui::Dg_AddProject *ui;
    QStringList m_select;
    QWidget* mpshade;
};

#endif // DG_ADDPROJECT_H
