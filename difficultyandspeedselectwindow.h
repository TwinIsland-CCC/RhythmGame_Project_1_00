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

private:
    Ui::DifficultyAndSpeedSelectWindow *ui;
};

#endif // DIFFICULTYANDSPEEDSELECTWINDOW_H
