#pragma once
#ifndef DblHWEAPON_H
#define DblHWEAPON_H

#include "Weapon.h"


class DblWeapon :

public Weapon
{
public:
	DblWeapon();
	DblWeapon(std::string name,std::string type, int dmg) : Weapon(name, type, dmg){};
	~DblWeapon();
};

#endif

