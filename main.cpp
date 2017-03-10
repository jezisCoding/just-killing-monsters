#include <iostream>
//#include "gameengine.h"
#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    //uncomment for CLI build
    //GameEngine engine;
    //engine.play();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
