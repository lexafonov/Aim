#ifndef MYTHREADENTER_H
#define MYTHREADENTER_H

#include <QThread>
#include "common.h"


class MyThreadEnter : public QThread
{
public:
    using QThread::QThread;
    void run();
    void SetData(dataD& str);
private:
    dataD _struct;
};

#endif // MYTHREADENTER_H
