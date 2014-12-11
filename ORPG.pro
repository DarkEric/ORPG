TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    hero.cpp \
    critter.cpp \
    monstr.cpp \
    warriormob.cpp \
    warrior.cpp \
    berserk.cpp \
    BUM.cpp \
    troll.cpp \
    COMPOTE.cpp \
    NPC.cpp \
    QNPC.cpp \
    FightWindow.cpp

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
    troll.h \
    DblHWeapon.h \
    items.h \
    Leather.h \
    Plate.h \
    Robe.h \
    Weapon.h \
    Field.h \
    Menu.h \
    BUM.h \
    COMPOTE.h \
    NPC.h \
    QNPC.h \
    FightWindow.h

