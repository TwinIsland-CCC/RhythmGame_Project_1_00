#include "newroom.h"
#include "ui_newroom.h"

NewRoom::NewRoom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewRoom)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,[=](){
        user_name = ui->lineEdit->text();
        new_or_old = false;
        this->close();
    });

}

NewRoom::~NewRoom()
{
    delete ui;
}
