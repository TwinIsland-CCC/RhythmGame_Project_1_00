#include "mythread.h"
#define cout qDebug() << "[" <<__FILE__ <<":"<<__FUNCTION__<<":"<<__LINE__ <<"]"

mythread::mythread(QObject *parent) : QObject(parent)
{

}

void mythread::load_widget()
{
    //QThread::sleep(1);
    emit load_widget_signal();
}

void mythread::load_song()
{

    cout<<"load_song执行了";

    QString filename=":/table/"+nameofsong+".txt";
    QString filename2 = "C:/Users/CCC/Desktop/qt/RhythmGame_Project_1_00/table/"+nameofsong+".txt";
    qDebug()<<filename;
    QFile* file = new QFile(filename2);

    file->open(QIODevice::ReadOnly);
    //if (!file->isReadable())return;
    //QByteArray arr = file->readAll();
    //QString str = arr;
    //qDebug()<<str<<"is couted";
    QTextStream str1(file);
    int tem1,tem2,tem3;

    str1>>current_potential;
    qDebug()<<"当前歌曲的ptt为"<<current_potential;
    while(!str1.atEnd())
    {
        rhythm note;
        str1 >> note.code;
        str1>>tem1>>tem2>>tem3;
        str1 >> note.key;
        str1 >> note.token;
        key_num++;
        //qDebug()<<note.code <<" "<< note.key <<" "<< note.token<<" ";//<<key_num;
        key_load.push_back(note);

    }

    cout<<key_num;
    miss_num = key_num;
    score_per_note = 10000000 / key_num;
    for(int i=0;i<key_num;i++)
    {
        //qDebug()<<"在给第"<<i<<"个音符赋值";
        Note* dot = new Note(nullptr,key_load[i].token,key_load[i].key);
        Notes.push_back(dot);
        mylabel* dot2 = new mylabel;
        dot2->setPixmap(dot->image);
        float_key.push_back(dot2);
        float_key[i]->resize(64,64);
        float_key[i]->setScaledContents(true);
        float_key[i]->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
        if(dot->type == 'Z' || dot->type == 'V')
        {
            float_key[i]->type = 'Z';
        }
        else if(dot->type == 'X' || dot->type == 'C')
        {
            float_key[i]->type = 'X';
        }
    }
    file->close();

    emit load_song_finsh();
    key_num -= 1;
    qDebug()<<"共有"<<key_num<<"个音符";
    cout<<"load_song执行完毕";

}

void mythread::load_save()
{
    cout<<"load_save执行了";

    QString filename1 = "C:/Users/CCC/Desktop/qt/RhythmGame_Project_1_00/save/songsave.txt";
    QString filename2 = "C:/Users/CCC/Desktop/qt/RhythmGame_Project_1_00/save/hostsave.txt";
    QFile* file1 = new QFile(filename1);
    QFile* file2 = new QFile(filename2);
    file1->open(QIODevice::ReadOnly);
    file2->open(QIODevice::ReadOnly);
    QTextStream str1(file1);
    QTextStream str2(file2);
    str1.setCodec("UTF-8");
    str2.setCodec("UTF-8");

    int tem1,tem2,tem3;
    qDebug()<<"str2读取了！";
    str2 >> user_name;
    qDebug()<<user_name;

    str2 >> user_icon;
    qDebug()<<user_icon;

    str2 >> your_potential;
    qDebug()<<your_potential;

    while(!str1.atEnd())
    {
        qDebug()<<"str1读取了！";
        archive a;
        str1 >> a.score;
        qDebug()<<a.score;
        str1 >> tem1;
        str1 >> tem2;
        str1 >> tem3;
        str1 >> a.grade;
        qDebug()<<a.grade;
        str1 >> a.potential;
        qDebug()<<a.potential;
        save_data.push_back(a);

    }

    file1->close();
    file2->close();

    cout<<"load_save执行完毕";

}


void mythread::over_save()//保存
{
    cout<<"over_save执行了";
    QString filename1 = "C:/Users/CCC/Desktop/qt/RhythmGame_Project_1_00/save/songsave.txt";
    QString filename2 = "C:/Users/CCC/Desktop/qt/RhythmGame_Project_1_00/save/hostsave.txt";
    QFile* file1 = new QFile(filename2);//存歌
    QFile* file2 = new QFile(filename1);//存信息
//    file1->open(QIODevice::WriteOnly);
//    file2->open(QIODevice::WriteOnly);
    file1->open(QIODevice::ReadWrite);
    file2->open(QIODevice::ReadWrite);
    QTextStream str1(file1);
    QTextStream str2(file2);
    str1.setCodec("UTF-8");
    str2.setCodec("UTF-8");

    archive get;
    if(get_score>=save_data[current_song].score)
    {
        get.grade = get_level;
        get.score = get_score;
        get.potential = get_potential;
        save_data[current_song] = get;


        QString get2 = "";
        for(int t = 0 ;t < numofsong ;t++)
        {
            get2 += QString::number(save_data[t].score) + " " + save_data[t].grade + " " + QString::number(save_data[t].potential) + "\n";
        }
        qDebug()<<get2;
        file2->flush();
        cout<<"file2的flush执行完毕";
        str2<<get2;
        cout<<"get2已导入";
    }
    else
    {
        cout<<"分数更低了，无需导入";
    }

    file1->close();
    file2->close();

    cout<<"over_save执行完毕";


}

void mythread::inf_save()
{
    cout<<"inf_save执行了";
    QString filename1 = "C:/Users/CCC/Desktop/qt/RhythmGame_Project_1_00/save/hostsave.txt";
    QFile* file = new QFile(filename1);//存信息
    file->open(QIODevice::ReadWrite);
    QTextStream str1(file);
    str1.setCodec("UTF-8");
    QString inf = user_name + " " + user_icon + " " + QString::number(your_potential);
    file->flush();
    str1<<inf;
    file->close();
    cout<<"inf_save执行完成";

}

void mythread::calculate_judge()
{



}
