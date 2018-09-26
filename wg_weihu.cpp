#include "wg_weihu.h"
#include "ui_wg_weihu.h"

Wg_WeiHu::Wg_WeiHu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wg_WeiHu)
{
    ui->setupUi(this);

    //
    init_ListView();

}

Wg_WeiHu::~Wg_WeiHu()
{
    delete ui;
}

void Wg_WeiHu::on_click_List()
{
    myDialog dialog(this);
    QString tmp_str = ui->lv_card_weihu->currentIndex().data().toString();
    tmp_str = QString("%1\n%2\n%3\n%4\n%5").arg(tmp_str).arg(tmp_str).arg(tmp_str).arg(tmp_str).arg(tmp_str);
    dialog.set_value(tmp_str);
    dialog.exec();
}

void Wg_WeiHu::init_ListView()
{
    connect(ui->lv_card_weihu, SIGNAL(clicked(QModelIndex)), this, SLOT(on_click_List()));
    //ui->lv_card_weihu->setFont(QFont("楷体", 11, 50));//不能设置单元格内字体
    ui->lv_card_weihu->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->lv_card_weihu->;
    //1、将表格设置为禁止编辑
    ui->lv_card_weihu->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置交替行颜色
    ui->lv_card_weihu->setAlternatingRowColors(true);
    QSqlDatabase database;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("Q7.db");

    }

    QSqlQuery query;
    query.prepare("select name from t_card_supported");
    query.exec();
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item;
    //添加数据
    while (query.next()) {
        item = new QStandardItem(query.value(0).toString());
        item->setFont(QFont("楷体", 11, 50));
        model->appendRow(item);
        //qDebug()<<query.value(0).toString();
    }
    qDebug()<<"init_listview";
   // model->appendRow(new QStandardItem("hello"));
    ui->lv_card_weihu->setModel(model);

}

void Wg_WeiHu::on_bt_pic_weihu_clicked()
{
    Dg_PicLocation dialog(this);
    dialog.exec();

}

void Wg_WeiHu::on_bt_yiqi_weihu_clicked()
{
    Dg_Check_yq dialog;
    dialog.exec();
}

void Wg_WeiHu::on_bt_tongdao_weihu_clicked()
{
    Dg_Check_td dialog;
    dialog.exec();
}

void Wg_WeiHu::on_bt_shezhi_weihu_clicked()
{
    Dg_Setting_Long dialog;
    dialog.exec();
}

void Wg_WeiHu::on_bt_add_weihu_clicked()
{

    Dg_AddProject dialog;
    dialog.exec();
}
