#include "note.h"

Note::Note(QWidget *parent) : QWidget(parent)
{

}

Note::Note(QWidget *parent,double start_time,char typ,QString img)
: QWidget(parent),note_start_time(start_time),type(typ)
{
    if(typ ==  'Z' || typ == 'V')
    {
        move(320,0);
        image = ":/key/key/key1.png";

    }
    else if(typ ==  'X' || typ == 'C')
    {
        move(480,0);
        image = ":/key/key/key2.png";

    }
    else
    {

    }
    resize(124,124);

}

int Note::judgetrigggered()
{
    return judge->elapsed();
}

Note::~Note()
{

}

