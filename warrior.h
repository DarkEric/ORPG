#ifndef WARRIOR_H
#define WARRIOR_H
#include <hero.h>
#include <stats.h>
#include "Plate.h"
class Warrior : public Hero
{
public:
    Warrior(std::string name,int type):Hero(name,type,WARRIOR_START_HP,WARRIOR_ATTACK_1,WARRIOR_DEFENSE_1,HERO_START_LOC_X,HERO_START_LOC_Y){
        this->str=WARRIOR_START_STR;
    }

private:

};

#endif // WARRIOR_H
