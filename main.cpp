#include "mainwindow.h"
#include <QApplication>
#include "data.h"
#include <test_data.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Data w;
//    Data w;
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
