#-------------------------------------------------
#
# Project created by QtCreator 2015-01-01T19:50:30
#
#-------------------------------------------------

QMAKE_CXXFLAGS +=-std=c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blum_generator.cpp \
    Fibonacci.cpp

HEADERS  += mainwindow.h \
    blum_blum.h \
    Fibonacci.h

FORMS    += mainwindow.ui
