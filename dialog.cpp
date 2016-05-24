#include "dialog.h"
#include "ui_dialog.h"
#include "capture.h"
#include <QPolygon>
#include <QPoint>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    x=y=0;
//    previous_x=previous_y=0;
    pointPairs.append(QPoint(0,0));
    capture *mycapture=new capture;
    mycapture->moveToThread(&workerThread);
    connect(this,SIGNAL(begin()),mycapture,SLOT(beginCapture()));
    connect(mycapture,SIGNAL(sendPosition(int,int)),this,SLOT(changePosition(int,int)));
    workerThread.start();
}

Dialog::~Dialog()
{
    delete ui;
    workerThread.quit();
    workerThread.wait();
}

void Dialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPolyline(QPolygon(pointPairs));
//    previous_x=x;
//    previous_y=y;


}

void Dialog::changePosition(int x, int y)
{
//    this->x=x;
//    this->y=y;
    pointPairs.append(QPoint(x,y));
    update();
}

void Dialog::on_beginCapture_clicked()
{
    emit begin();
}
