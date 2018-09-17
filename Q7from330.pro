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
    test_data.cpp \
    mydialog.cpp \
    win_canshu.cpp \
    customtabstyle.cpp \
    wg_canshu.cpp \
    dg_login.cpp \
    win_kuaisu.cpp \
    my_label.cpp \
    wg_pic.cpp \
    dg_progress.cpp \
    wg_ks_table.cpp \
    lb_check.cpp

HEADERS += \
        mainwindow.h \
    widget_progress.h \
    dir_bt.h \
    data.h \
    test_data.h \
    mydialog.h \
    win_canshu.h \
    customtabstyle.h \
    wg_canshu.h \
    dg_login.h \
    win_kuaisu.h \
    my_label.h \
    wg_pic.h \
    dg_progress.h \
    wg_ks_table.h \
    lb_check.h

FORMS += \
        mainwindow.ui \
    widget_progress.ui \
    data.ui \
    test_data.ui \
    mydialog.ui \
    win_canshu.ui \
    wg_canshu.ui \
    dg_login.ui \
    win_kuaisu.ui \
    my_pic.ui \
    wg_pic.ui \
    dg_progress.ui \
    wg_ks_table.ui

RESOURCES += \
    icon.qrc
