#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QMainWindow>
#include "source.h"
#include "mythread.h"

namespace Ui {
class ResultWidget;
}

class ResultWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultWidget(QWidget *parent = nullptr);
    void init();
    ~ResultWidget();
    QMediaPlayer* player;
signals:
    void ContinueBtnpushed();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::ResultWidget *ui;
};

#endif // RESULTWIDGET_H
