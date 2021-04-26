#include "difficultyandspeedselectwindow.h"
#include "ui_difficultyandspeedselectwindow.h"

DifficultyAndSpeedSelectWindow::DifficultyAndSpeedSelectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DifficultyAndSpeedSelectWindow)
{
    ui->setupUi(this);
}

DifficultyAndSpeedSelectWindow::~DifficultyAndSpeedSelectWindow()
{
    delete ui;
}
