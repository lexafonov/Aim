#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>

class Client : public QDialog
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    ~Client();
public slots:
    void CloseBtnClicked();
    void dataReceived();
private:
    QTextEdit *ReceiveTextEdit;
    QPushButton *CloseBtn;
    QVBoxLayout *mainLayout;
    int port;
    QUdpSocket *udpSocket;
};

#endif // UDPCLIENT_H
