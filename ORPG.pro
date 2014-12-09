TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hero.cpp \
    critter.cpp \
    monstr.cpp \
    warriormob.cpp \
    Armor.cpp \
    DblHWeapon.cpp \
    items.cpp \
    Leather.cpp \
    Plate.cpp \
    Robe.cpp \
    Weapon.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hero.h \
    critter.h \
    warrior.h \
    stats.h \
    monstr.h \
    berserk.h \
    warriormob.h \
    Armor.h \
    DblHWeapon.h \
    items.h \
    Leather.h \
    Plate.h \
    Robe.h \
    Weapon.h

