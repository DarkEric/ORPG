TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hero.cpp \
    critter.cpp \
    warrior.cpp \
    berserk.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hero.h \
    critter.h \
    warrior.h \
    stats.h \
    berserk.h

