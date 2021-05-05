#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
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
    int song_length;
    int i;//第i个音符
    int remaining_length;

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
