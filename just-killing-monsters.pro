TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    entity.cpp \
    interactiveentity.cpp \
    environment.cpp \
    creature.cpp \
    hero.cpp \
    potion.cpp \
    monster.cpp \
    gamefield.cpp \
    gameboard.cpp \
    gameengine.cpp

HEADERS += \
    entity.h \
    interactiveentity.h \
    environment.h \
    creature.h \
    hero.h \
    position.h \
    potion.h \
    monster.h \
    gamefield.h \
    gameboard.h \
    gameengine.h
