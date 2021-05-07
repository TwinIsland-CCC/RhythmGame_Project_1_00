#ifndef NEWROOM_H
#define NEWROOM_H

#include <QWidget>
#include "source.h"

namespace Ui {
class NewRoom;
}

class NewRoom : public QWidget
{
    Q_OBJECT

public:
    explicit NewRoom(QWidget *parent = nullptr);
    ~NewRoom();

private:
    Ui::NewRoom *ui;
};

#endif // NEWROOM_H
