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
    //threadOut() = default;
    threadOut(QObject * ptr = nullptr);
    ~threadOut() = default;
    void run();
private:
    QUdpSocket* udpSocket;
public slots:
    void dataReceived();
signals:
    void reprintDataWindow(dataD);
};

#endif // THREADOUT_H
