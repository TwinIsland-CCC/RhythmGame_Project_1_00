#ifndef PROTUTORIALWIDGET_H
#define PROTUTORIALWIDGET_H

#include <QWidget>

namespace Ui {
class protutorialwidget;
}

class protutorialwidget : public QWidget
{
    Q_OBJECT

public:
    explicit protutorialwidget(QWidget *parent = nullptr);
    ~protutorialwidget();

private:
    Ui::protutorialwidget *ui;
};

#endif // PROTUTORIALWIDGET_H
