#-------------------------------------------------
#
# Project created by QtCreator 2014-01-02T23:21:24
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StreetFighter
TEMPLATE = app

LIBS += -lSOIL

SOURCES += main.cpp\
        mainwindow.cpp \
    globject.cpp \
    player.cpp \
    opponent.cpp \
    road.cpp \
    tree.cpp \
    glmainwindow.cpp \
    opponentqueue.cpp

HEADERS  += mainwindow.h \
    globject.h \
    player.h \
    opponent.h \
    road.h \
    tree.h \
    glmainwindow.h \
    opponentqueue.h

FORMS    += mainwindow.ui
