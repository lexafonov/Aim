#include "mythread.h"
#include "qhostaddress.h"

MyThread::MyThread()
{
    _udpSocket=new QUdpSocket;   // Создаем QUdpSocket
}

void MyThread::SetData(dataD &str){
    _struct = str;
}

void MyThread::run(){
    //dataD str{_angle, _otH, _otV};
    int siz = sizeof(_struct);
    auto ptr = reinterpret_cast<char*>(&_struct);

    int length;
    if(ptr == nullptr)
    {
        return;
    }
    if((length=_udpSocket->writeDatagram(ptr, siz, QHostAddress::LocalHost, _port)) != siz)
    {
        return;
    }
}
