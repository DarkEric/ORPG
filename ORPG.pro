TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hero.cpp \
    warrior.cpp \
    critter.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hero.h \
    warrior.h \
    critter.h

