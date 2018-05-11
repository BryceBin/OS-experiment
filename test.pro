#-------------------------------------------------
#
# Project created by QtCreator 2018-04-14T12:07:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pcb.cpp \
    thread.cpp \
    memory_block.cpp

HEADERS  += mainwindow.h \
    pcb.h \
    thread.h \
    memory_block.h

FORMS    += mainwindow.ui
