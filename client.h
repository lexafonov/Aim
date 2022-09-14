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
#include <QtWidgets>

class Client : public QDialog, public Ui::Client
{
    Q_OBJECT

public:
    Client(QWidget *parent = 0);
    ~Client();
    void changedColorCombo(int);
    void changedAimCombo(int);
public slots:
    void CloseBtnClicked();
    //void dataReceived();
    void reDataWind(dataD);
private:
    QUdpSocket *udpSocket;
    threadOut* myThread;

    QStringList lstColor;
    QStringList lstAim;

    QBrush black = QBrush(QColor(0, 0, 0));
    QBrush white = QBrush(QColor(255, 255, 255));
    QBrush ser = QBrush(QColor(100, 100, 100));

    QGraphicsScene* scene = new QGraphicsScene(QRectF(-100,-100,300,300));
    QGraphicsRectItem * pRect;
};

#endif // UDPCLIENT_H
