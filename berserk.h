#ifndef BERSERK_H
#define BERSERK_H
#include <warrior.h>
#include "Weapon.h"
class Berserk : public Warrior
{
public:
    Berserk(std::string name):Warrior(name,ID_TYPE_BERSERK){
        Set_energy(0);
    }
    Weapon* Get_weapon()const{return THWeap;}
    void Set_weapon(Weapon* THWeap);
    void Unset_weapon(Weapon* THWeap);
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
private:
    Weapon* THWeap;
};

#endif // BERSERK_H
