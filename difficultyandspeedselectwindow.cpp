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

    //创建主要游戏窗体
    Gamewindow* game = new Gamewindow;

    //设置back按钮，以返回上一个页面
    connect(ui->Backbtn,&QPushButton::clicked,this,[=](){
        emit this->backbtnpushed();
    });

    connect(ui->Playbtn,&QToolButton::clicked,this,[=](){
        game->show();
        this->hide();
    });


    //新需求：显示历史最高成绩以及评价


}

DifficultyAndSpeedSelectWindow::~DifficultyAndSpeedSelectWindow()
{
    delete ui;
}
