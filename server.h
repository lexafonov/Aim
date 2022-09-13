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
    ~Server() = default;
public slots:
    void StartBtnClicked();
private slots:
    void SliderAngleChanged(int value);
    void SliderOtstupHChanged(int value);
    void SliderOtstupVChanged(int value);

private:
    QUdpSocket *udpSocket;
    //Значения слайдеров
    qreal _angle;
    qreal _otH;
    qreal _otV;
};

#endif // UDPSERVER_H
