#include "qwikaccess.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qwikaccess w;
    w.show();
    return a.exec();
}
