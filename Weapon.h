#ifndef WEAPON_H
#define WEAPON_H

#include "items.h"



class Weapon :
	public items
{
public:
	int dmg;
public:
    Weapon(){}
    Weapon(std::string name, int type, int dmg,int color) : items(name,type,color)
	{
		this->dmg = dmg;
	}
    int Attack(){ return dmg; }
    void Set_dmg(int n){this->dmg=n;}
};

#endif
