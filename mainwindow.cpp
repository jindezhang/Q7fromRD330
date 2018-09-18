#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("Q7");
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//窗体无边框，无法移动。
//    showMaximized();//最大化

    t = new QTimer();
    connect(t,SIGNAL(timeout()),this,SLOT(timer_Out()));

    //设置按钮样式
    //QString l_boder = "border-radius:9px";
    QString bt_border = "QPushButton{background-color: rgb(52, 178, 237);border-radius:15px;}";
//    ui->bt_canshu->setStyleSheet(bt_border);
//    ui->bt_help->setStyleSheet(bt_border);
//    ui->bt_saomiao->setStyleSheet(bt_border);
    ui->bt_shutup->setStyleSheet("QPushButton{background-color: rgb(242, 79, 80);border-radius:15px;} QPushButton:hover{color:#E5FEFF;background:#f46f8e;}\
                             QPushButton:pressed{\
                                 color:#A0DAFB;\
                                 background:rgb(242, 79, 80);}");
//    ui->ed_addr->setStyleSheet(l_boder);
//    ui->ed_doc->setStyleSheet(l_boder);
    ui->bt_fuhua->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->bt_liulan->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->bt_kuaisu->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui_data = nullptr;
    ui_canshu = nullptr;
    ui_kuaisu = nullptr;

    fuhua_show(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_shutup_clicked()
{
    exit(0);
}

void MainWindow::fuhua_show(bool b)
{
    ui->bt_kuaisu->setEnabled(!b);
    t_value = 100;
    if(b)
    {
        ui->label_3->show();
        ui->wg_progress->show();
        ui->l_time->show();
        ui->bt_quxiao->show();
        t->start(1000);
        ui->bt_kuaisu->setStyleSheet("QToolButton{\
                                     background-color: rgb(167,167,167);\
                                     color: rgb(255, 255, 255);\
                             }QToolButton:hover{\
                                     color:#E5FEFF;\
                                background:#5DACE4;}\
                            QToolButton:pressed{\
                                color:#A0DAFB;\
                                background:#2483C7;}");

    }else{
        ui->label_3->hide();
        ui->wg_progress->hide();
        ui->l_time->hide();
        ui->bt_quxiao->hide();
        t->stop();
        ui->bt_kuaisu->setStyleSheet("QToolButton{\
                                     background-color: rgb(30, 141, 217);\
                                     color: rgb(255, 255, 255);}\
                                     QToolButton:hover{\
                                     color:#E5FEFF;\
                                background:#5DACE4;}\
                            QToolButton:pressed{\
                                color:#A0DAFB;\
                                background:#2483C7;}");
    }

}

void MainWindow::on_bt_fuhua_clicked()
{
    fuhua_show(true);
}

void MainWindow::on_bt_quxiao_clicked()
{
    fuhua_show(false);
}

void MainWindow::timer_Out()
{
    t_value--;
    if(0 == t_value){
        t->stop();
        return;
    }
    QString h = toStr(t_value%60);
    QString m = toStr(t_value/60);

    QString tmp = QString("%1:%2").arg(m).arg(h);

    ui->l_time->setText(tmp);
    ui->wg_progress->set_level(100 - t_value);
}

//十进制数格式化
QString MainWindow::toStr(int i)
{
    QString ii = QString("%1").arg(i);
    if(i <= 9)
        return "0"+ii;
    else
        return ii;
}

void MainWindow::on_bt_liulan_clicked()
{
    if(ui_data == nullptr)
        ui_data = new Data(this);
    ui_data->show();
    this->hide();
}

void MainWindow::on_bt_help_clicked()
{
    Dg_Input dialog ;
    dialog.exec();
}

void MainWindow::on_bt_canshu_clicked()
{
    if(nullptr == ui_canshu)
        ui_canshu = new Win_Canshu(this);
    ui_canshu->show();
    this->hide();
}

void MainWindow::on_bt_saomiao_clicked()
{

    dg_login.show();
}

void MainWindow::on_bt_kuaisu_clicked()
{
    if(nullptr == ui_kuaisu)
        ui_kuaisu = new Win_Kuaisu(this);
    ui_kuaisu->show();
    this->hide();
}
