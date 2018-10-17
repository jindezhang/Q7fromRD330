#include "dg_addproject.h"
#include "ui_dg_addproject.h"

Dg_AddProject::Dg_AddProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_AddProject)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());


    init_ListView();
    m_select.clear();
    ui->edp_pro->setReadOnly(true);//设置为只读
    connect(ui->ed_id, SIGNAL(editingFinished()), this, SLOT(check_CardID()));
    ui->ed_t->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));//+ 匹配前一个表达式出现一次或者多次；$ 字符结束的位置

    mpshade = init_Shade(this);
}

Dg_AddProject::~Dg_AddProject()
{
    delete mpshade;
    delete ui;
}

void Dg_AddProject::on_pushButton_2_clicked()
{
    ui->ed_id->setText(QString("6701"));//便于关闭；
    hide();
}

void Dg_AddProject::on_bt_ok_clicked()
{
    if(!check_CardID()){
        return;

    }
    qDebug()<<"on_bt_ok_clicked";
    hide();
}

void Dg_AddProject::init_ListView()
{
    connect(ui->lv_card_addpro, SIGNAL(clicked(QModelIndex)), this, SLOT(click_list(QModelIndex)));
    //ui->lv_card_addpro->setFont(QFont("楷体", 11, 50));//不能设置单元格内字体
    ui->lv_card_addpro->setSelectionMode(QAbstractItemView::SingleSelection);
//    ui->lv_card_addpro->;
    //1、将表格设置为禁止编辑
    ui->lv_card_addpro->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //设置交替行颜色
    ui->lv_card_addpro->setAlternatingRowColors(true);
    //设置可以多选
    ui->lv_card_addpro->setSelectionMode(QAbstractItemView::MultiSelection);

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
   // model->appendRow(new QStandardItem("hello"));
    ui->lv_card_addpro->setModel(model);

}

void Dg_AddProject::click_list(QModelIndex model)
{

    qDebug()<<"click"<<model.row();
}

void Dg_AddProject::on_bt_move_clicked()
{
    //qDebug()<<"m_select.count()"<<m_select.count();
    //选择选中的对象
    QItemSelectionModel *selmodel = ui->lv_card_addpro->selectionModel();
    if (selmodel)
    {
        QModelIndexList indexlist = selmodel->selectedIndexes();
        int count1 = indexlist.size();
        if(0  == count1)
            return;
        if(m_select.count() == 3 || count1 > 3){
            WG_Shade shade(mpshade);
            myDialog dialog;
            dialog.set_icon(0);
            dialog.set_info(QString("最多支持三个项目"));
            dialog.exec();
            ui->lv_card_addpro->clearSelection();//清空选中项
            return;
        }
        QStringList tmp;
        for(auto item:indexlist){
            //qDebug()<<item.data().toString();
            tmp.push_back(item.data().toString());
        }
        add_Text(tmp);
    }
    ui->lv_card_addpro->clearSelection();//清空选中项
    //ui->lv_card_addpro->setSelectionMode(QAbstractItemView::NoSelection);
//    QString info = QString("%1").arg(ui->lv_card_addpro->currentIndex().data().toString());
//    ui->edp_pro->appendPlainText(info);

}

void Dg_AddProject::add_Text(QStringList &info)
{
    if(info.count() == 0)
        return;
    if(m_select.count() == 0){
        m_select = info;
        for(auto item:m_select)
            ui->edp_pro->appendPlainText(item);
        return;
    }
    int i = 0;//用于标识是否存在相同；
    for(auto item:info){
        i = 0;
        for(auto temp:m_select){
            if(temp == item){
                i = 1;
                break;
            }
        }
        if(1 != i && m_select.count() < 3){
            m_select.push_back(item);
            ui->edp_pro->appendPlainText(item);
        }
    }
    qDebug()<<m_select;

}

bool Dg_AddProject::check_CardID()
{
    QString info = "卡号必须是6700~6799，67100~67255";
    WG_Shade shade(mpshade);
    myDialog dialog;
    dialog.set_icon(0);
    dialog.set_info(info);
    int text = ui->ed_id->text().toInt();
    if(text < 6700 || text > 67255){
        dialog.exec();
        //ui->ed_id->setFocus();
        return false;
    }
    if(text < 67100 && text >6799){
        dialog.exec();
        //ui->ed_id->setFocus();
        return false;
    }
    return true;
}

void Dg_AddProject::on_bt_clear_clicked()
{
    ui->edp_pro->clear();
    m_select.clear();

}

void Dg_AddProject::on_bt_add_clicked()
{
    WG_Shade shade(mpshade);
    Dg_AddPro dialog;
    dialog.exec();
}
