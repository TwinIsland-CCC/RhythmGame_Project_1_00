#ifndef DIFFICULTYANDSPEEDSELECTWINDOW_H
#define DIFFICULTYANDSPEEDSELECTWINDOW_H

#include <QMainWindow>

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

private:
    Ui::DifficultyAndSpeedSelectWindow *ui;

signals:
    void backbtnpushed();
    void Re_Select();
};

#endif // DIFFICULTYANDSPEEDSELECTWINDOW_H
