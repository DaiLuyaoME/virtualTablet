#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPaintEvent>
#include <QThread>
#include <QPainter>
#include <QVector>
#include <QPoint>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    QThread workerThread;

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void paintEvent(QPaintEvent*event);
public slots:
    void changePosition(int x,int y);

private:
    Ui::Dialog *ui;
    int x;
    int y;
//    int previous_x;
//    int previous_y;
    QVector<QPoint> pointPairs;
signals:
    void begin();
private slots:
    void on_beginCapture_clicked();
};

#endif // DIALOG_H
