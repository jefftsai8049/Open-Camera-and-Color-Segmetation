#-------------------------------------------------
#
# Project created by QtCreator 2015-10-21T12:13:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = camera_open
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    camera.h

FORMS    += mainwindow.ui


INCLUDEPATH += C:\\opencv300_x64_vc2013\\include \
                C:\\opencv300_x64_vc2013\\include\\opencv \
                C:\\opencv300_x64_vc2013\\include\\opencv2 \

##debug libs

LIBS +=  C:\\opencv300_x64_vc2013\\lib\\opencv_world300.lib \
                C:\\opencv300_x64_vc2013\\lib\\opencv_ts300.lib \
#release libs
                C:\\opencv300_x64_vc2013\\lib\\opencv_world300d.lib \
                C:\\opencv300_x64_vc2013\\lib\\opencv_ts300d.lib
