#pragma once
#include "items.h"


class Armor :
	public items
{
private :
	int p_resist;
	int stat;
public:
	Armor();
	Armor(std::string name, int type, int p_resist,int stat, int color) : items(name, type,color)
	{
		this->p_resist = p_resist;
		this->stat = stat;
	}
	int Get_armor(){ return p_resist; };
	int Get_stat(){ return stat; };
	~Armor();
};

