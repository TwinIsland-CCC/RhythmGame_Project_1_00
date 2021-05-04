#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QMainWindow>
#include "source.h"

namespace Ui {
class ResultWidget;
}

class ResultWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultWidget(QWidget *parent = nullptr);
    ~ResultWidget();

signals:
    void ContinueBtnpushed();

private:
    Ui::ResultWidget *ui;
};

#endif // RESULTWIDGET_H
