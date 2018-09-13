#ifndef WIN_KUAISU_H
#define WIN_KUAISU_H

#include <QMainWindow>
#include <QSize>
#include "wg_pic.h"

namespace Ui {
class Win_Kuaisu;
}

class Win_Kuaisu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win_Kuaisu(QWidget *parent = 0);
    ~Win_Kuaisu();

private:
    Ui::Win_Kuaisu *ui;
};

#endif // WIN_KUAISU_H
