#-------------------------------------------------
#
# Project created by QtCreator 2018-09-10T09:21:40
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Q7from330
TEMPLATE = app
RC_ICONS = ./home/Q7Reader.ico
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    widget_progress.cpp \
    dir_bt.cpp \
    data.cpp \
    test_data.cpp

HEADERS += \
        mainwindow.h \
    widget_progress.h \
    dir_bt.h \
    data.h \
    test_data.h

FORMS += \
        mainwindow.ui \
    widget_progress.ui \
    data.ui \
    test_data.ui

RESOURCES += \
    icon.qrc