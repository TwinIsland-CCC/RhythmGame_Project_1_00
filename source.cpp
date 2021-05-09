#include "source.h"

QString user_name = "CCC";
QString user_icon = ":/test/icon1.jpg";

QString nameofsong = "";//选中的歌曲名字

bool new_or_old = true;//true为新手，默认为true

double your_result = 0;//初始化成绩

double your_potential = 0;//初始化ptt

double BPM = 0;

int current_song = 0;//默认选择的歌

int combo = 0;//初始化连击数

double current_potential = 0;//初始化歌曲ptt

QVector<Note*>Notes = {};//谱面的实现

int level = 0;

int key_num = 0;//总音符个数

int interval = 200;//判定区间


//初始化局内数据
int maxperfect_num = 0;
int perfect_num = 0;
int great_num = 0;
int miss_num = 0;
double tp = 0;
double score_per_note = 0;
int highest_combo = 0;
int get_score = 0;
QString get_level = "";
double get_potential = 0;//初始化获得的ptt

QVector<archive>save_data = {};//初始化存档数据

QVector<rhythm>key_load = {};  //初始化谱面数据



QTime myTime;

QTimer *myTimer=new QTimer;

int wait_time=0;    //等待时长

int begin_time=0;   //开始时刻

int pause_time=0;   //暂停时长

int pause_begin=0;  //暂停时刻

double time_per_beat=0;

int intervall=0;   //定时器超时时间间隔

double current_speed=0;

QVector<mylabel*>float_key={};     //用于创建音符

source::source()
{

}
