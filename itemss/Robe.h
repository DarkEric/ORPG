#pragma once
#include "Armor.h"
class Robe :
	public Armor
{
public:
	Robe();
	Robe(std::string name, std::string type, int p_resist, std::string type_stat, int stat) : Armor(name, type, p_resist, type_stat, stat)
	{
	}
	~Robe();
};

