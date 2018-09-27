#ifndef WG_SEARCH_H
#define WG_SEARCH_H

#include <QWidget>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QPushButton>
//★★★★弃用，转wg_searchLine

namespace Ui {
class Wg_Search;
}

class Wg_Search : public QWidget
{
    Q_OBJECT

public:
    explicit Wg_Search(QWidget *parent = 0);
    ~Wg_Search();

private slots:
    void search();//点击按钮
private:
    Ui::Wg_Search *ui;
    QLineEdit* m_pSearchLineEdit;
};

#endif // WG_SEARCH_H
