#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QThread>
#include <QPixmap>
#include "source.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //开场动画（暂用校徽）
//    QPixmap pix(":/test/nku.png");
//    QSplashScreen *splash=new QSplashScreen(pix);
//    splash->show();
//    QThread::sleep(1);

    w.show();

//    splash->finish(&w);
//    delete splash;

    return a.exec();
}
