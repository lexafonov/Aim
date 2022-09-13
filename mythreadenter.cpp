#include "mythreadenter.h"
#include "qhostaddress.h"

MyThreadEnter::MyThreadEnter()
{
    _udpSocket=new QUdpSocket;   // Создаем QUdpSocket
}

void MyThreadEnter::SetData(dataD &str){
    _struct = str;
}

void MyThreadEnter::run(){
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
