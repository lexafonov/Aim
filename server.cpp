#include "server.h"
#include <QHostAddress>
#include <QUdpSocket>
#include <QDebug>

Server::Server(QWidget *parent)
    : QWidget(parent)
{
    /* Инициализируем каждый элемент управления */
    //TimerLabel = new QLabel(tr("Таймер:"),this);
    //TextLineEdit = new QLineEdit(this);
    //StartBtn = new QPushButton(tr("Отправить"),this);
    ///* Устанавливаем макет */
    //mainLayout = new QVBoxLayout(this);
    //mainLayout->addWidget(TimerLabel);
    //mainLayout->addWidget(TextLineEdit);
    //mainLayout->addWidget(StartBtn);
    //connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));
    port = 5555;                // Устанавливаем параметр номера порта UDP
    udpSocket=new QUdpSocket;   // Создаем QUdpSocket
}

Server::~Server()
{

}

void Server::StartBtnClicked()
{
    //QString msg =TextLineEdit->text();
    QString msg = "kjkjkj";
    qDebug()<<msg.toLatin1();
    int length=0;
    if(msg == "")
    {
        return;
    }
    if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::LocalHost,port))!=msg.length())// QHostAddress :: Broadcast отправляет на широковещательный адрес
    {
        return;
    }
}
int Server::GetPort() const{
    return port;
}
