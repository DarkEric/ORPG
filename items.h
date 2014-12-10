

#ifndef ITEM_H
#define ITEM_H

#include <string>

class items
{
private:
	std::string name;
    int type;

public:

    items(std::string name, int type)
	{
		this->name = name;
		this->type = type;
	}
	
    std::string Get_name(){ return name; }
    int Get_type(){ return type; }

};

#endif

