#ifndef LB_CHECK_H
#define LB_CHECK_H

#include <QObject>
#include <QLabel>
#include <QPixmap>

class Lb_Check : public QLabel
{
    Q_OBJECT
public:
    explicit Lb_Check(QObject *parent = nullptr);

signals:

protected:
    void mousePressEvent(QMouseEvent *ev);
public slots:
};

#endif // LB_CHECK_H
