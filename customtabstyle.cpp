﻿#include "customtabstyle.h"

QSize CustomTabStyle::sizeFromContents(QStyle::ContentsType type, const QStyleOption *option, const QSize &size, const QWidget *widget) const
{
    QSize s = QProxyStyle::sizeFromContents(type, option, size, widget);
    if (type == QStyle::CT_TabBarTab) {
        s.transpose();
        s.rwidth() = 55; // 设置每个tabBar中item的大小
        s.rheight() = 146;
    }
    return s;
}

//void CustomTabStyle::drawControl(QStyle::ControlElement element, const QStyleOption *option, QPainter *painter, const QWidget *widget) const
//{
//    if (element == CE_TabBarTabLabel) {
//        if (const QStyleOptionTab *tab = qstyleoption_cast<const QStyleOptionTab *>(option)) {
//            QRect allRect = tab->rect;

//            if (tab->state & QStyle::State_Selected) {
//                painter->save();
//                painter->setPen(0x89cfff);
//                painter->setBrush(QBrush(0x89cfff));
//                //painter->drawRect(allRect.adjusted(6, 6, -6, -6));
//                painter->drawPixmap(allRect,QPixmap(":/new/home/home/params.png"));
//                painter->restore();
//            }
//            QTextOption option;
//            option.setAlignment(Qt::AlignCenter);
//            if ((tab->state & QStyle::State_Selected) && (tab->row == 1)) {
//                painter->setPen(0xf8fcff);
//                painter->drawPixmap(allRect,QPixmap(":/new/home/home/params.png"));
//            }
//            else {
//                painter->setPen(0x5d5d5d);
//            }

//            painter->drawText(allRect, tab->text, option);
//            return;
//        }
//    }

//    if (element == CE_TabBarTab) {
//        QProxyStyle::drawControl(element, option, painter, widget);
//    }
//}
