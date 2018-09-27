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
    data.cpp \
    mydialog.cpp \
    win_canshu.cpp \
    customtabstyle.cpp \
    wg_canshu.cpp \
    dg_login.cpp \
    win_kuaisu.cpp \
    wg_pic.cpp \
    dg_progress.cpp \
    wg_ks_table.cpp \
    l_pic.cpp \
    dg_input.cpp \
    wg_kuaisu.cpp \
    wg_showpic.cpp \
    wg_weihu.cpp \
    wg_locationpic.cpp \
    dg_piclocation.cpp \
    dg_addproject.cpp \
    dg_addpro.cpp \
    dg_check_yq.cpp \
    dg_check_td.cpp \
    dg_setting_long.cpp \
    dg_setting_add.cpp \
    dg_outsetting.cpp \
    mainbutton.cpp \
    vicebutton.cpp \
    dg_seltime.cpp \
    wg_searchline.cpp \
    wg_search.cpp

HEADERS += \
        mainwindow.h \
    widget_progress.h \
    data.h \
    mydialog.h \
    win_canshu.h \
    customtabstyle.h \
    wg_canshu.h \
    dg_login.h \
    win_kuaisu.h \
    wg_pic.h \
    dg_progress.h \
    wg_ks_table.h \
    l_pic.h \
    dg_input.h \
    wg_kuaisu.h \
    wg_showpic.h \
    wg_weihu.h \
    wg_locationpic.h \
    dg_piclocation.h \
    dg_addproject.h \
    dg_addpro.h \
    dg_check_yq.h \
    dg_check_td.h \
    dg_setting_long.h \
    dg_setting_add.h \
    dg_outsetting.h \
    mainbutton.h \
    vicebutton.h \
    dg_seltime.h \
    wg_searchline.h \
    wg_search.h

FORMS += \
        mainwindow.ui \
    widget_progress.ui \
    data.ui \
    mydialog.ui \
    win_canshu.ui \
    wg_canshu.ui \
    dg_login.ui \
    win_kuaisu.ui \
    my_pic.ui \
    wg_pic.ui \
    dg_progress.ui \
    wg_ks_table.ui \
    dg_input.ui \
    wg_kuaisu.ui \
    wg_showpic.ui \
    wg_weihu.ui \
    wg_locationpic.ui \
    dg_piclocation.ui \
    dg_addproject.ui \
    dg_addpro.ui \
    dg_check_yq.ui \
    dg_check_td.ui \
    dg_setting_long.ui \
    dg_setting_add.ui \
    dg_outsetting.ui \
    dg_seltime.ui \
    wg_search.ui

RESOURCES += \
    icon.qrc
