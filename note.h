#ifndef NOTE_H
#define NOTE_H

#include <QWidget>
#include <QTimer>

class Note : public QWidget
{
    Q_OBJECT
    //音符类
public:
    explicit Note(QWidget *parent = nullptr,int judge_interval = 0);
    QString image;//音符图片
    //需求：按照时间实现判定，而非音符距离判定线距离，这样才能实现调速功能
    QTimer judge;//用定时器进行判定
    int note_start_time;//音符在什么时候落下


signals:
    void maxperfect();//四种信号，对应四种判定
    void perfect();
    void great();
    void miss();
};

#endif // NOTE_H
