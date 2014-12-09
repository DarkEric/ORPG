#pragma once
#include "Armor.h"



class Leather :
	public Armor
{
public:
	Leather();
	Leather(std::string name, std::string type, int p_resist, std::string type_stat, int stat) : Armor(name, type, p_resist, type_stat, stat)
	{	
	}
	~Leather();
};

