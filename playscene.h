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
    void Re_init();
    void Re_init_icon();
    QLabel* statuslabel;
    QString statusbartext;
    int i;//第i首歌
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::PlayScene *ui;

signals:
    void backbtnpushed();
};

#endif // PLAYSCENE_H
