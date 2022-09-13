#include "server.h"
#include <QHostAddress>
#include <QUdpSocket>
#include <QDebug>
#include "common.h"

Server::Server(QWidget *parent) : QWidget(parent, Qt::Window | Qt::WindowCloseButtonHint)
{
    setupUi(this);

    connect(ButtonSend, SIGNAL(clicked()), this, SLOT(StartBtnClicked()));

    connect(SliderAngle, SIGNAL(valueChanged(int)), this, SLOT(SliderAngleChanged(int)));
    connect(SliderOtstupH, SIGNAL(valueChanged(int)), this, SLOT(SliderOtstupHChanged(int)));
    connect(SliderOtstupV, SIGNAL(valueChanged(int)), this, SLOT(SliderOtstupVChanged(int)));


    udpSocket=new QUdpSocket;   // Создаем QUdpSocket

    //Угол камеры по горизонтали, град
    _angle = 3;
    SliderAngle->setValue(_angle * 10.0);
    AngleLbl->setText(QString::number(_angle));
    //Отступ по горизонтали
    _otH = 0.2;
    SliderOtstupH->setValue(_otH * 100.0);
    OtstupHLbl->setText(QString::number(_otH));
    //Отступ по вертикали
    _otV = -0.45;
    SliderOtstupV->setValue(_otV * 100.0);
    OtstupVLbl->setText(QString::number(_otV));
}

void Server::StartBtnClicked()
{
    dataD str{_angle, _otH, _otV};

    int siz = sizeof(str);
    auto ptr = reinterpret_cast<char*>(&str);

    int length=0;
    if(ptr == nullptr)
    {
        return;
    }
    // QHostAddress :: Broadcast отправляет на широковещательный адрес
    //if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::LocalHost,port))!=msg.length())
    if((length=udpSocket->writeDatagram(ptr, siz, QHostAddress::LocalHost, _port)) != siz)
    {
        return;
    }
}

void Server::SliderAngleChanged(int value)
{
    _angle = value / 10.0;
    AngleLbl->setText(QString::number(_angle));
}


void Server::SliderOtstupHChanged(int value)
{
    _otH = value / 100.0;
    OtstupHLbl->setText(QString::number(_otH));
}


void Server::SliderOtstupVChanged(int value)
{
    _otV = value / 100.0;
    OtstupVLbl->setText(QString::number(_otV));
}

