#-------------------------------------------------
#
# Project created by QtCreator 2015-01-10T19:04:17
#
#-------------------------------------------------
QMAKE_CXXFLAGS +=-std=c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui_lista
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    blum_generator.cpp \
    Fibonacci.cpp \
    testbinarny.cpp \
    RandL.cpp \
    test_pi.cpp

HEADERS  += mainwindow.h \
    blum_blum.h \
    Fibonacci.h \
    testbinarny.h \
    ../../../../projekt moodelowanie/ProjektModelowanie/Interfejsy_&_RandL/test_pi.h \
    ../../../../projekt moodelowanie/ProjektModelowanie/Interfejsy_&_RandL/RandL.h \
    RandL.h \
    test_pi.h \
    Test.h \
    Generator.h \
    test_pimaciek.h

FORMS    += mainwindow.ui
