#ifndef WARRIOR_H
#define WARRIOR_H
#include <hero.h>
#include <stats.h>
class Warrior : public Hero
{
public:
    Warrior():Hero(WARRIOR_START_HP,WARRIOR_ATTACK_1,WARRIOR_DEFENSE_1,HERO_START_LOC_X,HERO_START_LOC_Y){
        this->str=WARRIOR_START_STR;
    }

private:
    int str;
//    Item* Armor;
};

#endif // WARRIOR_H
