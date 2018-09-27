#include "dg_check_td.h"
#include "ui_dg_check_td.h"

Dg_Check_td::Dg_Check_td(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Check_td)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    init_Table();
    connect(ui->bt_1, SIGNAL(clicked(bool)), this, SLOT(bt_Click()));
    connect(ui->bt_2, SIGNAL(clicked(bool)), this, SLOT(bt_Click()));
    connect(ui->bt_3, SIGNAL(clicked(bool)), this, SLOT(bt_Click()));
    connect(ui->bt_4, SIGNAL(clicked(bool)), this, SLOT(bt_Click()));
    connect(ui->bt_5, SIGNAL(clicked(bool)), this, SLOT(bt_Click()));
    connect(ui->bt_6, SIGNAL(clicked(bool)), this, SLOT(bt_Click()));
    connect(ui->bt_7, SIGNAL(clicked(bool)), this, SLOT(bt_Click()));
    connect(ui->bt_8, SIGNAL(clicked(bool)), this, SLOT(bt_Click()));
}

Dg_Check_td::~Dg_Check_td()
{
    delete ui;
}

void Dg_Check_td::on_pushButton_2_clicked()
{
    hide();
}

void Dg_Check_td::init_Table()
{
    QStringList head_list;
    QString name;
    for(int i = 1; i<9; i++){
        name = QString("通道%1").arg(i);
        head_list<<name;
    }
     ui->tableWidget->setRowCount(8);
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
     for(int i = 0; i<8; i++)
        ui->tableWidget->setColumnWidth(i,ui->tableWidget->width()/8);

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

void Dg_Check_td::bt_Click()
{
    ViceButton * button = qobject_cast<ViceButton *>(sender());
    QString bt_Value = button->text();
    //switch 语句里面执行成功，则return；
    switch (bt_Value[2].toLatin1()) {
    case '1':

        qDebug()<<"bt_click"<<bt_Value;
        return;
        break;
    case '2':

        break;
    case '3':

        break;
    case '4':

        break;
    case '5':

        break;
    case '6':

        break;
    case '7':

        break;
    case '8':
        qDebug()<<"bt_click"<<bt_Value;
        break;

    default:
        break;
    }
    dialog_Show(bt_Value);
}

void Dg_Check_td::dialog_Show(QString &info)
{
    myDialog dialog;
    dialog.set_icon(0);
    QString str = QString("获取%1数据失败").arg(info);
    dialog.set_info(str);
    dialog.exec();

}
