#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gamewidget.h"
#include <QPushButton>
#include <QWidget>

class mainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit mainWindow(QWidget *parent = 0);

signals:

public slots:
    //定义登录槽函数
    void loginSlot();
    void exitSlot();

private:
    //父窗口
    QWidget *pre;
    //按钮
    QPushButton *loginBtn,*exitBtn;
    //游戏窗口
    gameWidget *GameWidget;

};

#endif // MAINWINDOW_H
