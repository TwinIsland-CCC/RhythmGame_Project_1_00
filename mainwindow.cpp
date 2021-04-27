#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QPushButton>
#include "tutorialwindow.h"
#include "playscene.h"
#include <QDebug>
#include <QMessageBox>
#include "difficultyandspeedselectwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建选择谱面窗体
    PlayScene* play = new PlayScene;

    //监听play中的back按钮，用于实现场景切换
    connect(play,&PlayScene::backbtnpushed,this,[=](){
        play->hide();
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




}

MainWindow::~MainWindow()
{
    delete ui;
}

