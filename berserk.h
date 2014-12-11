#ifndef BERSERK_H
#define BERSERK_H
#include <hero.h>
#include "DblHWeapon.h"
class Berserk : public Warrior
{
public:
    Berserk(std::string name):Hero(name,ID_TYPE_BERSERK,WARRIOR_START_HP,WARRIOR_ATTACK_1,WARRIOR_DEFENSE_1,HERO_START_LOC_X,HERO_START_LOC_Y,WARRIOR_START_STR){}

    void Attack(Critter *whom);
private:

};

#endif // BERSERK_H
