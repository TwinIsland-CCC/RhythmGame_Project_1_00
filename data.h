#ifndef DATA_H
#define DATA_H
#include <QString>
#include <QElapsedTimer>

//struct archive{
//    double potential;

//};

//struct score{
//    QString grade;
//    int res;


//};

struct rhythm
{
    int code;
    double token;
    char key;

};

struct archive
{
    int score;
    QString grade;
    double potential;
};

#endif // DATA_H
