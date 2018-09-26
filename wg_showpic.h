#ifndef WG_SHOWPIC_H
#define WG_SHOWPIC_H

#include <QWidget>

namespace Ui {
class Wg_ShowPic;
}

class Wg_ShowPic : public QWidget
{
    Q_OBJECT

public:
    explicit Wg_ShowPic(QWidget *parent = 0);
    ~Wg_ShowPic();
    void set_pic(bool pa_type, QPixmap &pa_pix);
private:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Wg_ShowPic *ui;
};

#endif // WG_SHOWPIC_H
