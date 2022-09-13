#include "server.h"
#include <QHostAddress>
#include <QUdpSocket>
#include <QDebug>
#include "common.h"

Server::Server(QWidget *parent) : QWidget(parent, Qt::Window | Qt::WindowCloseButtonHint)
{
    /* Инициализируем каждый элемент управления */
    //TimerLabel = new QLabel(tr("Таймер:"),this);
    //TextLineEdit = new QLineEdit(this);
    //StartBtn = new QPushButton(tr("Отправить"),this);
    /* Устанавливаем макет */
    //mainLayout = new QVBoxLayout(this);
    //mainLayout->addWidget(TimerLabel);
    //mainLayout->addWidget(TextLineEdit);
    //mainLayout->addWidget(StartBtn);

    setupUi(this);

    connect(ButtonSend,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));

    _port = 5555;                // Устанавливаем параметр номера порта UDP
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
    if((length=udpSocket->writeDatagram(ptr, siz, QHostAddress::LocalHost,_port)) != siz)
    {
        return;
    }
}
int Server::GetPort() const{
    return _port;
}

void Server::on_SliderAngle_valueChanged(int value)
{
    _angle = value / 10.0;
    AngleLbl->setText(QString::number(_angle));
}


void Server::on_SliderOtstupH_valueChanged(int value)
{
    _otH = value / 100.0;
    OtstupHLbl->setText(QString::number(_otH));
}


void Server::on_SliderOtstupV_valueChanged(int value)
{
    _otV = value / 100.0;
    OtstupVLbl->setText(QString::number(_otV));
}

