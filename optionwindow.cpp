#include "optionwindow.h"
#include "ui_optionwindow.h"

OptionWindow::OptionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OptionWindow)
{
    ui->setupUi(this);
    ui->NameEdit->setText(user_name);


    movie.setFileName(":/test/cat3.gif");//已经在类中声明了movie
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

    //点击back按钮回到mainwindow
    connect(ui->FinishBtn,&QPushButton::clicked,this,[=](){
        user_name = ui->NameEdit->text();
        mythread myT;
        myT.inf_save();
        emit this->FinishBtnpushed();
    });

    connect(ui->CancelBtn,&QPushButton::clicked,this,[=](){
        ui->NameEdit->setText(user_name);
        emit this->CancelBtnpushed();
    });

    connect(ui->OpenBtn,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开");
        ui->IconEdit->setText(path);
        user_icon = path;
        emit this->OpenBtnpushed();
    });

}

OptionWindow::~OptionWindow()
{
    delete ui;
}

void OptionWindow::keyPressEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat())
    {
        if(event->key() == Qt::Key_Return)
        {
            qDebug()<<"push";
            emit ui->FinishBtn->clicked();
        }
        else if(event->key() == Qt::Key_Escape)
        {
            qDebug()<<"push";
            emit ui->CancelBtn->clicked();
        }
    }
}
