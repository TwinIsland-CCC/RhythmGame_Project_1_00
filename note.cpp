#include "note.h"

Note::Note(QWidget *parent) : QWidget(parent)
{
    //interval的数值，应是2倍判定区间，这样才能保证早晚判定的一致性
    //judge.start();
    //每一个音符有一个他自己的计时器，在计时器所允许的时间范围内才会触发判定。
    //如果计时器没关着，检测到按键按下后计时器停止
    //int remainingtime = interval-judge.elapsed();

//    connect(this,&Note::miss,[=]()//实现判定加分
//    {
//        been_judged = true;
//    });
//    connect(this,&Note::great,[=]()
//    {
//        get_score += (score_per_note / 2);
//        been_judged = true;
//    });
//    connect(this,&Note::perfect,[=]()
//    {
//        get_score += score_per_note;
//        been_judged = true;
//    });
//    connect(this,&Note::maxperfect,[=]()
//    {
//        get_score += (score_per_note + 1);
//        been_judged = true;
//    });

}

//Note::Note(QWidget *parent,QString img,QElapsedTimer* judge,double start_time,int typ)
//    : QWidget(parent),image(img),note_start_time(start_time),type(typ)
//{
//    //judge = new QElapsedTimer();
//    qDebug()<<"timer已创建";

//}

Note::Note(QWidget *parent,char typ,double start_time,QString img)
: QWidget(parent),note_start_time(start_time),type(typ)
{
    if(typ ==  'Z' || typ == 'V')
    {
        image = ":/key/key/key1.png";

    }
    else if(typ ==  'X' || typ == 'C')
    {
        image = ":/key/key/key2.png";
    }
    else
    {

    }

}

int Note::judgetrigggered()
{
    return judge.elapsed();
    //int remainingtime = interval-judge.elapsed();
}

Note::~Note()
{

}
