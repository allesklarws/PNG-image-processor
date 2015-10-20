#-------------------------------------------------
#
# Project created by QtCreator 2014-01-31T10:43:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ImgPro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imgProcess_funcs.cpp \
    layout.cpp \
    parameterdlg.cpp \
    initialize.cpp \
    color_win.cpp \
    parameterdlg2.cpp \
    qcustomplot.cpp \
    pattern_make.cpp \
	windrift.cpp

HEADERS  += mainwindow.h \
    parameterdlg.h \
    color_win.h \
    parameterdlg2.h \
    qcustomplot.h \
    pattern_make.h \
	windrift.h

FORMS    +=

OTHER_FILES +=
