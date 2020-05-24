#include "mainwindow.h"
#include <QApplication>
#include <ImageMagick-7/Magick++.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Magick::InitializeMagick(*argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
