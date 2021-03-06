﻿#include "wg_ks_table.h"
#include "ui_wg_ks_table.h"

wg_ks_table::wg_ks_table(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wg_ks_table)
{
    ui->setupUi(this);
    connect(ui->tableWidget, SIGNAL(cellPressed(int,int)), this, SLOT(click_Check(int,int)));
    build_tableHead();

    //connect(ui->tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(click_Item(QTableWidgetItem*)));
    //double click
    connect(ui->tableWidget, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(click_double_Item(QModelIndex)));

//    mpshade = init_Shade(parent);
//    mpshade->resize(1024, 700);
}

wg_ks_table::~wg_ks_table()
{
//    delete mpshade;
    delete ui;
}

void wg_ks_table::sel_Row(int row)
{
//    ui->tableWidget->verticalScrollBar()->setSliderPosition(row);
    ui->tableWidget->selectRow(row);
    //    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void wg_ks_table::sel_Value(QString row)
{
    QList<QTableWidgetItem *> tmp_item = ui->tableWidget->findItems(row, Qt::MatchContains);
    for(int i = 0; i < tmp_item.count(); i++){
        //qDebug()<<tmp_item.at(i)->row();//输出行号
        ui->tableWidget->selectRow(tmp_item.at(i)->row());
    }
}

void wg_ks_table::sel_Value(int row)
{
    QString rows = QString("%1").arg(row+1);
    QList<QTableWidgetItem *> tmp_item = ui->tableWidget->findItems(rows, Qt::MatchContains);
    for(int i = 0; i < tmp_item.count(); i++){
        //qDebug()<<tmp_item.at(i)->row();//输出行号
        ui->tableWidget->selectRow(tmp_item.at(i)->row());
    }
}

void wg_ks_table::click_Check(int row, int col)
{
    click_Item(row);
    //qDebug()<<row<<" "<<col;
    //如果不是第一列，那么返回。
    if(col != 0)
        return;

    QTableWidgetItem* item;
    item = new QTableWidgetItem();
    QString tmp_path;
    if(v_check[row])
       tmp_path = ":/new/home/home/unchecked.png";
    else
       tmp_path = ":/new/home/home/checked.png";

    item->setIcon(QIcon(QPixmap(tmp_path)));
    ui->tableWidget->setItem(row, 0, item);
    v_check[row] = !v_check[row];
}

void wg_ks_table::click_Item(int row)
{
    QTableWidget * tmp_item = ui->tableWidget;
    while(tmp_item->item(row, 1) == 0)
        row--;
    emit row_sel(tmp_item->item(row, 1)->text().toInt()-1);
//    qDebug()<<"click item"<<tmp_item->item(row, 1)->text();
}


void wg_ks_table::click_double_Item(QModelIndex item)
{
    Q_UNUSED(item);
    emit sig_shade(true);
//    WG_Shade shade(mpshade);
    kuai.exec();
    emit sig_shade(false);
}

void wg_ks_table::build_tableHead()
{

   QStringList head_list;
   head_list<<"导出  "  ;
    head_list<<"卡编号 " ;
    head_list<<"测试卡 " ;
    head_list<<"项目名称" ;
    head_list<<"结果  " ;
    head_list<<"参考区间" ;
    head_list<<"样品编号" ;
    head_list<<"备注"   ;
    head_list<<"批次"   ;
    ui->tableWidget->setRowCount(25);
    ui->tableWidget->setColumnCount(head_list.count());
    ui->tableWidget->setHorizontalHeaderLabels(head_list);

    //表头字体加粗
    QFont font = ui->tableWidget->horizontalHeader()->font();
    font.setBold(true);
    font.setPointSize(11);
    ui->tableWidget->horizontalHeader()->setFont(font);

    //设置表头背景样式  设置表头字体，颜色，模式
    ui->tableWidget->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:lightgray;color: black;"
                                                       "padding-left: 4px;border: 1px solid #6c6c6c;"
                                                       "font:11pt '宋体';}");
    //设置表头宽度
    ui->tableWidget->horizontalHeader()->setFixedHeight(26);

    //设置内容居中
    QString tmp_value;
    for(int i = 7; i >= 0; i--){
        tmp_value = QString("%1").arg(i+1);
        set_value(tmp_value, i, 1);
    }

    //设置列宽
    for(int i = 1; i<head_list.count(); i++)
       ui->tableWidget->setColumnWidth(i,ui->tableWidget->width()/head_list.count());
    qDebug()<<"widget:"<<ui->tableWidget->width()/head_list.count();
    //隐藏旁边的数字，去掉默认自带的行号
    ui->tableWidget->verticalHeader()->setHidden(true);

    //添加复选框，并且设置大小
    build_tableChecked(25);
    ui->tableWidget->setIconSize(QSize(23, 23));


    //设置表单中字体
    font.setBold(false);
    //font.setPointSize(11);
    ui->tableWidget->setFont(font);

    //禁止编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    //行列自适应,★★★先装载数据，再自适应。
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->resizeRowsToContents();


    //每隔一行换一个颜色，一恢一白 setAlternatingRowColors(true);
    ui->tableWidget->setAlternatingRowColors(true);

    //任意单击都选中一行  setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    //充满窗体,水平方向和垂直方向
   // ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    //ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //表头最后一行会自动拉伸，也可以实现充满窗体的效果
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //设置单元中的字体格式
//    ui.qtablewidget->item(1, 0)->setBackgroundColor(QColor(0,60,10));
//    ui.qtablewidget->item(1, 0)->setTextColor(QColor(200,111,100));
//    ui.qtablewidget->item(1, 0)->setFont(QFont("Helvetica"));

}

void wg_ks_table::build_tableChecked(int pa_col)
{
    QTableWidgetItem *item;
    do{
    item = new QTableWidgetItem();
    item->setIcon(QIcon(QPixmap(":/new/home/home/checked.png")));
    ui->tableWidget->setItem(pa_col, 0, item);
    v_check.push_back(true);
    } while (pa_col--) ;

}

void wg_ks_table::set_value(QString &value, int row, int col)
{
    ui->tableWidget->setItem(row, col, new QTableWidgetItem(value));
    ui->tableWidget->item(row, col)->setTextAlignment(Qt::AlignCenter);

}
