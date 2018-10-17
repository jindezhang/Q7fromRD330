#ifndef WG_SHADE_H
#define WG_SHADE_H

/**
* @projectName   Q7from330
* @describe      描述：
* @author        RD330
* @date          2018-10-17
*/
/*
 * 遮罩窗体是一个QWidget，用于突显弹窗。
 * init_Shade() 获取一个遮罩窗体。
 * WG_Shade 传入一个遮罩窗体的指针。该类构造时，会显示遮罩窗体。析构时，会隐藏遮罩窗体。
 */

//初始化遮罩窗体。
//@param parent： 遮罩窗体所依赖的窗体，被遮罩的窗体
//return： 返回遮罩窗体的指针；
#include <QWidget>
inline QWidget* init_Shade( QWidget *parent)
{
    QWidget * mpShadeWindow = new QWidget(parent);
    QString str("QWidget{background-color:rgba(0,0,0,0.6);}");
    mpShadeWindow->setStyleSheet(str);
    mpShadeWindow->setGeometry(0, 0, parent->width(), parent->height());
    mpShadeWindow->hide();
    return mpShadeWindow;
}

//便于遮罩窗体的操作。
class WG_Shade
{
public:
    explicit WG_Shade(QWidget* shade):mpShade(shade){
        shade->show();
    }
    ~WG_Shade(){
        mpShade->hide();
    }
private:
    QWidget *mpShade;
};

#endif // WG_SHADE_H
