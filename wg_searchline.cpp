#include "wg_searchline.h"

Wg_SearchLine::Wg_SearchLine(QWidget *parent) : QLineEdit(parent)
{
    QPushButton *pSearchButton = new QPushButton(this);

    pSearchButton->setCursor(Qt::PointingHandCursor);
    pSearchButton->setFixedSize(22, 22);
    pSearchButton->setToolTip(QStringLiteral("打开"));
    pSearchButton->setStyleSheet("QPushButton{border-image:url(:/new/home/home/date.png); background:transparent;} \
                                         QPushButton:hover{border:2px solid  rgb(52, 178, 237);} \
                                         ");

    //防止文本框输入内容位于按钮之下
    QMargins margins = this->textMargins();
    this->setTextMargins(margins.left(), margins.top(), pSearchButton->width(), margins.bottom());
//    this->setPlaceholderText(QStringLiteral("请输入搜索内容"));

    QHBoxLayout *pSearchLayout = new QHBoxLayout();
    pSearchLayout->addStretch();
    pSearchLayout->addWidget(pSearchButton);
    pSearchLayout->setSpacing(0);
    pSearchLayout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(pSearchLayout);

    setStyleSheet("QLineEdit#Wg_SearchLine{background-color: rgb(214, 214, 214);}");
    //setEnabled(false);//不可编辑
    setFocusPolicy(Qt::NoFocus);//不可获取焦点

    connect(pSearchButton, SIGNAL(clicked(bool)), this, SLOT(search()));

}

void Wg_SearchLine::search()
{
    qDebug()<<"search";
    emit bt_click(this->text());
}
