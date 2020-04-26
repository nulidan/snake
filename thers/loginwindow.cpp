#include "loginwindow.h"
#include <iostream>
#include <QMessageBox>

using namespace std;
loginWindow::loginWindow(QWidget *parent)
    : QWidget(parent)
{
    //设置窗口大小
    this->setFixedSize(600,600);
    //设置窗口标题
    this->setWindowTitle(QString::fromUtf8("贪吃蛇登录窗口"));
    //设置窗口logo
    this->setWindowIcon(QIcon("./image/tig.jpg"));
    //设置背景
    setAutoFillBackground(true);
        QPalette pal = this->palette();
        pal.setBrush(backgroundRole(), QPixmap("./image/beij.jpg"));
        setPalette(pal);


    //设置用户名label+样式+位置+与登录关联
    userLabel = new QLabel(QString::fromUtf8("用户名："),this);
    userLabel->setStyleSheet("font-size:14px;color:#000");
    userLabel->setGeometry(95,100,60,30);
    //设置用户名输入框
    userEdit = new QLineEdit(this);
    userEdit->setStyleSheet("font-size:14px;color:#1ba784;border-radius:10px");
    userEdit->setGeometry(165,100,120,30);
    userEdit->setMaxLength(10);


    //设置密码label
    passLabel = new QLabel(QString::fromUtf8("密码："),this);
    passLabel->setStyleSheet("font-size:14px;color:#000");
    passLabel->setGeometry(95,160,60,30);
    //设置密码输入框
    passEdit = new QLineEdit(this);
    passEdit->setEchoMode(QLineEdit::Password);
    passEdit->setStyleSheet("font-size:14px;color:#1ba784;border-radius:10px");
    passEdit->setGeometry(165,160,120,30);
    passEdit->setMaxLength(12);
    //登录按钮
    loginBtn = new QPushButton(QString::fromUtf8("登录"),this);
    loginBtn->setStyleSheet("color:#63bbd0;background-color:#c6e6e8;border-radius:10px");
    loginBtn->setGeometry(125,250,150,35);
    loginBtn->setIcon(QIcon("./image/icon.png"));
    //退出按钮
    exitBtn = new QPushButton(QString::fromUtf8("退出"),this);
    exitBtn->setStyleSheet("color:#63bbd0;background-color:#c6e6e8;border-radius:10px");
    exitBtn->setGeometry(125,300,150,35);
    exitBtn->setIcon(QIcon("./image/icon.png"));

    //信号与槽连接 按钮，点击信号，this，登录退出槽函数
    connect(loginBtn,SIGNAL(clicked()),this,SLOT(loginSlot()));

}
void loginWindow::loginSlot()
{
    QString user = userEdit->text();
    QString pass = passEdit->text();
    //打印出来
    cout<<"user:"<<user.toStdString()<<endl;
    cout<<"pass:"<<pass.toStdString()<<endl;
    if(strcmp(user.toStdString().c_str(),"")==0 ||
            strcmp(pass.toStdString().c_str(),"")==0)
    {
        QMessageBox::information(this,
                                 QString::fromUtf8("登录"),
                                 QString::fromUtf8("登录失败"),
                                 QMessageBox::Ok);
    }
    else if(strcmp(user.toStdString().c_str(),"147")==1 ||
                strcmp(user.toStdString().c_str(),"147")==-1)
     {
            //提示
            QMessageBox::information(this,QString::fromUtf8("信息提示"),
                                          QString::fromUtf8("用户名不存在！"),
                                          QMessageBox::Ok);
            userEdit->clear();
            passEdit->clear();
     }
        //密码不是123456
    else if(strcmp(user.toStdString().c_str(),"18156")==0 &&
            strcmp(pass.toStdString().c_str(),"18157")==1 &&
            strcmp(pass.toStdString().c_str(),"18157")==-1)
 {
            //提示
            QMessageBox::information(this,QString::fromUtf8("信息提示"),
                                          QString::fromUtf8("密码错误！"),
                                          QMessageBox::Ok);
            passEdit->clear();
     }


        else if(strcmp(user.toStdString().c_str(),"147")==0 &&
                strcmp(pass.toStdString().c_str(),"123456")==0)
     {
             //提示
             QMessageBox::information(this,QString::fromUtf8("登录提示"),
                                           QString::fromUtf8("登录成功！"),
                                           QMessageBox::Ok);

         //跳转后show()显示，hide()隐藏登陆框
         this->hide();
         //显示主界面,this：登录窗口-父窗口
         mainWin = new mainWindow(this);
         mainWin->show();

     }
 }



loginWindow::~loginWindow()
{

}
