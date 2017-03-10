#-------------------------------------------------
#
# Project created by QtCreator 2017-03-07T18:40:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = just-killing-monsters
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    creature.cpp \
    entityfactory.cpp \
    environment.cpp \
    fieldactor.cpp \
    fieldentity.cpp \
    gameboard.cpp \
    gameengine.cpp \
    gamefield.cpp \
    hero.cpp \
    monster.cpp \
    monsterfearsome.cpp \
    potion.cpp \
    xmlparser.cpp \
    sos.cpp

HEADERS  += mainwindow.h \
    creature.h \
    entityfactory.h \
    environment.h \
    fieldactor.h \
    fieldentity.h \
    gameboard.h \
    gameengine.h \
    gamefield.h \
    hero.h \
    monster.h \
    monsterfearsome.h \
    my2dboardvector.h \
    myexceptions.h \
    myqmap.h \
    position.h \
    potion.h \
    xmlparser.h \
    sos.h

FORMS    += mainwindow.ui

win32 {
    INCLUDEPATH += C:\Users\eag\Documents\GitHub\boost_1_62_0\
    #LIBS += "-LC:/dev/Boost/lib/" \    --COPY PASTED
    #    "-Llibboost_filesystem-mgw53-mt-d-1_61.a",
    #    "-Llibboost_system-mgw53-mt-d-1_61.a",
    #    "-Llibboost_serialization-mgw53-mt-d-1_61.a" #-LLIBS
}
