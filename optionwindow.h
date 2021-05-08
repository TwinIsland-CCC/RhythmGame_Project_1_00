#ifndef OPTIONWINDOW_H
#define OPTIONWINDOW_H

#include <QMainWindow>

#include "source.h"

namespace Ui {
class OptionWindow;
}

class OptionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OptionWindow(QWidget *parent = nullptr);
    ~OptionWindow();
    QMediaPlayer *meow;
    QMovie movie;


signals:
    void FinishBtnpushed();
    void CancelBtnpushed();
    void OpenBtnpushed();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::OptionWindow *ui;
};

#endif // OPTIONWINDOW_H
