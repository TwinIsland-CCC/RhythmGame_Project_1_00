#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>
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
    char type = 'Z';
    int y = 0;
    void dealClose();

signals:
    void clicked();
    void showed();
    void flushed();

private:

};

#endif // MYLABEL_H
