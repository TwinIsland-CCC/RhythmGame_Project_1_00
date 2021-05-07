#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <string>
#include <sstream>
#include <QString>
#include <QTextStream>
#include <fstream>
#include "source.h"
#include "data.h"
#include <cstdio>
class mythread : public QObject
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr);

public slots:
    void load_widget();
    void load_song();
    void load_save();
    void keep_save();
    void calculate_judge();
signals:
    void load_widget_signal();
    void load_song_finsh();


};


#endif // MYTHREAD_H
