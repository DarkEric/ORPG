#ifndef BERSERK_H
#define BERSERK_H
#include <warrior.h>
#include "DblHWeapon.h"
class Berserk : public Warrior
{
public:
    Berserk(std::string name,int type,char sumbol):Warrior(name,type,sumbol){}
    DblWeapon* Get_weapon()const{return THWeap;}
    void Set_weapon(DblWeapon* THWeap){this->THWeap=THWeap;}
    void Attack(Critter *whom);
private:
    DblWeapon* THWeap;
};

#endif // BERSERK_H
