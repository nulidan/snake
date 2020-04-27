#include "mainwindow.h"
#include <QIcon>
#include  <QMessageBox>
#include <iostream>
using namespace std;
mainWindow::mainWindow(QWidget *parent)
{
    //this-登录窗口
    pre = parent;
    //设置窗口大小
    this->setFixedSize(600,600);
    //设置窗口标题
    this->setWindowTitle(QString::fromUtf8("登录窗口"));
    //设置窗口logo
    this->setWindowIcon(QIcon("./image/icon.jpg"));
    //设置背景
    setAutoFillBackground(true);
        QPalette pal = this->palette();
        pal.setBrush(backgroundRole(), QPixmap("./image/beij.jpg"));
        setPalette(pal);

    //开始按钮
    loginBtn = new QPushButton(QString::fromUtf8("开始游戏"),this);
    loginBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    loginBtn->setGeometry(200,100,170,60);
    //退出按钮
    exitBtn = new QPushButton(QString::fromUtf8("退出游戏"),this);
    exitBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    exitBtn->setGeometry(200,200,170,60);

    //信号与槽的连接
    connect(loginBtn,SIGNAL(clicked()),this,SLOT(loginSlot()));
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(exitSlot()));
}

void mainWindow::loginSlot()
{

    this->hide();
    //显示游戏窗口
    GameWidget = new gameWidget(this);
    GameWidget->show();




}
void mainWindow::exitSlot(){
    cout<<"end game"<<endl;

    if(QMessageBox::Yes == QMessageBox::question(this,QString::fromUtf8("退出提示"),
                                                 QString::fromUtf8("确认退出游戏？"),
                                                 QMessageBox::Yes,QMessageBox::No));
    this->close();
    pre->show();
}


