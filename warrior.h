#ifndef WARRIOR_H
#define WARRIOR_H
#include <hero.h>
#include <stats.h>
#include "Plate.h"
class Warrior : public Hero
{
public:
    Warrior(std::string name,int type,char sumbol):Hero(name,type,sumbol,WARRIOR_START_HP,WARRIOR_ATTACK_1,WARRIOR_DEFENSE_1,HERO_START_LOC_X,HERO_START_LOC_Y){
        this->str=WARRIOR_START_STR;
    }
    void Set_str(int n){str=n;}
    int Get_str(){return str;}
    Plate* Get_armor()const{return Armor;}
    void Set_armor(Plate* Armor);
    void Unset_armor(Plate* Armor);
private:
    int str;
    Plate* Armor;
};

#endif // WARRIOR_H
