#include "protutorialwidget.h"
#include "ui_protutorialwidget.h"

protutorialwidget::protutorialwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::protutorialwidget)
{
    ui->setupUi(this);
}

protutorialwidget::~protutorialwidget()
{
    delete ui;
}
