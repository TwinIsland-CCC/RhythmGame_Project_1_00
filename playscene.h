#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QMediaPlayer>
#include "source.h"

namespace Ui {
class PlayScene;
}

class PlayScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayScene(QWidget *parent = nullptr);
    ~PlayScene();
    QMediaPlayer* preview;

private:
    Ui::PlayScene *ui;

signals:
    void backbtnpushed();
};

#endif // PLAYSCENE_H
