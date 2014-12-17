#include "items.h"


class Armor :
	public items
{
private :
	int p_resist;
	int stat;
	std::string type_stat;
    int m_resist;
public:
    Armor(std::string name, int type,int p_resist,int m_resist,std::string type_stat, int stat,int color) : items(name,type,color)
	{
		this->p_resist = p_resist;
		this->stat = stat;
		this->type_stat = type_stat;
        this->m_resist = m_resist;
	}
    int Get_armor(){ return p_resist; }
    std::string Get_type_stat(){ return type_stat; }
    int Get_stat(){ return stat; }
    int Get_m_resist(){return m_resist;}
};

