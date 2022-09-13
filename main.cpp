#include "server.h"
#include "client.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Server w;
    w.show();

    Client cl(w.GetPort());
    cl.show();

    return a.exec();
}
