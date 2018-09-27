#include "dg_setting_long.h"
#include "ui_dg_setting_long.h"

Dg_Setting_Long::Dg_Setting_Long(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Setting_Long)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    init_Table();
    cmenu = nullptr;
}

Dg_Setting_Long::~Dg_Setting_Long()
{
    delete ui;
}

void Dg_Setting_Long::on_pushButton_2_clicked()
{
    hide();
}

void Dg_Setting_Long::init_Table()
{
    ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableWidget, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(show_contextMenu(QPoint)));

    QStringList head_list;
    head_list<<"卡号(名称)";
    head_list<<"批次号(可为空)";
    head_list<<"项目1";
    head_list<<"项目2";
    head_list<<"项目3";

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
     for(int i = 0; i<head_list.count(); i++)
        ui->tableWidget->setColumnWidth(i,ui->tableWidget->width()/head_list.count());

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

void Dg_Setting_Long::show_contextMenu(QPoint pos)
{
    Q_UNUSED(pos);
    if(cmenu)//保证同时只存在一个menu，及时释放内存
    {
        delete cmenu;
        cmenu = nullptr;
    }
    cmenu = new QMenu(ui->tableWidget);

    QAction* modColAction = cmenu->addAction("修改该行");
    QAction *delColAction = cmenu->addAction("删除该行");
    QAction* addColAction = cmenu->addAction("增加一行");

    connect(modColAction, SIGNAL(triggered(bool)), this, SLOT(action_mod()));
    connect(delColAction, SIGNAL(triggered(bool)), this, SLOT(action_del()));
    connect(addColAction, SIGNAL(triggered(bool)), this, SLOT(action_add()));

    cmenu->exec(QCursor::pos());//在当前鼠标位置显示
    //cmenu->exec(pos)是在viewport显示
}

void Dg_Setting_Long::action_mod()
{

}

void Dg_Setting_Long::action_add()
{
    Dg_Setting_add dialog;
    dialog.exec();

    QList<QString> value = dialog.get_Value();
    int row_count = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(row_count);


    QTableWidgetItem* item = add_row(QString("*"));
    ui->tableWidget->setItem(row_count, 0, item);

    int i = 0;
    for(auto tmp: value){
        i++;
        QTableWidgetItem* item = add_row(tmp);
        ui->tableWidget->setItem(row_count, i, item);
    }


}

QTableWidgetItem *Dg_Setting_Long::add_row(QString &info)
{
    QTableWidgetItem* item = new QTableWidgetItem();
    item->setText(info);
    return item;
}

void Dg_Setting_Long::action_del()
{
    int rowIndex = ui->tableWidget->currentRow();
    if (rowIndex != -1)
        ui->tableWidget->removeRow(rowIndex);
}

void Dg_Setting_Long::on_bt_canal_setting_clicked()
{
    hide();
}
