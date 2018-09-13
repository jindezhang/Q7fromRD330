#ifndef WG_PIC_H
#define WG_PIC_H

#include <QWidget>
#include<QResizeEvent>
#include<QSize>
#include<qDebug>

//ENbj 420 * 60
namespace Ui {
class Wg_Pic;
}

class Wg_Pic : public QWidget
{
    Q_OBJECT

public:
    explicit Wg_Pic(QWidget *parent = 0);
    ~Wg_Pic();

private:
    void resizeEvent(QResizeEvent *event);
private:

    Ui::Wg_Pic *ui;
};

#endif // WG_PIC_H
