#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QElapsedTimer>
#include <QTime>
#include <QDebug>
#include "source.h"

class Note : public QWidget
{
    Q_OBJECT
    //音符类
public:
    explicit Note(QWidget *parent = nullptr);
    //explicit Note(QWidget *parent = nullptr,QString img = "",QElapsedTimer* judge = new QElapsedTimer,double note_start_time = 0,int type = 0);
    explicit Note(QWidget *parent = nullptr,char type = 'Z',double note_start_time = 0,QString img = "");
    ~Note();
    QString image;//音符材质
    //需求：按照时间实现判定，而非音符距离判定线距离，这样才能良好地实现调速功能
    QElapsedTimer judge;//用定时器进行判定
    double note_start_time;//音符在什么时候落下
    char type;//0代表在左，1代表在右
    //type是音符的类型，暂时只有0和1，都是单键
    int y = 0;//实现动画
    bool been_judged = false;

signals:
    void maxperfect();//四种信号，对应四种判定
    void perfect();
    void great();
    void miss();

public slots:
    int judgetrigggered();

};

#endif // NOTE_H
