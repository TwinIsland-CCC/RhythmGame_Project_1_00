#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include "pausewindow.h"
#include "source.h"
#include "note.h"

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
    QMovie movie;
    QMediaPlayer* meow;
    QMediaPlayer* player = new QMediaPlayer;
    QTimer* bgtimer = new QTimer(this);
    QTimer* bgtimer2 = new QTimer(this);
    int song_length;
    int i;//第i个音符
    int remaining_length;
    int current = 0;
    int current2 = -400;
    int current_i = 0;
    int current_i2 = 0;
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
