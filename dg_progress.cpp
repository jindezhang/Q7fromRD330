#include "dg_progress.h"
#include "ui_dg_progress.h"

Dg_Progress::Dg_Progress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dg_Progress)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

}

Dg_Progress::~Dg_Progress()
{
    delete ui;
}

void Dg_Progress::set_Progress(int pa_value)
{
   ui->l_num->setText(QString("%1").arg(pa_value));

   ui->widget_2->set_level(pa_value);
}
