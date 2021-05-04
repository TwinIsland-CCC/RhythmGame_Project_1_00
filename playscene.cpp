#include "playscene.h"
#include "ui_playscene.h"
#include <QPushButton>
#include "mainwindow.h"
#include "source.h"
#include <QPixmap>
#include <QLabel>
#include <QPicture>
#include "difficultyandspeedselectwindow.h"

PlayScene::PlayScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayScene)
{
    ui->setupUi(this);

    QLabel* statuslabel = new QLabel;
    ui->statusBar->addPermanentWidget(statuslabel);
    QString statusbartext = "欢迎，";
    statusbartext+=user_name;
    statusbartext+="！您的potential是：";
    statusbartext+=QString::number(your_potential);
    statuslabel->setText(statusbartext);

    //创建选择难度、速度窗体
    DifficultyAndSpeedSelectWindow* sele = new DifficultyAndSpeedSelectWindow;

    //为SchrollArea设置透明度
    //0为完全透明，1为完全不透明，但不知道我的为啥是一块黑的
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    effect->setOpacity(1);
    ui->scrollArea->setGraphicsEffect(effect);

    //点击back按钮回到mainwindow
    connect(ui->Backbtn,&QPushButton::clicked,this,[=](){
        emit this->backbtnpushed();
    });

    //点击选歌栏中每一首歌，在背景里显示相应封面
    //需求：切换特效
    connect(ui->toolButton,&QToolButton::clicked,this,[=](){
       QPixmap* pix = new QPixmap(":/test/faradise.jpg");
       ui->label->setPixmap(*pix);
       nameofsong = ui->toolButton->text();
       qDebug()<<nameofsong;
    });
    connect(ui->toolButton_2,&QToolButton::clicked,this,[=](){
       QPixmap* pix = new QPixmap(":/test/sdorica.jpg");
       ui->label->setPixmap(*pix);
       nameofsong = ui->toolButton_2->text();
       //qDebug()<<nameofsong;
    });
    connect(ui->toolButton_3,&QToolButton::clicked,this,[=](){
       QPixmap* pix = new QPixmap(":/test/ANIMA.jpg");
       ui->label->setPixmap(*pix);
       nameofsong = ui->toolButton_3->text();
       //qDebug()<<nameofsong;

    });

    //点击选中那首歌以后，点击play进入难度选择、调速页面
    connect(ui->Playbtn,&QPushButton::clicked,this,[=](){
        this->hide();
        sele->init();
        sele->show();
    });

    //监听dassw中的back按钮，用于实现场景切换
    connect(sele,&DifficultyAndSpeedSelectWindow::backbtnpushed,this,[=](){
        sele->hide();
        this->show();
    });

    connect(sele,&DifficultyAndSpeedSelectWindow::Re_Select,[=](){
        this->show();
    });

}

PlayScene::~PlayScene()
{
    delete ui;
}
