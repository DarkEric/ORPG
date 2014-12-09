
#ifndef DblHWEAPON_H
#define DblHWEAPON_H

#include "Weapon.h"


class DblWeapon : public Weapon
{
public:
    DblWeapon(std::string name,std::string type, int dmg) : Weapon(name, type, dmg){}
};

#endif

