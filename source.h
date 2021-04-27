#ifndef SOURCE_H
#define SOURCE_H

#include <QApplication>
#include<QBitmap>
#include<QButtonGroup>
#include<QCheckBox>
#include<QCursor>
#include<QDataStream>
#include<QDebug>
#include<QFile>
#include<QFileDialog>
#include<QFont>
#include<QGraphicsBlurEffect>
#include<QGraphicsOpacityEffect>
#include<QKeyEvent>
#include<QLabel>
#include<QtMultimedia/QMediaPlayer>
#include<QtMultimedia/QMediaPlaylist>
#include<QMovie>
#include<QtMultimedia/QSound>
#include<QPainter>
#include<QParallelAnimationGroup>
#include<QPixmap>
#include<QPropertyAnimation>
#include<QRadioButton>
#include<QScrollArea>
#include<QSequentialAnimationGroup>
#include<QStackedWidget>
#include<QString>
#include<QTextCodec>
#include<QThread>
#include<QTime>
#include<QTimer>
#include<QVector>
#include<QWidget>
#include"note.h"

using namespace std;

const int numofsong = 3;

extern double your_result;
//计分机制：
//类似arcaea，满分10000000，连击不算分，每个key算10000000除以key总数的分数。
//共有四种判定，分别是max perfect，perfect，great，miss。
//perfect的分值是10000000除以key总数，max perfect的分值是perfect的分值+1
//great的分值是perfect的分值的50%，miss不得分。
//满分为10000000+key数，打出满分会触发特殊特效（敬请期待）

extern double your_potential;
//potential是一种表征游戏玩家实力的机制。
//potential计算机制：
//每次将谱面游玩结束，会根据你的成绩和谱面定数计算出在本首曲子中你应得的ptt数。
//具体计算方法有待确定

extern int combo;

extern QVector<Note*>Notes;//谱面的实现

extern int key_num;//总音符个数





class source
{
public:
    source();
};

#endif // SOURCE_H
