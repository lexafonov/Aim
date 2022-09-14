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
    myThread = new threadOut();
    connect(myThread, &threadOut::reprintDataWindow, this, &Client::reDataWind);
    myThread->start(QThread::NormalPriority);
}
Client::~Client(){
    myThread->notRun();
    myThread->quit();
    myThread->wait();
    delete myThread;
}
void Client::CloseBtnClicked()
{
    close();
}

void Client::reDataWind(dataD str){
    AngleLbl->setText(QString::number(str.angle));
    OtHLbl->setText(QString::number(str.otH));
    OtVLbl->setText(QString::number(str.otV));
}
