#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include "tutorialwindow.h"
#include "protutorialwidget.h"
#include "source.h"
#include <QMediaPlayer>
#include "playscene.h"
#include "mythread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    tutorialwindow tutorial1;
    protutorialwidget tutorial2;

    QThread* initthread;
    mythread* init;

    QMovie movie;
    QMediaPlayer *player;
    QMediaPlayer *meow;

};
#endif // MAINWINDOW_H
