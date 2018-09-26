#include "wg_pic.h"
#include "ui_wg_pic.h"

Wg_Pic::Wg_Pic(bool picType,QWidget *parent) :
    QWidget(parent),pic_Type(picType),
    ui(new Ui::Wg_Pic)
{
    ui->setupUi(this);


    //pic_height = 174;
    //pic_width = 0;
    m_total_widht = 0;
//    m_backcolor = "";
    m_index = -1;
    m_size = size();
    ui->l_pic->setScaledContents(true);
    ui->l_pic->installEventFilter(this);
    setMaximumHeight(174);
//    setMinimumHeight(70);
}



Wg_Pic::~Wg_Pic()
{
    delete ui;
}

void Wg_Pic::setTotalwidht(int pa_widtht)
{
    m_total_widht = pa_widtht;
}

void Wg_Pic::set_BackgrandColor(QString pa_color)
{
    //    m_backcolor = QString("background-color: rgb(%1);").arg(pa_color);
}

void Wg_Pic::set_Pixmap(const QString &pa_path)
{
    m_pix = new QPixmap(pa_path);
}

void Wg_Pic::show_Pixmap()
{
    //用label来装作图

    //显示算法: y不变，x = x * w
    //real:2480*1748
    //美图：open 1423*1003--->缩放因子：1.7428
    //first 166*353
    //pic 139*617---> w=139
    //定位需要有个浮动值，因为卡与卡之间有间隙。所以copy() x = 139 --> 142

    if(!pic_Type){
       long double common = 1.7428;
       //m_index = 2;
       QPixmap pix =  m_pix->copy((166 + m_index * 142) * common, 353*common, 139*common, 617*common);
       qDebug()<<"index"<<m_index;
       QMatrix trans;
       trans.rotate(270);
       pix = pix.transformed(trans);//旋转270度

       ui->l_pic->setPixmap(pix);
       m_pic.set_pic(pic_Type, pix);
    }else{
         ui->l_pic->setPixmap(*m_pix);//QPixmap(":/new/home/home/q7.bmp"));
         m_pic.set_pic(pic_Type, *m_pix);
         //画框
         ui->l_pic->set_Index(m_index);
         ui->l_pic->label_Update();
       }
    ui->l_pic->move(0,0);
}

void Wg_Pic::set_Index(int index)
{
    m_index = index;

}

int Wg_Pic::get_Index()
{
    return m_index;
}

void Wg_Pic::index_get(int index)
{
    //如果没有点击测试卡，那么丢弃信号。
    if(-1 == index)
        return;
    m_index = index;
    show_Pixmap();
}

void Wg_Pic::resizeEvent(QResizeEvent *event)
{
    QSize size = event->size();
    m_size = size;
    int tmp_h = 0;//设置大小
    //位置
    int tmp_x = 0;
    int tmp_y = 0;

    //如果高度大于图片高度，那么现实图片高度即可。长度也是一样
//    if(size.height() > pic_height){

//        tmp_h = size.height() - pic_height;
//        tmp_y = tmp_h;
//    }else
    {
        tmp_h = size.height();
    }
//    if(size.width() > pic_width){
//        tmp_y = size.width() - pic_width;
//    }

    //左右图的变化
    if(!pic_Type){


        //左图；x=0;y=height-pic.height; w:h = 25:6
        this->setGeometry(QRect(tmp_x,tmp_y,(tmp_h*25/6), tmp_h));
    }
    else{
        //绘图
        this->repaint();
        int width = (7*tmp_h/5);
        //右边图片的变化 y=0;x=740-width; h:w = 5:7
        this->setGeometry(QRect(m_total_widht-width,tmp_y,(7*tmp_h/5), tmp_h));
    }
}

void Wg_Pic::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

//    //限制窗体大小。拉伸的限制
//    QSize wg_size = size();
//    if(wg_size.height() > 170)
//        wg_size.rheight() = 170;

//    resize(wg_size);

    ui->l_pic->resize(size());
    qDebug() << "wg_pic size()"<<size();


//    static QPixmap pix (":/new/home/home/q7.bmp");
//    QPainter painter(this);

//    QTransform transform;
//    //transform可以代替p的translate，因为他会进行一系列复杂的运算，平移、旋转、缩放等等
//    //虽然p也有scale，rotate，translate等函数
//    //transform.rotate(10);
//    //transform.scale(0.8, 0.8);  //缩放功能
//    //将以下所有的图像旋转10度,改语句后面的所画的图像都要旋转
//   // painter.setTransform(transform);
//    //将下方画的所有图形移动相对应的位置,整体图像平移，只影响这句话之后的语句，知道遇到下一个translate语句
//   // painter.translate(100, 100);
//    //消锯齿，让画出的图形更加美观
//    painter.setRenderHint(QPainter::SmoothPixmapTransform);

//    pix.scaled(QSize(this->width(),this->height()));
    //    painter.drawPixmap(QPoint(0, 0),pix);
}

void Wg_Pic::mousePressEvent(QMouseEvent *event)
{

    //只有右图才可以
    if(pic_Type){
        m_index = select_Pic(event->x(), event->y());
        ui->l_pic->set_Index(m_index);
        if(-1 != m_index)
            emit pic_index(m_index);
//        this->repaint();
//        qDebug() << event->x();
//        qDebug() << event->y();

    }

}

void Wg_Pic::mouseDoubleClickEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    m_pic.show();
}

int Wg_Pic::select_Pic(int x, int y)
{
    //real:2480*1748
    //美图：open 1423*1003--->缩放因子：1.7428
    //first 166*353
    //pic 139*617---> w=139
//    图片区域：以open 的来计算。
//            四个点(上下左）:(x1, y1)/(x1, y2)/(x2, y1)/(x2, y2)
//            x1 = 166 （浮动）
//            y1 = 353
//            x2 = index * 139 + 166   index:卡槽测试卡总数
//            y2 = 353 + 617

//    缩放因子：long double --> m_size.height() / 1003
//    第几张试剂卡：(x - 166) / 139

    long double common;//缩放因子
    common = (long double)m_size.height() / 1003;
    //不在图片区域，不要。
    x /= common;
    y /= common;
    if(x < 166 || x > (8 * 139 + 166) || y < 353 || y > (353+617) )
        return -1;

    int tmp_index = ((x-166) / 139);

    return tmp_index;
}


