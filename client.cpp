#include "client.h"
#include <QUdpSocket>
#include <QMessageBox>
#include <QHostAddress>
#include "common.h"

Client::Client(QWidget *parent) : QDialog(parent, Qt::Window | Qt::WindowCloseButtonHint)
{
    setupUi(this);

    AngleLbl->setText(QString::number(2));
    OtHLbl->setText(QString::number(0));
    OtVLbl->setText(QString::number(0));

    // Устанавливаем параметр номера порта UDP, указываем для мониторинга данных по этому порту
    /*udpSocket = new QUdpSocket(this);		// Создаем QUdpSocket
    connect(udpSocket,SIGNAL(readyRead()), this, SLOT(dataReceived()));
    bool result=udpSocket->bind(_port);// Привязать порт
    if(!result)
    {
        QMessageBox::information(this,"error","udp socket create error!");
        return;
    }*/

    myThread = new threadOut();
    //udpSocket->moveToThread(myThread);
    connect(myThread, &threadOut::reprintDataWindow, this, &Client::reDataWind);
    myThread->start(QThread::NormalPriority);
}
Client::~Client(){
    myThread->quit();
    myThread->wait();
    delete myThread;
}
void Client::CloseBtnClicked()
{
    close();
}

/*void Client::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())// Есть дейтаграмма для чтения
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());

        auto str = reinterpret_cast<dataD*>(datagram.data());

        //QString msg = QString::number(str->angle) + "\r\n" + QString::number(str->otH) + "\r\n" + QString::number(str->otV) + "\r\n";
        //ReceiveTextEdit->insertPlainText(msg);
        reDataWind(*str);
    }
}*/
void Client::reDataWind(dataD str){
    AngleLbl->setText(QString::number(str.angle));
    OtHLbl->setText(QString::number(str.otH));
    OtVLbl->setText(QString::number(str.otV));
}
