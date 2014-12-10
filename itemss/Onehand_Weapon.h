#pragma once

#ifndef WEAPON_H
#define WEAPON_H

#include "items.h"

class Onehand_Weapon :
	public items
{
public:
	int dmg;
public:	
	Onehand_Weapon();
	Onehand_Weapon(std::string name, int type, int dmg, int color) : items(name, type, color)
	{
		this->dmg = dmg;
	}
	int Attack(){ return dmg; };
	~Onehand_Weapon();
};

#endif