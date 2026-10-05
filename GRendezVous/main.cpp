#include "rdv.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rdv w;
    w.show();
    return QApplication::exec();
}