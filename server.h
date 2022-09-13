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
    int GetPort() const;
public slots:
    void StartBtnClicked();
private slots:
    void on_SliderAngle_valueChanged(int value);

    void on_SliderOtstupH_valueChanged(int value);

    void on_SliderOtstupV_valueChanged(int value);

private:
    int _port;
    QUdpSocket *udpSocket;
    //Значения слайдеров
    qreal _angle;
    qreal _otH;
    qreal _otV;
};

#endif // UDPSERVER_H
