#pragma once
#ifndef DblHWEAPON_H
#define DblHWEAPON_H

#include "Onehand_Weapon.h"


class Twohand_Weapon :

 public Onehand_Weapon
{
public:
	Twohand_Weapon();
	Twohand_Weapon(std::string name, int type, int dmg, int color) : Onehand_Weapon(name, type, dmg, color){};
	~Twohand_Weapon();
};

#endif

