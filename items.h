#ifndef ITEM_H
#define ITEM_H

#include <string>

class items
{
private:
	std::string name;
    int type;
    int color;
public:

    items(std::string name, int type, int color)
	{
		this->name = name;
		this->type = type;
        this->color = color;
    }
	
    std::string Get_name(){ return name; }
    int Get_type(){ return type; }
    int Get_color(){return color;}

};

#endif

