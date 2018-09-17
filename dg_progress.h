#ifndef DG_PROGRESS_H
#define DG_PROGRESS_H

#include <QDialog>

namespace Ui {
class Dg_Progress;
}

class Dg_Progress : public QDialog
{
    Q_OBJECT

public:
    explicit Dg_Progress(QWidget *parent = 0);
    ~Dg_Progress();
    void set_Progress(int pa_value);
private:
    Ui::Dg_Progress *ui;
};

#endif // DG_PROGRESS_H
