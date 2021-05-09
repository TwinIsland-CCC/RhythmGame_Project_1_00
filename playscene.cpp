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

    statuslabel = new QLabel(this);
    ui->statusBar->addPermanentWidget(statuslabel);
    statusbartext = "欢迎，";
    statusbartext+=user_name;
    statusbartext+="！您的potential是：";
    statusbartext+=QString::number(your_potential);
    statuslabel->setText(statusbartext);


    ui->NameLabel->setText(user_name);
    ui->PttLabel->setText(QString::number(your_potential));
    ui->IconLabel->setPixmap(QPixmap(user_icon));

    preview = new QMediaPlayer(this);
    preview->setMedia(QUrl("qrc:/mus/music.wav"));
    preview->setVolume(50);
    //preview->play();

    //创建选择难度、速度窗体
    DifficultyAndSpeedSelectWindow* sele = new DifficultyAndSpeedSelectWindow;

    //为SchrollArea设置透明度
    //0为完全透明，1为完全不透明，但不知道我的为啥是一块黑的
//    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
//    effect->setOpacity(1);
//    ui->scrollArea->setGraphicsEffect(effect);

    //点击back按钮回到mainwindow
    connect(ui->Backbtn,&QPushButton::clicked,this,[=](){
        preview->pause();
        emit this->backbtnpushed();
    });

    //默认选中paradise
    QPixmap* pix = new QPixmap(":/test/faradise.jpg");
    ui->label->setPixmap(*pix);
    preview->setMedia(QUrl("qrc:/mus/preview/preview/paradise_preview_BPM126.mp3"));
    nameofsong = "paradise";
    current_song = 0;
    delete pix;

    //点击选歌栏中每一首歌，在背景里显示相应封面
    //需求：切换特效
    connect(ui->toolButton,&QToolButton::clicked,this,[=](){
       preview->stop();
       QPixmap* pix = new QPixmap(":/test/faradise.jpg");
       ui->label->setPixmap(*pix);
       preview->setMedia(QUrl("qrc:/mus/preview/preview/paradise_preview_BPM126.mp3"));
       preview->play();
       nameofsong = ui->toolButton->text();
       current_song = 0;
       delete pix;


    });
    connect(ui->toolButton_2,&QToolButton::clicked,this,[=](){
       preview->stop();
       QPixmap* pix = new QPixmap(":/test/sdorica.jpg");
       ui->label->setPixmap(*pix);
       preview->setMedia(QUrl("qrc:/mus/preview/preview/the story unfolds_preview_120.124BPM.mp3"));
       preview->play();
       nameofsong = ui->toolButton_2->text();
       //qDebug()<<nameofsong;

       current_song = 1;
       delete pix;
    });
    connect(ui->toolButton_3,&QToolButton::clicked,this,[=](){
       preview->stop();
       QPixmap* pix = new QPixmap(":/test/ANIMA.jpg");
       ui->label->setPixmap(*pix);
       preview->setMedia(QUrl("qrc:/mus/preview/preview/test_preview_BPM130.wav"));
       preview->play();
       nameofsong = ui->toolButton_3->text();
       //qDebug()<<nameofsong;

       current_song = 2;
       delete pix;
    });

    //点击选中那首歌以后，点击play进入难度选择、调速页面，播放BGMpreview
    connect(ui->Playbtn,&QPushButton::clicked,this,[=](){
        //preview->stop();
        this->hide();
        sele->init();
        sele->show();
        sele->myload->load_song();
    });

    connect(sele,&DifficultyAndSpeedSelectWindow::Music_Stop,this,[=](){
        preview->stop();
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

void PlayScene::Re_init()
{
    statusbartext = "欢迎，";
    statusbartext+=user_name;
    statusbartext+="！您的potential是：";
    statusbartext+=QString::number(your_potential);
    statuslabel->setText(statusbartext);

    ui->NameLabel->setText(user_name);
    ui->PttLabel->setText(QString::number(your_potential));

}

void PlayScene::Re_init_icon()
{
    ui->IconLabel->setPixmap(user_icon);
}

void PlayScene::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Return)
        {
            emit ui->Playbtn->clicked();
        }
        else if(event->key() == Qt::Key_Escape)
        {
            emit ui->Backbtn->clicked();
        }
    }
}
