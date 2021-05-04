#include "optionwindow.h"
#include "ui_optionwindow.h"

OptionWindow::OptionWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OptionWindow)
{
    ui->setupUi(this);

    //点击back按钮回到mainwindow
    connect(ui->FinishBtn,&QPushButton::clicked,this,[=](){
        emit this->FinishBtnpushed();
    });

    connect(ui->CancelBtn,&QPushButton::clicked,this,[=](){
        emit this->CancelBtnpushed();
    });



}

OptionWindow::~OptionWindow()
{
    delete ui;
}
