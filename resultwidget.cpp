#include "resultwidget.h"
#include "ui_resultwidget.h"

ResultWidget::ResultWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWidget)
{
    ui->setupUi(this);

    //当游戏结束后出现此窗口，并播放BGM


}

ResultWidget::~ResultWidget()
{
    delete ui;
}
