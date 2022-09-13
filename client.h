#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>
#include "server.h"
#include "ui_client.h"

class Client : public QDialog, public Ui::Client
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    ~Client() = default;
public slots:
    void CloseBtnClicked();
    void dataReceived();
private:
    //QTextEdit *ReceiveTextEdit;
    //QPushButton *CloseBtn;
    //QVBoxLayout *mainLayout;
    QUdpSocket *udpSocket;
};

#endif // UDPCLIENT_H
