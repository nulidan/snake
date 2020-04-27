#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPushButton>


class gameWidget : public QWidget
{
    Q_OBJECT
public:
    explicit gameWidget(QWidget *parent = 0);
    //绘画事件重写
    void paintEvent(QPaintEvent *);

signals:

public slots:

private:
    //父窗体 主菜单页面
    QWidget *pre;
    //按钮
    QPushButton *upBtn,*downBtn,*rightBtn,*leftBtn,*startBtn,*endBtn;
    //记录蛇的每个下标
    int snake[100][2];

    //蛇头的走向
    int direction;
    //食物的走向
    int foodx,foody;
};

#endif // GAMEWIDGET_H
