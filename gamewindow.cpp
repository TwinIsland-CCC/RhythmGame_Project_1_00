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
    qDebug()<<"I am main Thread, my ID:"<<QThread::currentThreadId()<<"\n";

    //试行方案1：按下键时触发按钮，按钮再进行进一步判定
    //可以考虑给鼠标左右键加一下
    connect(this,&Gamewindow::Z_triggered,ui->Mainkey1,[=](){
        //qDebug()<<"Z被按下";
        emit ui->Mainkey1->clicked();
    });
    connect(this,&Gamewindow::X_triggered,ui->Mainkey2,[=](){
        //qDebug()<<"X被按下";
        emit ui->Mainkey2->clicked();
    });



    connect(ui->Mainkey1,&QPushButton::clicked,[=](){
        //qDebug()<<"key1被按下";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止


    });
    connect(ui->Mainkey2,&QPushButton::clicked,[=](){
        //qDebug()<<"key2被按下";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止


    });

    //预先为音符数组connect一下判定
    //如果计时器没关着，检测到按键按下后计时器停止

    connect(ui->PauseBtn,&QPushButton::clicked,[=](){
        bgtimer->stop();
        player->pause();
        PauseWindow* paus = new PauseWindow;
        paus->setWindowModality(Qt::ApplicationModal);
        paus->show();
        connect(paus,&PauseWindow::game_continue,[=](){
            player->play();
            bgtimer->start(1);
            paus->close();
        });
        ////restart和exit一会再写


    });

    movie.setFileName(":/test/cat2.gif");//已经在类中声明了movie
    ui->label->setMovie(&movie);
    movie.start();

    meow = new QMediaPlayer;
    QMediaPlaylist* list2 = new QMediaPlaylist;
    list2->addMedia(QUrl("qrc:/mus/sounds/sounds/meow.mp3"));
    list2->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    meow->setPlaylist(list2);
    meow->setVolume(100);
    connect(ui->label,&mylabel::clicked,[=](){
        meow->stop();
        meow->play();
    });



}

void Gamewindow::init(){
    //创建成绩窗口
    ResultWidget* res = new ResultWidget();
    res->setWindowModality(Qt::ApplicationModal);

    //主要的游戏交互窗口
    //QElapsedTimer* coun = new QElapsedTimer();

    //结束以后显示成绩
    connect(this,&Gamewindow::Game_Over,[=](){
        this->hide();
        res->show();
    });

    //监听result中的Continue按钮，用于实现场景切换
    connect(res,&ResultWidget::ContinueBtnpushed,[=](){
        res->close();
        emit Game_Over();
    });

    //创建线程
    mythread* jud = new mythread();//为判定创建线程
    jud->moveToThread(&judgethread);
    judgethread.start();



    //整体的判定
    //游戏开始

    //测试
    QVector<Note*>Notestest = {};
    //QElapsedTimer* timer = new QElapsedTimer;
    Note* dot = new Note(this,100,'Z',":/test/nku.png");
    Notestest.push_back(dot);


    //需求：写出音符下落模块
    song_length = 2000;//通过文件读取歌曲长度（待实现）
    i = 0;//第i个音符
    remaining_length = song_length;

    key_num = Notestest.length();
    miss_num = key_num;
    score_per_note = 10000000 / key_num;

    connect(ui->Mainkey1,&QPushButton::clicked,[=](){
        qDebug()<<"key1被按下2";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止
//调试用代码
//        bool flag = Notestest[i]->judge.isValid();
//        qDebug()<<flag;

        if(!(Notestest[i]->been_judged) && Notestest[i]->judge.isValid())
        {
            //qDebug()<<"timer活着的";
            if(!(Notestest[i]->type))
            {
                qDebug()<<"音符在左边";
                //按对了就启动判定
                int remain = interval - Notestest[i]->judge.elapsed();
                if(remain > 0 && remain <= 50 | remain > 150 && remain < 200)
                {
                    qDebug()<<remain<<" "<<"great";
                    Notestest[i]->been_judged = true;
                    emit Notestest[i]->great();
                    get_score += (score_per_note / 2);
                    great_num++;
                    qDebug()<<great_num;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                }
                else if(remain > 50 && remain <= 75 | remain > 125 && remain <= 150)
                {
                    qDebug()<<remain<<" "<<"perfect";
                    Notestest[i]->been_judged = true;
                    emit Notestest[i]->perfect();
                    get_score += score_per_note;
                    perfect_num++;
                    qDebug()<<perfect_num;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                }
                else if(remain > 75 && remain <= 125)
                {
                    qDebug()<<remain<<" "<<"max perfect";
                    Notestest[i]->been_judged = true;
                    emit Notestest[i]->maxperfect();
                    get_score += (score_per_note + 1);
                    maxperfect_num++;
                    qDebug()<<maxperfect_num;
                    perfect_num++;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                }
                else
                {
                    qDebug()<<remain<<" "<<"miss";
                    Notestest[i]->been_judged = true;
                    emit Notestest[i]->miss();
                    qDebug()<<miss_num;
                    ui->ScoreLabel->setText(QString::number(get_score));
                }
            }
            else
            {
                qDebug()<<"音符在右边，你按反了";
                //按反了就什么也不做
            }
        }
        else
        {
            qDebug()<<"你按的太早了，音符还没下来，或者你按的太晚了，音符都跑了";
        }
    });

    connect(ui->Mainkey2,&QPushButton::clicked,[=](){
        qDebug()<<"key2被按下2";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止
        if(!(Notestest[i]->been_judged) && Notestest[i]->judge.isValid())
        {
            //qDebug()<<"timer活着的";
            if(Notestest[i]->type)
            {
                qDebug()<<"音符在右边";
                //按对了就启动判定
                int remain = interval - Notestest[i]->judge.elapsed();
                if(remain > 0 && remain <= 50 | remain > 150 && remain < 200)
                {
                    qDebug()<<remain<<" "<<"great";
                    Notestest[i]->been_judged = true;
                    emit Notestest[i]->great();
                    get_score += (score_per_note / 2);
                    great_num++;
                    qDebug()<<great_num;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                }
                else if(remain > 50 && remain <= 75 | remain > 125 && remain <= 150)
                {
                    qDebug()<<remain<<" "<<"perfect";
                    Notestest[i]->been_judged = true;
                    emit Notestest[i]->perfect();
                    get_score += score_per_note;
                    perfect_num++;
                    qDebug()<<perfect_num;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                }
                else if(remain > 75 && remain <= 125)
                {
                    qDebug()<<remain<<" "<<"max perfect";
                    Notestest[i]->been_judged = true;
                    emit Notestest[i]->maxperfect();
                    get_score += (score_per_note + 1);
                    maxperfect_num++;
                    qDebug()<<maxperfect_num;
                    perfect_num++;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                }
                else
                {
                    qDebug()<<remain<<" "<<"miss";
                    Notestest[i]->been_judged = true;
                    emit Notestest[i]->miss();
                    qDebug()<<miss_num;
                    ui->ScoreLabel->setText(QString::number(get_score));
                }
            }
            else
            {
                qDebug()<<"音符在左边，你按反了";
                //按反了就什么也不做
            }
        }
        else
        {
            qDebug()<<"你按的太早了，音符还没下来，或者你按的太晚了，音符都跑了";
        }

    });


    connect(player,&QMediaPlayer::stateChanged,[=](){
        if(player->state() == QMediaPlayer::StoppedState)
        {
            bgtimer->stop();
            QEventLoop eventloop;
            QTimer::singleShot(1000, &eventloop, SLOT(quit()));
            //qDebug()<<"1s";
            eventloop.exec();//打完歌以后暂停1s，开启贤者模式（不是
            res->init();
            emit Game_Over();
        }
    });



    player->setMedia(QUrl("qrc:/mus/"+nameofsong+".wav"));
    player->play();
    bgtimer->start(1);

    //coun->start();

    //Notestest[i]->judge.start();

    //线程
//    while(remaining_length)
//    {
////        if(Notestest[i]->note_start_time == coun->elapsed())
////        {
////            //实现：使音符下落


////            //让音符开始判定计时，完成判定模块
////            Notestest[i]->judge->start();
////            //需求：当开始之后时间经过100ms时让这个音符的judge变为invalid


////            //下一个音符
////            i++;
////        }
////        else
////        {
////            qDebug()<<"err";
////        }

//        remaining_length = song_length - coun->elapsed();

//    }




    //qDebug()<<"emitted";
}

void Gamewindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        //qDebug()<<"press";
        switch(event->key())
        {//Z和V为一判定，X和C为一判定
        case Qt::Key_Z:
            //特效
            //qDebug()<<"press  z";
            emit Z_triggered();
            break;

        case Qt::Key_V:
            //特效
            //qDebug()<<"press  v";
            emit Z_triggered();
            break;

        case Qt::Key_X:
            //特效
            //qDebug()<<"press  x";
            emit X_triggered();
            break;

        case Qt::Key_C:
            //特效
            //qDebug()<<"press  c";
            emit X_triggered();
            break;

        }
    }
}


void Gamewindow::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        //qDebug()<<"release";
    }
}


Gamewindow::~Gamewindow()
{
    judgethread.quit();//退出线程
    judgethread.wait();
    delete ui;
}
