TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    ../../ORPG/Armor.h \
    ../../ORPG/items.h \
    ../../ORPG/Weapon.h

