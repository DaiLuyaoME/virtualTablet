#include "capture.h"

capture::capture(QObject *parent) : QObject(parent)
{
    keepCapturing=true;
}

capture::~capture()
{

}

void capture::beginCapture()
{
    if(!keepCapturing)
        return;

    VideoCapture capture(1);
    Mat frame;
    float radius;
    Point2f center;
    vector<vector<Point>> contours;
    Mat temp;
    Mat thresh;

    int fps=15;

    int iLowH = 0;
    int iHighH = 10;

    int iLowS = 50;
    int iHighS = 255;

    int iLowV = 50;
    int iHighV = 255;
    namedWindow("camera_one");
    moveWindow("camera_one",300,300);

    createTrackbar("LowH", "camera_one", &iLowH, 179); //Hue (0 - 179)
    createTrackbar("HighH", "camera_one", &iHighH, 179);

    createTrackbar("LowS", "camera_one", &iLowS, 255); //Saturation (0 - 255)
    createTrackbar("HighS", "camera_one", &iHighS, 255);

    createTrackbar("LowV", "camera_one", &iLowV, 255);//Value (0 - 255)
    createTrackbar("HighV", "camera_one", &iHighV, 255);

    while(keepCapturing)
    {
        capture >> frame;
        cvtColor(frame, temp, COLOR_BGR2HSV);
        inRange(temp, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV), thresh);
        findContours(thresh, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
        vector<vector<Point>>::iterator itc = contours.begin();
        while (itc != contours.end())
        {
            if (itc->size() > 250||itc->size() < 50)
                itc = contours.erase(itc);
            else
                ++itc;
        }

        if(contours.size()==1)
        {
            Mat temp = Mat(contours[0]);
            minEnclosingCircle(temp, center, radius);
            circle(frame, Point(center), static_cast<int>(radius), Scalar(0), 2);
            emit sendPosition(int(center.x),int(center.y));
        }

        for (int i = 0; i < contours.size(); ++i)
        {
            Mat temp = Mat(contours[i]);
            minEnclosingCircle(temp, center, radius);
            circle(frame, Point(center), static_cast<int>(radius), Scalar(0), 2);
        }

        imshow("camera_one",frame);

        if(waitKey(1000 / fps)>0)
            break;

    }
    return;

}

