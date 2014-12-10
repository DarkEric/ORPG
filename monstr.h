#ifndef MONSTR_H
#define MONSTR_H
#include "critter.h"
class Monstr:public Critter
{
public:
    Monstr(std::string name,int type,int MAX_HP,int dmg,int p_resist,int x,int y,int Level):Critter(name,type,MAX_HP,dmg,p_resist,x,y,Level)
    {
        this->heroin=0;
        this->agrrange=0;
    }

    void Set_agrrange(int n);
    int Get_agrrange();
    void Change_heroin();

    int Get_heroin();
private:
    int heroin,
        agrrange;
};

#endif // MONSTR_H
