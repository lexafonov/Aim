#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QDialog>
#include "ui_client.h"
#include "threadout.h"
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
    void resizeEvent(QResizeEvent *);

public slots:
    void CloseBtnClicked();
    void reDataWind(dataD);
private:
    qreal angle;
    qreal otH;
    qreal otV;

    qreal widt = 800;

    threadOut myThread;

    QStringList lstColor;
    QStringList lstAim;
    QSvgWidget svg;
};

#endif // UDPCLIENT_H
