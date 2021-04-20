#include "tutorialwindow.h"
#include "ui_tutorialwindow.h"

tutorialwindow::tutorialwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tutorialwindow)
{
    ui->setupUi(this);
}

tutorialwindow::~tutorialwindow()
{
    delete ui;
}
