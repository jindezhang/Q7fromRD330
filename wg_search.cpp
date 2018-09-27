#include "wg_search.h"
#include "ui_wg_search.h"

Wg_Search::Wg_Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wg_Search)
{
    ui->setupUi(this);

    m_pSearchLineEdit = new QLineEdit();
    QPushButton *pSearchButton = new QPushButton(this);

    pSearchButton->setCursor(Qt::PointingHandCursor);
    pSearchButton->setFixedSize(28, 28);
    pSearchButton->setToolTip(QStringLiteral("搜索"));
    pSearchButton->setStyleSheet("QPushButton{border-image:url(:/new/home/home/date.png); background:transparent;} \
                                         QPushButton:hover{border:2px solid  rgb(52, 178, 237);} \
                                         ");

    //防止文本框输入内容位于按钮之下
    QMargins margins = m_pSearchLineEdit->textMargins();
    m_pSearchLineEdit->setTextMargins(margins.left(), margins.top(), pSearchButton->width(), margins.bottom());
    m_pSearchLineEdit->setPlaceholderText(QStringLiteral("请输入搜索内容"));

    QHBoxLayout *pSearchLayout = new QHBoxLayout();
    pSearchLayout->addStretch();
    pSearchLayout->addWidget(pSearchButton);
    pSearchLayout->setSpacing(0);
    pSearchLayout->setContentsMargins(0, 0, 0, 0);
    m_pSearchLineEdit->setLayout(pSearchLayout);

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(m_pSearchLineEdit);
    setLayout(layout);

    setMinimumSize(150,22);
    connect(pSearchButton, SIGNAL(clicked(bool)), this, SLOT(search()));

}

Wg_Search::~Wg_Search()
{
    delete ui;
}

#include<QMessageBox>
void Wg_Search::search()
{
    QString strText = m_pSearchLineEdit->text();
    if (!strText.isEmpty())
    {
        QMessageBox::information(this, QStringLiteral("搜索"), QStringLiteral("搜索内容为%1").arg(strText));
    }
}
