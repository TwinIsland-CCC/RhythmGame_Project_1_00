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

    QString filename="../table/"+nameofsong+".txt";
    qDebug()<<filename;
//    QTextCodec *code = QTextCodec::codecForName("GB2312");//解决中文路径问题
    string name = filename.toStdString();
    fstream file(name,ios::in);
    //if(file)
    {
        file.read(reinterpret_cast<char*>(&BPM),sizeof(BPM));

        rhythm note;
        while(file.read(reinterpret_cast<char*>(&note),sizeof(note)))
        {
            key_load.push_back(note);
        }
        key_num=key_load.size();//初始化总key数
        qDebug()<<key_num;
        for(int i=0;i<key_num;i++)
        {
            Note* dot = new Note(nullptr,key_load[i].token,key_load[i].key);
            Notes.push_back(dot);
        }
        file.close();

        emit load_song_finsh();

    }
    //else
    {
        //cout<<"fail";
    }
}

void mythread::load_save()
{
    cout<<"load_save执行了";
    //读取存挡
    ifstream save_file;
    string path = "../save/save.txt";
    save_file.open(path, ios::in|ios::binary);//以二进制方式为读文件而打开文件
    if (!save_file)
    {
        archive save;
        for(int i=0;i<numofsong;i++)
        {
            save.code=i;
            save.grade=' ';
            save.score=0;
            save_data.push_back(save);
        }
    }
    else
    {
        archive save;
        while(save_file.read(reinterpret_cast<char*>(&save),sizeof(save)))
        {
            save_data.push_back(save);
        }
        save_file.close();
    }

}

void mythread::keep_save()
{
    cout<<"keep_save执行了";
    if(save_data.size()!=0)
    {
        ofstream save_file("../save/save.txt",ios::out|ios::binary);

        for(int i=0;i<numofsong;i++)
        {
            save_file.write(reinterpret_cast<char*>(&save_data[i]),sizeof(save_data[i]));
        }

        save_file.close();
    }
}

void mythread::calculate_judge()
{



}
