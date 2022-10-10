#include "mythreadenter.h"
#include <QUdpSocket>

void MyThreadEnter::SetData(dataD &str){
    _struct = str;
}

void MyThreadEnter::run(){
    QUdpSocket _udpSocket;
    int siz = sizeof(_struct);
    auto ptr = reinterpret_cast<char*>(&_struct);

    int length = _udpSocket.writeDatagram(ptr, siz, QHostAddress::LocalHost, _port);
    if(length != siz)
    {
        return;
    }
}
