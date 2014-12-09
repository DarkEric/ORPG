TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hero.cpp \
    warrior.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hero.h \
    warrior.h

