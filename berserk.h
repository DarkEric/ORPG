#ifndef BERSERK_H
#define BERSERK_H
#include <warrior.h>
#include "Weapon.h"
class Berserk : public Warrior
{
public:
    Berserk(std::string name):Warrior(name,ID_TYPE_BERSERK){}
    Weapon* Get_weapon()const{return THWeap;}
    void Set_weapon(Weapon* THWeap);
    void Unset_weapon(Weapon* THWeap);
    void Attack(Critter *whom);
private:
    Weapon* THWeap;
};

#endif // BERSERK_H
