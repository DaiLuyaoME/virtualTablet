#-------------------------------------------------
#
# Project created by QtCreator 2015-09-21T02:20:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vitualTablet
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    capture.cpp

HEADERS  += dialog.h \
    capture.h

FORMS    += dialog.ui
win32:CONFIG(release, debug|release):  LIBS += -LD:/OpenCV/opencv/build/x86/vc12/lib/ -lopencv_core2410 -lopencv_highgui2410 -lopencv_calib3d2410 -lopencv_contrib2410 -lopencv_features2d2410 -lopencv_flann2410 -lopencv_gpu2410 -lopencv_imgproc2410 -lopencv_legacy2410 -lopencv_ml2410.lib -lopencv_nonfree2410 -lopencv_objdetect2410 -lopencv_photo2410 -lopencv_stitching2410 -lopencv_ts2410 -lopencv_video2410 -lopencv_videostab2410
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/OpenCV/opencv/build/x86/vc12/lib/ -lopencv_core2410d -lopencv_highgui2410d -lopencv_flann2410d -lopencv_gpu2410d -lopencv_imgproc2410d -lopencv_legacy2410d -lopencv_ml2410d -lopencv_nonfree2410d -lopencv_objdetect2410d -lopencv_photo2410d -lopencv_stitching2410d -lopencv_ts2410d -lopencv_video2410d -lopencv_videostab2410d

INCLUDEPATH += D:/OpenCV/opencv/build/include
DEPENDPATH += D:/OpenCV/opencv/build/include
