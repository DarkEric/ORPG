

#ifndef ITEM_H
#define ITEM_H

#include <string>

class items
{
private:
	std::string name;
	std::string type;

public:

	items(std::string name, std::string type)
	{
		this->name = name;
		this->type = type;
	}
	
    std::string Get_name(){ return name; }
    std::string Get_type(){ return type; }

};

#endif

