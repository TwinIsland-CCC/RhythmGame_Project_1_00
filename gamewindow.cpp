#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "mythread.h"
#include "source.h"
#include "resultwidget.h"

Gamewindow::Gamewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gamewindow)
{
    ui->setupUi(this);


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

void Gamewindow::init(){
    //创建成绩窗口
    ResultWidget* res = new ResultWidget();

    //主要的游戏交互窗口
    QElapsedTimer* coun = new QElapsedTimer();

    //结束以后显示成绩
    connect(this,&Gamewindow::Game_Over,[=](){
        this->hide();
        res->show();
    });


    //创建线程
    mythread* jud = new mythread();//为判定创建线程
    jud->moveToThread(&judgethread);




    //整体的判定
    //游戏开始


    //需求：写出音符下落模块
    int song_length = 0;//通过文件读取歌曲长度（待实现）
    int i = 0;//第i个音符
    int remaining_length = song_length;
    connect(ui->Mainkey1,&QPushButton::clicked,[=](){
        qDebug()<<"key1被按下";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止
        if(Notes[i]->judge->isValid())
        {
            if(!(Notes[i]->type))
            {

            }
        }
        else
        {
            qDebug()<<"你按的太早了，音符还没下来，或者你按的太晚了，音符都跑了";
        }
    });
    connect(ui->Mainkey2,&QPushButton::clicked,[=](){
        qDebug()<<"key2被按下";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止


    });
    coun->start();
    while(remaining_length)
    {
        if(Notes[i]->note_start_time == coun->elapsed())
        {
            //实现：使音符下落


            //让音符开始判定计时，完成判定模块
            Notes[i]->judge->start();
            //需求：当开始之后时间经过100ms时让这个音符的judge变为invalid


            //下一个音符
            i++;
        }
        else
        {
            qDebug()<<"err";
        }

        remaining_length = song_length - coun->elapsed();

    }


    QEventLoop eventloop;
    QTimer::singleShot(1000, &eventloop, SLOT(quit()));
    //qDebug()<<"1s";
    eventloop.exec();//打完歌以后暂停1s，开启贤者模式（不是
    emit Game_Over();
    //qDebug()<<"emitted";
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
    judgethread.quit();//退出线程
    judgethread.wait();
    delete ui;
}
