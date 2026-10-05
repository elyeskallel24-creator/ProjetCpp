#include "gpetmanager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GPetManager w;
    w.showMaximized();
    return a.exec();
}
