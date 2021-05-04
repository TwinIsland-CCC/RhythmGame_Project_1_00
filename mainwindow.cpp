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

    //为ui添加背景音乐(一会再写)
    QMediaPlayer *player = new QMediaPlayer(this);//设置背景音乐
    //player->setMedia(QUrl::fromLocalFile(":/mus/music.mp3"));
    player->setVolume(50);//音量
    player->play();//开始播放，也可以用按钮的方式，这里用的是菜单栏中的action


    //监听各种back按钮，用于实现场景切换
    connect(play,&PlayScene::backbtnpushed,this,[=](){
        play->hide();
        this->show();
    });

    connect(option,&OptionWindow::FinishBtnpushed,this,[=](){
        option->hide();
        this->show();
    });

    connect(option,&OptionWindow::CancelBtnpushed,this,[=](){
        option->hide();
        this->show();
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
        player->stop();
        this->hide();
        play->show();
    });

    //设置一张gif
    movie.setFileName(":/test/eveonecat1.gif");//已经在类中声明了movie
    ui->label->setMovie(&movie);
    movie.start();

    //点击edit按钮显示对话框：此功能暂未开放！
    connect(ui->EditBtn,&QPushButton::clicked,this,[=](){
        QMessageBox::information(this,"哦...","此功能暂未开放！","好吧");
    });


    //新需求：左上角和状态栏都显示用户名和ptt，并且在左上角显示头像

    QLabel* statuslabel = new QLabel;
    ui->statusBar->addPermanentWidget(statuslabel);
    QString statusbartext = "欢迎，";
    statusbartext+=user_name;
    statusbartext+="！您的potential是：";
    statusbartext+=QString::number(your_potential);
    statuslabel->setText(statusbartext);

    ui->NameLabel->setText(user_name);
    ui->PttLabel->setText(QString::number(your_potential));
    //新需求：为第一次进入游戏的玩家弹出设置用户名窗口


    //新需求：在option中提供更改用户名界面，提供名片界面（选）
    connect(ui->OptionBtn,&QPushButton::clicked,[=](){
        option->show();
        this->hide();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

