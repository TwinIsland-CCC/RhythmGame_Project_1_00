#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QElapsedTimer>
#include <QTime>

class Note : public QWidget
{
    Q_OBJECT
    //音符类
public:
    explicit Note(QWidget *parent = nullptr,int judge_interval = 0);
    QString image;//音符材质
    //需求：按照时间实现判定，而非音符距离判定线距离，这样才能良好地实现调速功能
    QElapsedTimer judge;//用定时器进行判定
    double note_start_time;//音符在什么时候落下
    int type = 0;//0代表在左，1代表在右


signals:
    void maxperfect();//四种信号，对应四种判定
    void perfect();
    void great();
    void miss();

public slots:
    void judgetrigggered();

};

#endif // NOTE_H
