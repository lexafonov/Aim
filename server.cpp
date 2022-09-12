#include "server.h"
#include <QHostAddress>
#include <QUdpSocket>
#include <QDebug>

Server::Server(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(tr("UDP Server"));
    /* Инициализируем каждый элемент управления */
    TimerLabel = new QLabel(tr("Таймер:"),this);
    TextLineEdit = new QLineEdit(this);
    StartBtn = new QPushButton(tr("начать"),this);
    /* Устанавливаем макет */
    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(TimerLabel);
    mainLayout->addWidget(TextLineEdit);
    mainLayout->addWidget(StartBtn);
    connect(StartBtn,SIGNAL(clicked()),this,SLOT(StartBtnClicked()));
    port = 5555;		// Устанавливаем параметр номера порта UDP
    isStarted = false;
    udpSocket=new QUdpSocket;// Создаем QUdpSocket
    timer = new QTimer(this);
    // Регулярно отправлять информацию о трансляции
    connect(timer,SIGNAL(timeout()),this,SLOT(timeout()));
}

Server::~Server()
{

}

void Server::StartBtnClicked()
{
    if(!isStarted)
    {
        StartBtn->setText("Стоп");
        timer->start(1000);
        isStarted=true;
    }
    else
    {
        StartBtn->setText("начать");
        isStarted=false;
        timer->stop();
    }
}

void Server::timeout()
{
    QString msg =TextLineEdit->text();
    qDebug()<<msg.toLatin1();
    int length=0;
    if(msg=="")
    {
        return;
    }
    if((length=udpSocket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port))!=msg.length())// QHostAddress :: Broadcast отправляет на широковещательный адрес
    {
        return;
    }
}
