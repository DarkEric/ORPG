#include "Armor.h"


class Plate :
	public Armor
{
public:
    Plate(std::string name, int type, int p_resist, std::string type_stat, int stat) : Armor(name, type, p_resist, type_stat, stat)
	{
	}

};

