

#ifndef WEAPON_H
#define WEAPON_H

#include "items.h"

class Weapon :
	public items
{

public:
	int dmg;
public:	
    Weapon(std::string name ,int type, int dmg) : items(name,type)
	{
		this->dmg = dmg;
    }
    int Attack(){ return dmg; }
};

#endif
