#include "dg_check_yq.h"
#include "ui_dg_check_yq.h"

Dg_Check_yq::Dg_Check_yq(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Check_yq)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    init_Table();
}

Dg_Check_yq::~Dg_Check_yq()
{
    delete ui;
}

void Dg_Check_yq::init_Table()
{
    QStringList head_list;
    head_list<<"校验机校验数据  "  ;
     head_list<<"本机通道1数据 " ;
     //ui->tableWidget->setRowCount(8);
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

     //隐藏旁边的数字，去掉默认自带的行号
     ui->tableWidget->verticalHeader()->setHidden(true);

     //设置列宽
     ui->tableWidget->setColumnWidth(0,ui->tableWidget->width()/2);

     //设置表单中字体
     font.setBold(false);
     //font.setPointSize(11);
     ui->tableWidget->setFont(font);

     //禁止编辑
     ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);


     //每隔一行换一个颜色，一恢一白 setAlternatingRowColors(true);
     ui->tableWidget->setAlternatingRowColors(true);

     //任意单击都选中一行  setSelectionBehavior(QAbstractItemView::SelectRows);
     ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

     //表头最后一行会自动拉伸，也可以实现充满窗体的效果
     ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}


void Dg_Check_yq::on_pushButton_2_clicked()
{
    hide();
}

void Dg_Check_yq::on_bt_collect_clicked()
{

}

void Dg_Check_yq::on_bt_start_clicked()
{

}
