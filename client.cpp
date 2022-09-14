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
}

void Client::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Создаём объект отрисовщика
    // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    int hh = height() - 100;
    int ww = width();
    painter.fillRect(0, 0, ww, hh, QBrush(Qt::black, Qt::SolidPattern));
    if(comboBoxColorF->currentIndex() == 0){
        //Черный
        painter.fillRect(0, 0, ww, hh,QBrush(Qt::black, Qt::SolidPattern));
    }
    else if(comboBoxColorF->currentIndex() == 1){
        //Белый
        painter.fillRect(0, 0, ww, hh,QBrush(Qt::white, Qt::SolidPattern));
    }
    else if(comboBoxColorF->currentIndex() == 2){
        //Серый
        painter.fillRect(0, 0, ww, hh,QBrush(Qt::gray, Qt::SolidPattern));
    }
    else{
        painter.fillRect(0, 0, ww, hh,QBrush(Qt::white, Qt::SolidPattern));
    }
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

    }
    else if(t == 1){

    }
    else if(t == 2){

    }
    else{
        //Ошибка
        qDebug() << "Некорректное значение переменной t\r\n";
    }
    repaint();
}

void Client::changedAimCombo(int t){

}
