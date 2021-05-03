#ifndef RESULTWIDGET_H
#define RESULTWIDGET_H

#include <QMainWindow>

namespace Ui {
class ResultWidget;
}

class ResultWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultWidget(QWidget *parent = nullptr);
    ~ResultWidget();

private:
    Ui::ResultWidget *ui;
};

#endif // RESULTWIDGET_H
