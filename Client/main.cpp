#include "client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client cl;
    cl.show();

    return a.exec();
}
