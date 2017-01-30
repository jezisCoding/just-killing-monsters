TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++14

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
    pointableobject.cpp \
    boardactor.cpp \
    boardentity.cpp

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
    pointableobject.h \
    fieldentity.h \
    fieldactor.h
