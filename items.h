#pragma once

#ifndef ITEM_H
#define ITEM_H

#include <string>

class items
{
private:
	std::string name;
	int color;
	int type;

public:
	items();
	items(std::string name, int type ,int color)
	{
		this->name = color;
		this->name = name;
		this->type = type;
	}
	
	std::string Get_name(){ return name; };
	int Get_color(){ return color; };
	int Get_type(){ return type; };
	~items();
};

#endif

