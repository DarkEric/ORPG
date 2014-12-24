TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    hero.cpp \
    critter.cpp \
    monstr.cpp \
    berserk.cpp \
    BUM.cpp \
    troll.cpp \
    COMPOTE.cpp \
    NPC.cpp \
    QNPC.cpp \
    FightWindow.cpp \
    Consol.cpp \
    controller.cpp \
    dragon.cpp \
    Game.cpp \
    Dialogq.cpp \
    CreateHero.cpp \
    Menu.cpp
    quest.cpp
    dragon.cpp \


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    hero.h \
    critter.h \
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
    Menu.h \
    BUM.h \
    COMPOTE.h \
    NPC.h \
    QNPC.h \
    Consol.h \
    CreateHero.h \
    FightWindow.h \
    Weapon.h \
    controller.h \
    dragon.h \
    Game.h \
    ID.h \
<<<<<<< HEAD
    Dialogq.h
=======
    dialog.h \
    Dialogq.h \
    quest.h \
    readdialog.h
>>>>>>> origin/master
    dragon.h

