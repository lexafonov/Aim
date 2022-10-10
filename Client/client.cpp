#include "client.h"

Client::Client(QWidget *parent) : QDialog(parent, Qt::Window)
{
    setupUi(this);

    AngleLbl->setText(QString::number(2));
    OtHLbl->setText(QString::number(0));
    OtVLbl->setText(QString::number(0));

    // Устанавливаем параметр номера порта UDP, указываем для мониторинга данных по этому порту
    connect(&myThread, &threadOut::reprintDataWindow, this, &Client::reDataWind);
    myThread.start(QThread::NormalPriority);

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

    resize(widt, widt * 3 / 4 + 100);
}

void Client::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this); // Создаём объект отрисовщика
    // Устанавливаем кисть абриса
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));

    int marg = 5;
    int ww = width() - 2 * marg;
    int hh = ww * 3 / 4;

    //Задать максимальный размер отрисовки графики
    painter.setClipRect(marg, marg, ww, hh);

    painter.fillRect(marg, marg, ww, hh, QBrush(Qt::black, Qt::SolidPattern));
    if(comboBoxColorF->currentIndex() == 0){
        //Черный
        painter.fillRect(marg, marg, ww, hh, QBrush(Qt::black, Qt::SolidPattern));
    }
    else if(comboBoxColorF->currentIndex() == 1){
        //Белый
        painter.fillRect(marg, marg, ww, hh, QBrush(Qt::white, Qt::SolidPattern));
    }
    else if(comboBoxColorF->currentIndex() == 2){
        //Серый
        painter.fillRect(marg, marg, ww, hh, QBrush(Qt::gray, Qt::SolidPattern));
    }
    else{
        painter.fillRect(marg, marg, ww, hh, QBrush(Qt::white, Qt::SolidPattern));
    }
    //Теперь отрисовка зеленого кретстика
    qreal xC = marg + ww / 2.0;
    qreal yC = marg + hh / 2.0;
    int hKr = 20;
    QLineF lineFH(xC - hKr, yC, xC + hKr, yC);
    QLineF lineFV(xC, yC - hKr, xC, yC + hKr);
    painter.setPen(QPen(Qt::green, 2, Qt::SolidLine, Qt::FlatCap));
    painter.drawLine(lineFH);
    painter.drawLine(lineFV);

    //А теперь вставка SVG-изображения
    //Размер прицела в зависимости от входного угла
    int razmPix = 1024 / 8;
    qreal length = angle * razmPix * 6000.0 / 360.0 / 20.0 * (ww / widt);
    qreal coordC = length / 2.0;
    qreal smH = xC - coordC + otH * ww / 2.0;
    qreal smV = yC - coordC + otV * hh / 2.0;
    QRectF rectSvg(smH, smV, length, length);
    QSvgRenderer svgr;
    if(comboBoxAim->currentIndex() == 0){
        svgr.load(QString(":images/svg/crosshair red.svg"));
    }
    else if(comboBoxAim->currentIndex() == 1){
        svgr.load(QString(":images/svg/crosshair black.svg"));
    }
    else{
        svgr.load(QString(":images/svg/crosshair black.svg"));
    }
    svgr.render(&painter, rectSvg);
}

Client::~Client(){
    myThread.notRun();
    myThread.quit();
    myThread.wait();
}

void Client::CloseBtnClicked()
{
    close();
}

void Client::reDataWind(dataD str){
    AngleLbl->setText(QString::number(str.angle));
    OtHLbl->setText(QString::number(str.otH));
    OtVLbl->setText(QString::number(str.otV));

    angle = str.angle;
    otH = str.otH;
    otV = str.otV;

    repaint();
}

void Client::changedColorCombo(int){
    repaint();
}

void Client::changedAimCombo(int){
    repaint();
}
void Client::resizeEvent(QResizeEvent *)
{
    //При изменении ширины задать максимальную высоту
    int ww = width();
    int hh = ww * 3 / 4 + 100;
    setMinimumHeight(hh);
}
