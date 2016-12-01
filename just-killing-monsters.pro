TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    entity.cpp \
    interactiveentity.cpp \
    environment.cpp

HEADERS += \
    entity.h \
    interactiveentity.h \
    environment.h
