#include "mylabel.h"
#include <QDebug>

mylabel::mylabel(QWidget *parent) :
    QLabel(parent)
{

}

void mylabel::mousePressEvent(QMouseEvent *ev){

    emit this->clicked();

}

mylabel::~mylabel()
{

}
