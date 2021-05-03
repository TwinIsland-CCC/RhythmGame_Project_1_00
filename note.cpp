#include "note.h"

Note::Note(QWidget *parent,int interval) : QWidget(parent)
{
    //interval的数值，应是2倍判定区间，这样才能保证早晚判定的一致性
    //judge.start();
    //每一个音符有一个他自己的计时器，在计时器所允许的时间范围内才会触发判定。
    //如果计时器没关着，检测到按键按下后计时器停止
    //int remainingtime = interval-judge.elapsed();


}


void Note::judgetrigggered()
{
    judge->elapsed();
    //int remainingtime = interval-judge.elapsed();
}
