#ifndef TUTORIALWINDOW_H
#define TUTORIALWINDOW_H

#include <QWidget>

namespace Ui {
class tutorialwindow;
}

class tutorialwindow : public QWidget
{
    Q_OBJECT

public:
    explicit tutorialwindow(QWidget *parent = nullptr);
    ~tutorialwindow();

private:
    Ui::tutorialwindow *ui;
};

#endif // TUTORIALWINDOW_H
