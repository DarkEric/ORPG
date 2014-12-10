#ifndef BERSERK_H
#define BERSERK_H
#include <warrior.h>
#include "DblHWeapon.h"
class Berserk : public Warrior
{
public:
    Berserk(std::string name):Warrior(name,ID_TYPE_BERSERK){}
    DblWeapon* Get_weapon()const{return THWeap;}
    void Set_weapon(DblWeapon* THWeap);
    void Unset_weapon(DblWeapon* THWeap);
    void Attack(Critter *whom);
private:
    DblWeapon* THWeap;
};

#endif // BERSERK_H
