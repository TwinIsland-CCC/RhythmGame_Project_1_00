#include "resultwidget.h"
#include "ui_resultwidget.h"

ResultWidget::ResultWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWidget)
{
    ui->setupUi(this);

    connect(ui->ContinueBtn,&QPushButton::clicked,this,[=](){
        emit this->ContinueBtnpushed();
        this->close();
    });

    //当游戏结束后出现此窗口，并播放BGM


}

ResultWidget::~ResultWidget()
{
    delete ui;
}
