#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QUdpSocket>
#include "server.h"
#include "ui_client.h"
#include "threadout.h"
#include <QtWidgets>
#include <QtSvg>

class Client : public QDialog, public Ui::Client
{
    Q_OBJECT
public:
    Client(QWidget *parent = nullptr);
    ~Client();
    void changedColorCombo(int);
    void changedAimCombo(int);
protected:
    /* Определяем виртуальный метод родительского класса
     * для отрисовки содержимого виджета
     * */
    void paintEvent(QPaintEvent *event);
public slots:
    void CloseBtnClicked();
    //void dataReceived();
    void reDataWind(dataD);
private:
    qreal angle;
    qreal otH;
    qreal otV;

    QUdpSocket *udpSocket;
    threadOut* myThread;

    QStringList lstColor;
    QStringList lstAim;
    QSvgWidget svg;
};

#endif // UDPCLIENT_H
