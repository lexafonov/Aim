#ifndef THREADOUT_H
#define THREADOUT_H

#include <QUdpSocket>
#include <QThread>
#include "common.h"
#include <QMessageBox>
#include <QUdpSocket>

class threadOut : public QThread
{
    Q_OBJECT
public:
    threadOut(QObject * ptr = nullptr);
    ~threadOut();
    void run();
    void notRun();
private:
    QUdpSocket* udpSocket;
    bool isRun;
public slots:
    void dataReceived();
signals:
    void reprintDataWindow(dataD);
};

#endif // THREADOUT_H
