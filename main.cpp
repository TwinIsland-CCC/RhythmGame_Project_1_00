#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QThread>
#include <QPixmap>
#include "source.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //开场动画（暂用校徽）
    QPixmap pix(":/test/nku.png");
    QSplashScreen *splash=new QSplashScreen(pix);
    splash->show();

    mythread myT;
    myT.load_save();

    QThread::sleep(1);

//    if(new_or_old)
//    {
//        NewRoom* ro = new NewRoom;
//        ro->setWindowModality(Qt::ApplicationModal);
//        ro->show();
//    }
    MainWindow w;

    w.show();





    splash->finish(&w);
    delete splash;

    return a.exec();
}
