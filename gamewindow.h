#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "source.h"

namespace Ui {
class Gamewindow;
}

class Gamewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gamewindow(QWidget *parent = nullptr);
    void init();
    ~Gamewindow();
    QThread judgethread;

signals:
    void Z_triggered();
    void X_triggered();
    void Game_Over();


protected:
    void keyPressEvent(QKeyEvent *event);//检测按键
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::Gamewindow *ui;
};

#endif // GAMEWINDOW_H
