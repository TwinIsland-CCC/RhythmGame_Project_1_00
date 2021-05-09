#include "mylabel.h"
#include <QDebug>

mylabel::mylabel(QWidget *parent) :
    QLabel(parent)
{
    connect(this,&mylabel::showed,[=]()
    {

    });
}

void mylabel::mousePressEvent(QMouseEvent *ev){

    emit this->clicked();

}

void mylabel::dealClose()
{
    emit this->flushed();
    this->close();

}

mylabel::~mylabel()
{

}
