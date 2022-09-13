#include "client.h"
#include <QUdpSocket>
#include <QMessageBox>
#include <QHostAddress>
#include "common.h"

Client::Client(QWidget *parent) : QDialog(parent, Qt::Window | Qt::WindowCloseButtonHint)
{
    /* Инициализируем каждый элемент управления */
    ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"),this);
    /* Устанавливаем макет */
    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);
    connect(CloseBtn,SIGNAL(clicked()), this, SLOT(CloseBtnClicked()));
    // Устанавливаем параметр номера порта UDP, указываем для мониторинга данных по этому порту
    udpSocket = new QUdpSocket(this);		// Создаем QUdpSocket
    connect(udpSocket,SIGNAL(readyRead()), this, SLOT(dataReceived()));
    bool result=udpSocket->bind(_port);// Привязать порт
    if(!result)
    {
        QMessageBox::information(this,"error","udp socket create error!");
        return;
    }
}

void Client::CloseBtnClicked()
{
    close();
}

void Client::dataReceived()
{
    while(udpSocket->hasPendingDatagrams())// Есть дейтаграмма для чтения
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());

        auto str = reinterpret_cast<dataD*>(datagram.data());

        QString msg = QString::number(str->angle) + "\r\n" + QString::number(str->otH) + "\r\n" + QString::number(str->otV) + "\r\n";
        ReceiveTextEdit->insertPlainText(msg);
    }
}
