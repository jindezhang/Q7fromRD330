#include "mainwindow.h"
#include <QApplication>
#include "data.h"
#include <win_canshu.h>
#include "win_kuaisu.h"
#include"wg_weihu.h"

#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    Wg_WeiHu w;
    //Data w;
//    Win_Canshu w;
    w.show();

    QFile styleSheet(":/new/Qss.qss");
    if (!styleSheet.open(QIODevice::ReadOnly))
        {
            qWarning("Can't open the style sheet file.");
            exit(1);
        }
    a.setStyleSheet(styleSheet.readAll());
    return a.exec();
}
