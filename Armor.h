
#include "items.h"


class Armor :
	public items
{
private :
	int p_resist;
	int stat;
	std::string type_stat;
public:
	Armor(std::string name, std::string type,int p_resist,std::string type_stat , int stat ) : items(name,type)
	{
		this->p_resist = p_resist;
		this->stat = stat;
		this->type_stat = type_stat;
	}
    int Get_armor(){ return p_resist; }
    std::string Get_type_stat(){ return type_stat; }
    int Get_stat(){ return stat; }

};

