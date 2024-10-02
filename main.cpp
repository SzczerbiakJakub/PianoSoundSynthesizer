#include "mainwindowgui.h"
#include <QtWidgets/QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Virtual Synthesizer");
    w.show();
    return a.exec();
}