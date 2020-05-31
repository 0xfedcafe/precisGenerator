#include "mainwindow.h"
#include <QApplication>
#include <ImageMagick-7/Magick++.h>
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"Russian");
    QApplication a(argc, argv);
    Magick::InitializeMagick(*argv);
    MainWindow w;
    w.show();
    return QApplication::exec();
}
