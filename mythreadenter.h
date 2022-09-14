#ifndef MYTHREADENTER_H
#define MYTHREADENTER_H

#include <QThread>
#include "common.h"
#include <QUdpSocket>


class MyThreadEnter : public QThread
{
public:
    MyThreadEnter(QObject * ptr = nullptr);
    ~MyThreadEnter();
    void run();
    void SetData(dataD& str);
private:
    dataD _struct;
    QUdpSocket* _udpSocket;
};

#endif // MYTHREADENTER_H
