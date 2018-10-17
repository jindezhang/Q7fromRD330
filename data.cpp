#include "data.h"
#include "ui_data.h"
#include "wg_shade.h"
Data::Data(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Data)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//窗体无边框，无法移动。
    SetTableView();

    mpShade = init_Shade(this);
}

Data::~Data()
{
    delete mpShade;
    delete ui;
}

void Data::OnPrevButtonClick()
{
    int limitIndex = (currentPage - 2) * PageRecordCount;
    RecordQuery(limitIndex);
    currentPage -= 1;
    UpdateStatus();
}

void Data::OnNextButtonClick()
{
    int limitIndex = currentPage * PageRecordCount;
    RecordQuery(limitIndex);
    currentPage += 1;
    UpdateStatus();
}

void Data::OnSwitchPageButtonClick()
{
    //得到输入的字符
    QString szText = "";
    //is Empty?
    if("" == szText)
        return;
    QRegExp regExp("^[0-9]*$");
    //is number?
    if(regExp.exactMatch(szText)){
        QMessageBox::warning(this,tr("inform"),tr("please input number"));
        return;
    }
    //得到页数
    int pageIndex = szText.toInt();
    //判断是否有指定页或者是否当前页
    if( pageIndex > totalPage || pageIndex < 1){
        QMessageBox::information(this, tr("inform"), tr("no this page"));
        return;
    }
    if(pageIndex == currentPage)
        return;
    //合法，跳转。
    //得到起始行号
    int limitIndex = (pageIndex -1) * PageRecordCount;
    //记录查询
    RecordQuery(limitIndex);
    //设置当前页
    currentPage = pageIndex;
    UpdateStatus();
}

void Data::SetTableView()
{
    //添加数据
  QSqlDatabase database = QSqlDatabase::addDatabase("QSQLITE");
  //设置数据库名称
  database.setDatabaseName("Q7.db");
  //判断是否打开
  if(!database.open()){
      qDebug()<<"database open failed!";
      exit(1);
  }

    queryModel = new QSqlQueryModel();
    currentPage = 1;
    totalRecrodCount = GetTotalRecordCount();
    totalPage = GetPageCount();
    UpdateStatus();
    SetTotalPageLabel();
    RecordQuery(0);
    ui->tableView_data->setModel(queryModel);

    //设置表头
    setTableHeader();
}

void Data::setTableHeader()
{
    int i = 0;

    QSqlQueryModel *queryModel_t = queryModel;
    queryModel_t->setHeaderData(i,Qt::Horizontal,"value");

    auto setHeader = [&i,queryModel_t](QString value){
        queryModel_t->setHeaderData(i,Qt::Horizontal,value);
                                        i++;};
    setHeader("序号"    );
    setHeader("日期"    );
    setHeader("报表"    );
    setHeader("检验医师"  );
    setHeader("检验地址"  );
    setHeader("测试卡"   );
    setHeader("样品编号"  );
    setHeader("项目编号"  );
    setHeader("结果"    );
    setHeader("参考区间"  );
    setHeader("批次"    );
    setHeader("姓名"    );
    setHeader("性别"    );
    setHeader("年龄"    );
    setHeader("住院号"   );
    setHeader("样本类型"  );
    setHeader("患者类型"  );
    setHeader("科室"    );
    setHeader("床号"    );
    setHeader("送检医师"  );
    setHeader("审核者"   );
    setHeader("警示"    );
    setHeader("备注"    );

}

int Data::GetTotalRecordCount()
{
    queryModel->setQuery("select * from xxx");
    return queryModel->rowCount();
}

int Data::GetPageCount()
{
    return (totalRecrodCount % PageRecordCount == 0) ?(totalRecrodCount / PageRecordCount) : (totalRecrodCount / PageRecordCount + 1);
}

void Data::RecordQuery(int limitIndex)
{
    //limit x,y : 提取x开始的y条记录数
    QString szQuery = QString("select * from xxx limit %1,%2").arg(limitIndex).arg(PageRecordCount);
    queryModel->setQuery(szQuery);
}

void Data::UpdateStatus()
{
    //设置当前页文本
    QString szCurrentText = QString("当前第%1页").arg(toStr(currentPage));

    //判断上一页下一页按钮是否可用
    if(1 == totalPage)//只有一页
    {

    }else if(1 == currentPage){//首页

    }else if(currentPage == totalPage)//末页
    {

    }else{

    }
}

void Data::SetTotalPageLabel()
{
    QString szPageCountText = QString("总共%1页").arg(totalPage);

}

QString Data::toStr(int i)
{
    QString ii = QString("%1").arg(i);
    if(i <= 9)
        return "0"+ii;
    else
        return ii;
}

void Data::on_pushButton_15_clicked()
{
    this->parentWidget()->show();
    this->close();
}

void Data::on_bt_del_clicked()
{
    mpShade->show();
    Dg_SelTime dialog;
    dialog.exec();
    mpShade->hide();
}
