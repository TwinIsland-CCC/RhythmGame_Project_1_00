#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include <QWidget>
#include <QMovie>
#include "source.h"

namespace Ui {
class PauseWindow;
}

class PauseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit PauseWindow(QWidget *parent = nullptr);
    ~PauseWindow();
    QMovie movie;
    QMediaPlayer* meow;

signals:
    void game_continue();
    void game_restart();
    void game_exit();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::PauseWindow *ui;
};

#endif // PAUSEWINDOW_H
