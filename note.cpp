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

Note::Note(QWidget *parent,double start_time,char typ,QString img)
: QWidget(parent),note_start_time(start_time),type(typ)
{
    if(typ ==  'Z' || typ == 'V')
    {
        move(320,0);
        image = ":/key/key/key1.png";
        //drawBackGround(this,img);
//        QFrame *frame = new QFrame;
//         frame->setObjectName("myframe");
//         frame->resize(124,124);
//         frame->setStyleSheet("QFrame#myframe{border-image:url(qrc:/key/key/key1.png)}" );
//         frame->show();

    }
    else if(typ ==  'X' || typ == 'C')
    {
        move(480,0);
        image = ":/key/key/key2.png";
        //drawBackGround(this,img);
//        QFrame *frame = new QFrame;
//         frame->setObjectName("myframe");
//         frame->resize(124,124);
//         frame->setStyleSheet("QFrame#myframe{border-image:url(qrc:/key/key/key2.png)}" );
//         frame->show();

    }
    else
    {

    }
    resize(124,124);

}

int Note::judgetrigggered()
{
    return judge->elapsed();
    //int remainingtime = interval-judge.elapsed();
}

Note::~Note()
{

}

void Note::drawBackGround(QWidget* w,QString img)
{
    w->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = w->palette();
    palette.setBrush(QPalette::Window,
            QBrush(QPixmap(img).scaled(// 缩放背景图.
                w->size(),
                Qt::IgnoreAspectRatio,
                Qt::SmoothTransformation)));             // 使用平滑的缩放方式
    w->setPalette(palette);
}
