#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.wybor_testu_i_gen();
    w.show();

    return a.exec();
}
