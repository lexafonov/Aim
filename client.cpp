#include "client.h"
#include <QUdpSocket>
#include <QMessageBox>
#include <QHostAddress>

Client::Client(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UDP Client"));		// Устанавливаем заголовок формы
    /* Инициализируем каждый элемент управления */
    ReceiveTextEdit = new QTextEdit(this);
    CloseBtn = new QPushButton(tr("Close"),this);
    /* Устанавливаем макет */
    mainLayout=new QVBoxLayout(this);
    mainLayout->addWidget(ReceiveTextEdit);
    mainLayout->addWidget(CloseBtn);
    connect(CloseBtn,SIGNAL(clicked()),this,SLOT(CloseBtnClicked()));
    port =5555;                             // Устанавливаем параметр номера порта UDP, указываем для мониторинга данных по этому порту
    udpSocket = new QUdpSocket(this);		// Создаем QUdpSocket
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(dataReceived()));
    bool result=udpSocket->bind(port);// Привязать порт
    if(!result)
    {
        QMessageBox::information(this,"error","udp socket create error!");
        return;
    }
}

Client::~Client()
{

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
        QString msg=datagram.data();
        ReceiveTextEdit->insertPlainText(msg);
    }
}
