#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include "tutorialwindow.h"
#include "protutorialwidget.h"
#include "playscene.h"

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
    QMovie movie;

};
#endif // MAINWINDOW_H
