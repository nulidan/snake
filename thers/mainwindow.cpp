#include "mainwindow.h"
#include <QIcon>
#include  <QMessageBox>
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

    //关卡按钮
    loginBtn = new QPushButton(QString::fromUtf8("关卡模式"),this);
    loginBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    loginBtn->setGeometry(200,100,170,60);
    //限时按钮
    loginBtn = new QPushButton(QString::fromUtf8("限时模式"),this);
    loginBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    loginBtn->setGeometry(200,200,170,60);
    //设置按钮
    loginBtn = new QPushButton(QString::fromUtf8("游戏设置"),this);
    loginBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    loginBtn->setGeometry(200,300,170,60);
    //退出按钮
    loginBtn = new QPushButton(QString::fromUtf8("退出游戏"),this);
    loginBtn->setStyleSheet("color:olivedrab;background-color:white;font-weight:bolder;border-radius:10px");
    loginBtn->setGeometry(200,400,170,60);
    //信号与槽的连接
    connect(loginBtn,SIGNAL(clicked()),this,SLOT(loginSlot()));
}

void mainWindow::loginSlot()
{
    //退出提示
    QMessageBox::question(this,QString::fromUtf8("提示"),
                               QString::fromUtf8("确认退出游戏？"),
                               QMessageBox::Yes);

    this->close();

}


