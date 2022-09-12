#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QUdpSocket>
#include <QTimer>

class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = 0);
    ~Server();
public slots:
    void StartBtnClicked();
    void timeout();
private:
    QLabel *TimerLabel;
    QLineEdit *TextLineEdit;
    QPushButton *StartBtn;
    QVBoxLayout *mainLayout;
    int port;
    bool isStarted;
    QUdpSocket *udpSocket;
    QTimer *timer;
};

#endif // UDPSERVER_H
