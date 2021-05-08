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

    //bgtimer->setTimerType(Qt::PreciseTimer);


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
        //restart和exit
        connect(paus,&PauseWindow::game_restart,[=](){
            player->play();
            bgtimer->start(1);
            paus->close();
        });
        connect(paus,&PauseWindow::game_exit,[=](){
            paus->close();
            emit Game_Over();
        });

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

    //创建线程
    mythread* jud = new mythread();//为判定创建线程
    jud->moveToThread(&judgethread);
    judgethread.start();

    connect(ui->Mainkey1,&QPushButton::clicked,[=]()
    {
        qDebug()<<"key1被按下2";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止
//调试用代码
//        bool flag = [i]->judge.isValid();
//        qDebug()<<flag;
        if(!(Notes[i]->been_judged) && Notes[i]->judge->isValid())
        {
            //qDebug()<<"timer活着的";
            if(!(Notes[i]->type))
            {
                qDebug()<<"音符在左边";
                //按对了就启动判定
                int remain = interval - Notes[i]->judge->elapsed();
                if(remain > 0 && remain <= 50 | remain > 150 && remain < 200)
                {
                    qDebug()<<remain<<" "<<"great";
                    Notes[i]->been_judged = true;
                    emit Notes[i]->great();
                    get_score += (score_per_note / 2);
                    great_num++;
                    qDebug()<<great_num;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                    if(i<key_num - 1)i++;
                    combo++;
                    if(combo >= highest_combo)highest_combo = combo;
                    ui->ComboLabel->setText(QString::number(combo));
                }
                else if(remain > 50 && remain <= 75 | remain > 125 && remain <= 150)
                {
                    qDebug()<<remain<<" "<<"perfect";
                    Notes[i]->been_judged = true;
                    emit Notes[i]->perfect();
                    get_score += score_per_note;
                    perfect_num++;
                    qDebug()<<perfect_num;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                    if(i<key_num - 1)i++;
                    combo++;
                    if(combo >= highest_combo)highest_combo = combo;
                    ui->ComboLabel->setText(QString::number(combo));
                }
                else if(remain > 75 && remain <= 125)
                {
                    qDebug()<<remain<<" "<<"max perfect";
                    Notes[i]->been_judged = true;
                    emit Notes[i]->maxperfect();
                    get_score += (score_per_note + 1);
                    maxperfect_num++;
                    qDebug()<<maxperfect_num;
                    perfect_num++;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                    if(i<key_num - 1)i++;
                    combo++;
                    if(combo >= highest_combo)highest_combo = combo;
                    ui->ComboLabel->setText(QString::number(combo));
                }
                else
                {
                    qDebug()<<remain<<" "<<"miss";
                    Notes[i]->been_judged = true;
                    emit Notes[i]->miss();
                    qDebug()<<miss_num;
                    ui->ScoreLabel->setText(QString::number(get_score));
                    if(i<key_num - 1)i++;
                    if(combo >= highest_combo)highest_combo = combo;
                    combo = 0;
                    ui->ComboLabel->setText(QString::number(combo));
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

    //qDebug()<<key_num;

    connect(ui->Mainkey2,&QPushButton::clicked,[=](){
        qDebug()<<"key2被按下2";
        //实现判定模块
        //如果计时器没关着，检测到按键按下后计时器停止
        if(!(Notes[i]->been_judged) && Notes[i]->judge->isValid())
        {
            //qDebug()<<"timer活着的";
            if(Notes[i]->type)
            {
                qDebug()<<"音符在右边";
                //按对了就启动判定
                int remain = interval - Notes[i]->judge->elapsed();
                if(remain > 0 && remain <= 50 | remain > 150 && remain < 200)
                {
                    qDebug()<<remain<<" "<<"great";
                    Notes[i]->been_judged = true;
                    emit Notes[i]->great();
                    get_score += (score_per_note / 2);
                    great_num++;
                    qDebug()<<great_num;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                    if(i<key_num - 1)i++;
                    combo++;
                    ui->ComboLabel->setText(QString::number(combo));
                    if(combo >= highest_combo)highest_combo = combo;
                }
                else if(remain > 50 && remain <= 75 | remain > 125 && remain <= 150)
                {
                    qDebug()<<remain<<" "<<"perfect";
                    Notes[i]->been_judged = true;
                    emit Notes[i]->perfect();
                    get_score += score_per_note;
                    perfect_num++;
                    qDebug()<<perfect_num;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                    if(i<key_num - 1)i++;
                    combo++;
                    ui->ComboLabel->setText(QString::number(combo));
                    if(combo >= highest_combo)highest_combo = combo;
                }
                else if(remain > 75 && remain <= 125)
                {
                    qDebug()<<remain<<" "<<"max perfect";
                    Notes[i]->been_judged = true;
                    emit Notes[i]->maxperfect();
                    get_score += (score_per_note + 1);
                    maxperfect_num++;
                    qDebug()<<maxperfect_num;
                    perfect_num++;
                    miss_num--;
                    ui->ScoreLabel->setText(QString::number(get_score));
                    if(i<key_num - 1)i++;
                    combo++;
                    ui->ComboLabel->setText(QString::number(combo));
                    if(combo >= highest_combo)highest_combo = combo;
                }
                else
                {
                    qDebug()<<remain<<" "<<"miss";
                    Notes[i]->been_judged = true;
                    emit Notes[i]->miss();
                    qDebug()<<miss_num;
                    ui->ScoreLabel->setText(QString::number(get_score));
                    if(i<key_num - 1)i++;
                    if(combo >= highest_combo)highest_combo = combo;
                    combo = 0;
                    ui->ComboLabel->setText(QString::number(combo));
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

    //qDebug()<<key_num;



    //待优化
    connect(bgtimer,&QTimer::timeout,[=](){
        current++;
        //qDebug()<<"进入判定了！";
        //qDebug()<<current<<" "<<current_i<<" "<<Notes[current_i]->note_start_time;
        if(current == Notes[current_i]->note_start_time)
        {
            qDebug()<<"应在"<<Notes[current_i]->note_start_time<<"处出现";
            //Notes[current_i]->show();

            float_key[i]->show();
            qDebug()<<"实在"<<current2<<"处出现";
            Notes[current_i++]->judge->start();
            qDebug()<<"第"<<current_i<<"个音符开始判定了！";
        }
        if(current - Notes[i]->note_start_time >= 200)
        {
            qDebug()<<"第"<<i<<"个音符miss了！";
            Notes[i]->been_judged = true;
            emit Notes[i]->miss();
            qDebug()<<miss_num;
            ui->ScoreLabel->setText(QString::number(get_score));
            if(i<key_num - 1)i++;
            ui->ComboLabel->setText(QString::number(combo));
            if(combo >= highest_combo)highest_combo = combo;
            combo = 0;
        }
    });

//    connect(bgtimer2,&QTimer::timeout,[=](){
//        current2++;
//    });


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


    //需求：写出音符下落模块
    song_length = 2000;//通过文件读取歌曲长度（待实现）
    i = 0;//第i个音符
    remaining_length = song_length;
    key_num = Notes.length();
    qDebug()<<key_num;
    miss_num = key_num;
    //if(key_num == 0)key_num++;
    qDebug()<<"timer活着的";

    //qDebug()<<key_num;

    player->setMedia(QUrl("qrc:/mus/"+nameofsong+".wav"));

    bgtimer->start(1);
    bgtimer2->start(1);

    player->play();
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
        case Qt::Key_Escape:
            emit ui->PauseBtn->clicked();
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

