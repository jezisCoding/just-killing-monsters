#TEMPLATE = app
#CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt
#QMAKE_CXXFLAGS += -std=c++14

#-------------------------------------------------
#
# Project created by QtCreator 2017-02-02T20:54:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = just-killing-monsters
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    environment.cpp \
    creature.cpp \
    hero.cpp \
    potion.cpp \
    monster.cpp \
    gamefield.cpp \
    gameboard.cpp \
    gameengine.cpp \
    entityfactory.cpp \
    monsterfearsome.cpp \
    fieldentity.cpp \
    fieldactor.cpp \
    mainwindow.cpp \
    staticoutputstream.cpp \
    myxmlparser.cpp

HEADERS += \
    environment.h \
    creature.h \
    hero.h \
    position.h \
    potion.h \
    monster.h \
    gamefield.h \
    gameboard.h \
    gameengine.h \
    entityfactory.h \
    myexceptions.h \
    monsterfearsome.h \
    my2dboardvector.h \
    fieldentity.h \
    fieldactor.h \
    mainwindow.h \
    staticoutputstream.h \
    myxmlparser.h

FORMS += \
    mainwindow.ui

DISTFILES +=
