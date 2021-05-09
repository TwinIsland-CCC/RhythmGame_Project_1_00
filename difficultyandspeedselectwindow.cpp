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
//    connect(ui->Backbtn,&QPushButton::clicked,this,[=](){
//        emit this->backbtnpushed();
//    });


    connect(ui->Playbtn,&QToolButton::clicked,this,[=](){
        //创建主要游戏窗体
        emit Music_Stop();//让preview停止
        this->hide();
        Gamewindow* game = new Gamewindow(this);
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





}

void DifficultyAndSpeedSelectWindow::init()
{
    //显示历史最高成绩以及评价
    ui->bestLabel->setText(QString::number(save_data[current_song].score));
    ui->gradelabel->setText(save_data[current_song].grade);
    ui->NameOfSong->setText(nameofsong);
}

DifficultyAndSpeedSelectWindow::~DifficultyAndSpeedSelectWindow()
{
    delete ui;
}

void DifficultyAndSpeedSelectWindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Return)
        {
            emit ui->Playbtn->clicked();
        }
        else if(event->key() == Qt::Key_Escape)
        {
            //emit ui->Backbtn->clicked();
        }
    }
}
