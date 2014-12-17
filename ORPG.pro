TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    hero.cpp \
    critter.cpp \
    monstr.cpp \
    warrior.cpp \
    berserk.cpp \
    BUM.cpp \
    troll.cpp \
    COMPOTE.cpp \
    NPC.cpp \
    QNPC.cpp \
    FightWindow.cpp \
    CheckMob.cpp \
    Field.cpp \
    CreateCritter.cpp \
    Consol.cpp \
    dragon.cpp \
    Dungeon.cpp


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hero.h \
    critter.h \
    warrior.h \
    stats.h \
    monstr.h \
    berserk.h \
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
    Consol.h \
    CreateHero.h \
    FightWindow.h \
    Weapon.h \
    CheckMob.h \
    CreateCritter.h \
    Dungeon.h \
    dragon.h


