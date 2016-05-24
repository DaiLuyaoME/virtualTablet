#ifndef CAPTURE_H
#define CAPTURE_H

#include <QObject>
#include <opencv2\opencv.hpp>
#include <iostream>
#include <vector>
using namespace std;
using namespace cv;

class capture : public QObject
{
    Q_OBJECT
public:
    explicit capture(QObject *parent = 0);
    ~capture();

signals:
    void sendPosition(int x,int y);

public slots:
    void beginCapture();
private:
    bool keepCapturing;
};

#endif // CAPTURE_H
