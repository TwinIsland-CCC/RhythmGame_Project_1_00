#include "pausewindow.h"
#include "ui_pausewindow.h"

PauseWindow::PauseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PauseWindow)
{
    ui->setupUi(this);

    movie.setFileName(":/test/cat.gif");//已经在类中声明了movie
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

    connect(ui->ContinueBtn,&QPushButton::clicked,[=](){
        emit game_continue();
    });

    connect(ui->ExitBtn,&QPushButton::clicked,[=](){
        emit game_exit();
    });

    connect(ui->RestartBtn,&QPushButton::clicked,[=](){
        emit game_restart();
    });
}

PauseWindow::~PauseWindow()
{
    delete ui;
}

void PauseWindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Return)
        {
            emit ui->ContinueBtn->clicked();
        }
        else if(event->key() == Qt::Key_Escape)
        {
            emit ui->ContinueBtn->clicked();
        }
    }
}
