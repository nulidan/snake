#include "gamewidget.h"
#include <QIcon>
#include <QTime>
//地图行
#define ROW 17
//地图列
#define COL 17
#include <iostream>
#include <QMessageBox>
using namespace std;

gameWidget::gameWidget(QWidget *parent)
{
    pre = parent;
    //设置窗口大小
    this->setFixedSize(800,600);
    //设置窗口标题
    this->setWindowTitle(QString::fromUtf8("游戏窗口"));
    //设置窗口logo
    this->setWindowIcon(QIcon("./image/tig.jpg"));
    //设置背景
    setAutoFillBackground(true);
    QPalette pal = this->palette();
    pal.setBrush(backgroundRole(), QPixmap("./image/beij.jpg"));
    setPalette(pal);

    //上下左右按钮
    upBtn = new QPushButton(QString::fromUtf8("上"),this);
    upBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    upBtn->setGeometry(630,140,80,50);

    downBtn = new QPushButton(QString::fromUtf8("下"),this);
    downBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    downBtn->setGeometry(630,260,80,50);

    leftBtn = new QPushButton(QString::fromUtf8("左"),this);
    leftBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    leftBtn->setGeometry(550,200,80,50);

    rightBtn = new QPushButton(QString::fromUtf8("右"),this);
    rightBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    rightBtn->setGeometry(710,200,80,50);
    //开始结束按钮
    startBtn = new QPushButton(QString::fromUtf8("开始"),this);
    startBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    startBtn->setGeometry(550,335,100,55);

    endBtn = new QPushButton(QString::fromUtf8("结束"),this);
    endBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    endBtn->setGeometry(690,335,100,55);

    //初始化蛇头位置
    //x与COL相关
    snake[0][0]=qrand()%COL;
    //y与ROW相关
    snake[0][1]=qrand()%ROW;
    cout<<"snake x"<<snake[0][0]<<endl;
    cout<<"snake y"<<snake[0][1]<<endl;

    qsrand(QTime::currentTime().msec());
    //初始化食物位置
    //x与COL相关
    foodx=qrand()%COL;
    //y与ROW相关
    foody=qrand()%ROW;
    cout<<"food x"<<foodx<<endl;
    cout<<"food y"<<foody<<endl;

}

void gameWidget::paintEvent(QPaintEvent *)
{
    //画网格
    QPainter paint(this);
    int i,j;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)

            {
            //xy
            paint.drawRect(j*28,i*28,28,28);
            }
    }
   //绘制蛇头
    paint.drawImage(QRectF(snake[0][0]*28,snake[0][1]*28,28,28),
                    QImage("./image/sna.jpg"));

   //绘制食物
    paint.drawImage(QRectF(foodx*28,foody*28,28,28),
                    QImage("./image/icon.png"));

}
