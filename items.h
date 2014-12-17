#ifndef ITEM_H
#define ITEM_H

#include <string>

class items
{
private:
    char name[30];
    int type;
    int color;
public:

    items(std::string name, int type, int color)
	{
        for(int i=0;i<30;i++)this->name[i]='\0';
        name.copy(this->name,name.length());
		this->type = type;
        this->color = color;
    }
	
    std::string Get_name(){ return name; }
    int Get_type(){ return type; }
    int Get_color(){return color;}
    void Set_name(std::string name){name.copy(this->name,name.length());}

};

#endif

