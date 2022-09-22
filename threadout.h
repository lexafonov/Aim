#ifndef THREADOUT_H
#define THREADOUT_H

#include <QThread>
#include "common.h"

class threadOut : public QThread
{
    Q_OBJECT
public:
    using QThread::QThread;
    void run();
    void notRun();
private:
    bool isRun{false};
signals:
    void reprintDataWindow(dataD);
};

#endif // THREADOUT_H
