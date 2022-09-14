#include "threadout.h"
#include "QtDebug"

threadOut::threadOut(QObject* ptr) : QThread(ptr)  {
    udpSocket = new QUdpSocket(this);
    auto yyy = connect(udpSocket, &QUdpSocket::readyRead, this, &threadOut::dataReceived);
    udpSocket->moveToThread(this);
    bool result=udpSocket->bind(_port);     // Привязать порт
    if(!result)
    {
      //QMessageBox::information(this, "error", "udp socket create error!");
        return;
    }
}

void threadOut::run(){
    // Устанавливаем параметр номера порта UDP, указываем для мониторинга данных по этому порту
    //udpSocket = QUdpSocket(this);         // Создаем QUdpSocket
    for(;;){}
}
void threadOut::dataReceived()
{

        dataD d{};
        udpSocket->readDatagram(reinterpret_cast<char*>(&d), sizeof(d));
        emit reprintDataWindow(d);

        //AngleLbl->setText(QString::number(str->angle));
        //OtHLbl->setText(QString::number(str->otH));
        //OtVLbl->setText(QString::number(str->otV));
}
