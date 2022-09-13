#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "common.h"
#include <QUdpSocket>


class MyThread : public QThread
{
public:
    MyThread();
    ~MyThread() = default;
    void run();
    void SetData(dataD& str);
private:
    dataD _struct;
    QUdpSocket* _udpSocket;
};

#endif // MYTHREAD_H
