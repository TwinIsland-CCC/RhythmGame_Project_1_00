#include "resultwidget.h"
#include "ui_resultwidget.h"

ResultWidget::ResultWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWidget)
{
    ui->setupUi(this);



    connect(ui->ContinueBtn,&QPushButton::clicked,this,[=](){
        emit this->ContinueBtnpushed();
        get_score = 0;
        nameofsong = "";
        maxperfect_num = 0;
        perfect_num = 0;
        great_num = 0;
        key_num = 0;
        player->stop();
        this->close();
    });

    //当游戏结束后出现此窗口，并播放BGM
    player = new QMediaPlayer;
    QMediaPlaylist* list = new QMediaPlaylist;
    list->addMedia(QUrl("qrc:/mus/result.ogg"));
    list->setPlaybackMode(QMediaPlaylist::Loop);
    player->setPlaylist(list);
    player->setVolume(50);//音量


}

void ResultWidget::init()
{
    //调试
//    qDebug()<<maxperfect_num;
//    qDebug()<<perfect_num;
//    qDebug()<<great_num;
//    qDebug()<<miss_num;
//    qDebug()<<get_score;



    ui->NameLabel->setText(user_name);
    ui->PttLabel->setText(QString::number(your_potential));
    ui->PerfectLabel->setText(QString::number(perfect_num)+"("+QString::number(maxperfect_num)+")");
    ui->GreatLabel->setText(QString::number(great_num));
    ui->MissLabel->setText(QString::number(miss_num));
    ui->SongNameLabel->setText(nameofsong);
    ui->ScoreLabel->setText(QString::number(get_score));
    ui->ComboLabel->setText(QString::number(highest_combo));
    QPixmap* icon = new QPixmap(":/test/ANIMA.jpg");//应实现随着歌曲名字换图（一会再写）
    ui->PictureLabel->setPixmap(*icon);

    if(get_score < 8000000)
    {
        get_level = "迷失";
        get_potential =current_potential * (double)get_score / (double)9500000;
    }
    else if(get_score >= 8000000 && get_score < 8800000)
    {
        get_level = "略知";
        get_potential = current_potential * (double)get_score / (double)9500000;
    }
    else if(get_score >= 8800000 && get_score < 9200000)
    {
        get_level = "了解";
        get_potential = current_potential * (double)get_score / (double)9500000;
    }
    else if(get_score >= 9200000 && get_score < 9500000)
    {
        get_level = "熟悉";
        get_potential = (current_potential - 1) + ((double)get_score - 9200000.0)/30000.0;
        }
    else if(get_score >= 9500000 && get_score < 9800000)
    {
        get_level = "通晓";
        get_potential = (current_potential) + ((double)get_score - 9500000.0)/30000.0;
    }
    else if(get_score >= 9800000 && get_score < 9900000)
    {
        get_level = "洞悉";
        get_potential = (current_potential + 1) + ((double)get_score - 9800000.0)/20000.0;
    }
    else if(get_score >= 9900000 && get_score < 10000000)
    {
        get_level = "洞悉+";
        get_potential = (current_potential + 1) + ((double)get_score - 9800000.0)/20000.0;
    }
    else if(get_score >= 10000000 && get_score < 10000000+key_num)
    {
        get_level = "征服";
        get_potential = current_potential + 2;
    }
    else if(get_score == 10000000 + key_num)
    {
        get_level = "制霸";
        get_potential = current_potential + 2;
    }
    else
    {
        get_level = "错误";
        get_potential = 0;
    }

    ui->LevelLabel->setText(get_level);
    player->play();//开始播放，也可以用按钮的方式，这里用的是菜单栏中的action

    mythread myT;
    myT.over_save();
}

ResultWidget::~ResultWidget()
{
    delete ui;
}

void ResultWidget::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Return)
        {
            qDebug()<<"push";
            emit ui->ContinueBtn->clicked();
        }
        else if(event->key() == Qt::Key_Escape)
        {
            qDebug()<<"push";
            emit ui->ContinueBtn->clicked();
        }
    }
}

