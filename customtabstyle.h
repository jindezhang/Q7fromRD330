#ifndef CUSTOMTABSTYLE_H
#define CUSTOMTABSTYLE_H


#include <QPainter>
#include <QProxyStyle>
#include<QStyleOptionTab>
#include<QRect>
#include<QTextOption>
#include <QSize>

class CustomTabStyle : public QProxyStyle
{
public:
    QSize sizeFromContents(ContentsType type, const QStyleOption *option,
        const QSize &size, const QWidget *widget) const;

    //void drawControl(ControlElement element, const QStyleOption *option,
                     //QPainter *painter, const QWidget *widget) const;
   // void drawItemPixmap(QPainter *painter, const QRect &rect, int alignment, const QPixmap &pixmap) const;

};

#endif // CUSTOMTABSTYLE_H
