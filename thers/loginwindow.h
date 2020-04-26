#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H


#include <QtGui/QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPalette>
#include <QPixmap>
#include <QMessageBox>

#include "mainwindow.h"
class loginWindow : public QWidget
{
    Q_OBJECT
public slots:
    void loginSlot();


public:
    loginWindow(QWidget *parent = 0);
    ~loginWindow();
private:
    //定义用户名密码提示语
    QLabel *userLabel,*passLabel;
    //用户名密码输入框
    QLineEdit *userEdit,*passEdit;
    //登录按钮
    QPushButton *loginBtn,*exitBtn;
    //主窗口-指针
    mainWindow *mainWin;
};

#endif // LOGINWINDOW_H
