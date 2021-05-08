#ifndef DIFFICULTYANDSPEEDSELECTWINDOW_H
#define DIFFICULTYANDSPEEDSELECTWINDOW_H

#include <QMainWindow>
#include "source.h"
#include "gamewindow.h"
#include "mythread.h"

namespace Ui {
class DifficultyAndSpeedSelectWindow;
}

class DifficultyAndSpeedSelectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit DifficultyAndSpeedSelectWindow(QWidget *parent = nullptr);
    ~DifficultyAndSpeedSelectWindow();
    void init();
    QThread* loadthread;
    mythread* myload;
    Gamewindow* game;

private:
    Ui::DifficultyAndSpeedSelectWindow *ui;

protected:
    void keyPressEvent(QKeyEvent *event);

signals:
    void backbtnpushed();
    void Re_Select();
    void Music_Stop();
};

#endif // DIFFICULTYANDSPEEDSELECTWINDOW_H
