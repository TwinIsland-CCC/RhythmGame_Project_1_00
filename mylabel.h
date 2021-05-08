#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
#include "source.h"
#include <QMouseEvent>

namespace Ui {
class mylabel;
}

class mylabel : public QLabel
{
    Q_OBJECT

public:
    explicit mylabel(QWidget *parent = nullptr);
    ~mylabel();
    void mousePressEvent(QMouseEvent *ev);
    int y = 0;

signals:
    void clicked();

private:

};

#endif // MYLABEL_H
