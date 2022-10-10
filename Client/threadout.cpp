#include "threadout.h"
#include "qmetatype.h"
#include <QUdpSocket>

#define nameof(x) #x
auto id = qRegisterMetaType<dataD>(nameof(dataD));

void threadOut::run(){
    QUdpSocket udpSocket;
    bool result = udpSocket.bind(_port);     // Привязать порт
    if(!result)
    {
        return;
    }
    isRun = true;
    dataD d{};
    for(;isRun;){
        if(udpSocket.hasPendingDatagrams()){
            udpSocket.readDatagram(reinterpret_cast<char*>(&d), sizeof(d));
            emit reprintDataWindow(d);
        }
    }
}
void threadOut::notRun(){
    isRun = false;
}
