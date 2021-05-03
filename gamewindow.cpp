#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "source.h"

Gamewindow::Gamewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gamewindow)
{
    ui->setupUi(this);

    //主要的游戏交互窗口

    //游戏开始
    //需求：写出音符下落模块


    //试行方案1：按下键时触发按钮，按钮再进行进一步判定
    //可以考虑给鼠标左右键加一下
    connect(this,&Gamewindow::Z_triggered,ui->Mainkey1,[=](){
        qDebug()<<"Z被按下";
        emit ui->Mainkey1->clicked();
    });
    connect(this,&Gamewindow::X_triggered,ui->Mainkey2,[=](){
        qDebug()<<"X被按下";
        emit ui->Mainkey2->clicked();
    });



    connect(ui->Mainkey1,&QPushButton::clicked,[=](){
        qDebug()<<"key1被按下";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止



    });
    connect(ui->Mainkey2,&QPushButton::clicked,[=](){
        qDebug()<<"key2被按下";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止


    });

    //预先为音符数组connect一下判定
    //如果计时器没关着，检测到按键按下后计时器停止


}
void Gamewindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        qDebug()<<"press";
        switch(event->key())
        {//Z和V为一判定，X和C为一判定
        case Qt::Key_Z:
            //特效
            qDebug()<<"press  z";
            emit Z_triggered();
            break;

        case Qt::Key_V:
            //特效
            qDebug()<<"press  v";
            emit Z_triggered();
            break;

        case Qt::Key_X:
            //特效
            qDebug()<<"press  x";
            emit X_triggered();
            break;

        case Qt::Key_C:
            //特效
            qDebug()<<"press  c";
            emit X_triggered();
            break;

        }
    }
}


void Gamewindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        qDebug()<<"release";
    }
}


Gamewindow::~Gamewindow()
{
    delete ui;
}
