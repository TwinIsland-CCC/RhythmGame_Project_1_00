#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QPushButton>
#include "tutorialwindow.h"
#include "playscene.h"
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include "source.h"
#include "optionwindow.h"
#include "difficultyandspeedselectwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建选择谱面窗体
    PlayScene* play = new PlayScene;
    OptionWindow* option = new OptionWindow;

    init = new mythread;
    initthread = new QThread(this);
    init->moveToThread(initthread);
    initthread->start();

    //connect(this,&QWidget::,init,&mythread::load_save);
    //connect(init,&mythread::load_widget_signal,this,&Widget::DealLoadWidget);
    connect(ui->ExitBtn,&QPushButton::clicked,init,&mythread::keep_save);

//    if(new_or_old)
//    {
//        NewRoom* ro = new NewRoom;
//        ro->show();
//    }

    //为ui添加背景音乐(一会再写)
    player = new QMediaPlayer;//设置背景音乐
    QMediaPlaylist* list = new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/mus/music.wav"));
    list->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(list);
    player->setVolume(50);//音量
    player->play();//开始播放，也可以用按钮的方式，这里用的是菜单栏中的action

    //小彩蛋
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

    ui->IconLabel->setPixmap(user_icon);

    //监听各种back按钮，用于实现场景切换
    connect(play,&PlayScene::backbtnpushed,this,[=](){
        player->play();
        play->hide();
        this->show();
    });

    //对option窗口的设置
    connect(option,&OptionWindow::FinishBtnpushed,this,[=](){
        Re_init();
        play->Re_init();
        option->hide();
        this->show();
    });

    connect(option,&OptionWindow::CancelBtnpushed,this,[=](){
        option->hide();
        this->show();
    });

    connect(option,&OptionWindow::OpenBtnpushed,this,[=](){
        Re_init_icon();
        play->Re_init_icon();
    });


    //点击工具栏帮助中新手教程，弹出一个窗口，里面显示一张图片（新手教程）
    connect(ui->tutorial,&QAction::triggered,this,[=](){
        tutorial1.show();
    });

    //点击工具栏帮助中进阶教程，弹出一个窗口，里面显示另一张图片（进阶教程）
    connect(ui->protutorial,&QAction::triggered,this,[=](){
        tutorial2.show();
    });

    //点击play按钮进入选取谱面界面
    connect(ui->PlayBtn,&QPushButton::clicked,this,[=](){
        player->pause();
        this->hide();
        play->preview->play();
        play->show();
    });

    //设置一张gif
    movie.setFileName(":/test/eveonecat1.gif");//已经在类中声明了movie
    ui->label->setMovie(&movie);
    movie.start();

    //点击edit按钮显示对话框：此功能暂未开放！
    connect(ui->EditBtn,&QPushButton::clicked,this,[=](){
        QMessageBox::information(this,"哦...","如果你想编辑你自己的谱面，请去qmk的github下下载谱面编辑器，里面有配套的教程哟~","好吧");
    });




    //新需求：左上角和状态栏都显示用户名和ptt，并且在左上角显示头像
    //已完成
    statuslabel = new QLabel;
    ui->statusBar->addPermanentWidget(statuslabel);
    statusbartext = "欢迎，";
    statusbartext+=user_name;
    statusbartext+="！您的potential是：";
    statusbartext+=QString::number(your_potential);
    statuslabel->setText(statusbartext);

    ui->NameLabel->setText(user_name);
    ui->PttLabel->setText(QString::number(your_potential));
    //新需求：为第一次进入游戏的玩家弹出设置用户名对话框


    //新需求：在option中提供更改用户名界面，提供名片界面（选）
    connect(ui->OptionBtn,&QPushButton::clicked,[=](){
        option->show();
        this->hide();
    });

}

MainWindow::~MainWindow()
{
    initthread->quit();
    initthread->wait();
    delete ui;
}

void MainWindow::Re_init()
{
    statusbartext = "欢迎，";
    statusbartext+=user_name;
    statusbartext+="！您的potential是：";
    statusbartext+=QString::number(your_potential);
    statuslabel->setText(statusbartext);

    ui->NameLabel->setText(user_name);
    ui->PttLabel->setText(QString::number(your_potential));

}


void MainWindow::Re_init_icon()
{
    ui->IconLabel->setPixmap(user_icon);
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Return)
        {
            qDebug()<<"push";
            emit ui->PlayBtn->clicked();
        }
        else if(event->key() == Qt::Key_Escape)
        {
            qDebug()<<"push";
            emit ui->ExitBtn->clicked();
        }
    }
}
