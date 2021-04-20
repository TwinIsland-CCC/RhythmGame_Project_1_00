#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDialog>
#include <QPushButton>
#include "tutorialwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //点击工具栏帮助中新手教程，弹出一个窗口，里面显示一张图片（新手教程）
    connect(ui->tutorial,&QAction::triggered,this,[=](){
        tutorial1.show();
    });

    //点击工具栏帮助中进阶教程，弹出一个窗口，里面显示另一张图片（进阶教程）
    connect(ui->protutorial,&QAction::triggered,this,[=](){
        tutorial2.show();
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

