#include "difficultyandspeedselectwindow.h"
#include "ui_difficultyandspeedselectwindow.h"
#include "playscene.h"
#include "gamewindow.h"
#include "source.h"

DifficultyAndSpeedSelectWindow::DifficultyAndSpeedSelectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DifficultyAndSpeedSelectWindow)
{
    ui->setupUi(this);




    //设置back按钮，以返回上一个页面
    connect(ui->Backbtn,&QPushButton::clicked,this,[=](){
        emit this->backbtnpushed();
    });

    connect(ui->Playbtn,&QToolButton::clicked,this,[=](){
        //创建主要游戏窗体
        emit Music_Stop();//让preview停止
        this->hide();
        Gamewindow* game = new Gamewindow;
        game->show();
        game->init();
        connect(game,&Gamewindow::Game_Over,[=](){
            emit Re_Select();
        });
    });


    connect(ui->EasyRadiobtn,&QRadioButton::clicked,[=](){
        level = 0;
        qDebug()<<level;
    });
    connect(ui->HardRadiobtn,&QRadioButton::clicked,[=](){
        level = 1;
        qDebug()<<level;
    });

    //新需求：显示历史最高成绩以及评价
    ui->bestLabel->setText("0");


}

void DifficultyAndSpeedSelectWindow::init()
{
    ui->NameOfSong->setText(nameofsong);
}

DifficultyAndSpeedSelectWindow::~DifficultyAndSpeedSelectWindow()
{
    delete ui;
}
