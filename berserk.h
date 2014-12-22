#ifndef BERSERK_H
#define BERSERK_H
#include <hero.h>
#include "Weapon.h"
class Berserk : public Hero
{
public:
    Berserk(std::string name):Hero(name,ID_TYPE_BERSERK,WARRIOR_START_HP,WARRIOR_ATTACK_1,WARRIOR_DEFENSE_1,
                                   HERO_START_POS_X,HERO_START_POS_Y,WARRIOR_ENERGY_MAX,WARRIOR_DEFENSE_1,
                                   WARRIOR_START_STR,BERSERK_START_ID_ARMOR,BERSERK_START_ID_WEAPON){
        Set_energy(0);
        this->Set_name_SP(1,"Неистовый удар");
        this->Set_name_SP(2,"Жажда крови");
      //  this->Set_name_SP(3,"скил3\0");
        this->Set_energy_coast(1,50);
        this->Set_energy_coast(2,100);
    }
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
    void Start_Battle(){
        this->Set_energy(0);
        this->Set_HP(this->Get_MAX_HP());
    }

};

#endif // BERSERK_H
