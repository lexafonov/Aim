#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>
#include "server.h"
#include "ui_client.h"
#include "threadout.h"

class Client : public QDialog, public Ui::Client
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    ~Client();
public slots:
    void CloseBtnClicked();
    //void dataReceived();
    void reDataWind(dataD);
private:
    //QTextEdit *ReceiveTextEdit;
    //QPushButton *CloseBtn;
    //QVBoxLayout *mainLayout;
    QUdpSocket *udpSocket;
    threadOut* myThread;
};

#endif // UDPCLIENT_H
