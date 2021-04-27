#include "gamewindow.h"
#include "ui_gamewindow.h"

Gamewindow::Gamewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gamewindow)
{
    ui->setupUi(this);

    //主要的游戏交互窗口





}

Gamewindow::~Gamewindow()
{
    delete ui;
}
