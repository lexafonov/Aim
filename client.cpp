#include "client.h"
#include <QUdpSocket>
#include <QMessageBox>
#include <QHostAddress>
#include "common.h"
#include <qcombobox.h>
#include <QRectF>

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
    //Список цветов фон
    lstColor << "Чёрный" << "Белый" << "Серый";
    comboBoxColorF->addItems(lstColor);
    comboBoxColorF->setEditable(true);
    connect(comboBoxColorF, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Client::changedColorCombo);

    //Список цветов прицела
    lstAim << "Красный" << "Черный";
    comboBoxAim->addItems(lstAim);
    comboBoxAim->setEditable(true);
    connect(comboBoxAim, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &Client::changedAimCombo);

    graphicsView->setScene(scene);
    pRect = scene->addRect(QRectF(-100,-100,120,80), QPen(Qt::black), QBrush(Qt::green));
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

void Client::changedColorCombo(int t){
    qDebug() << t;
    if(t == 0){
        //Черный
        pRect->setBrush(QBrush(Qt::black));
    }
    else if(t == 1){
        //Белый
        pRect->setBrush(QBrush(Qt::white));
    }
    else if(t == 2){
        //Серый
        pRect->setBrush(QBrush(Qt::gray));
    }
    else{
        //Ошибка
        qDebug() << "Некорректное значение переменной t\r\n";
    }
    graphicsView->update();
}

void Client::changedAimCombo(int t){

}
