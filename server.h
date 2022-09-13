#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QtWidgets>
#include <QUdpSocket>
#include "ui_server.h"

class Server : public QWidget, public Ui::Server
{
    Q_OBJECT
public:
    Server(QWidget *parent = 0);
    ~Server();
    int GetPort() const;
public slots:
    void StartBtnClicked();
private:
    //QLabel *TimerLabel;
    //QLineEdit *TextLineEdit;
    //QPushButton *StartBtn;
    //QVBoxLayout *mainLayout;
    int port;
    QUdpSocket *udpSocket;
};

#endif // UDPSERVER_H
