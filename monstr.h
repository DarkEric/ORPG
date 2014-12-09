#ifndef MONSTR_H
#define MONSTR_H
#include "critter.h"
class Monstr:public Critter
{
public:
    Monstr(int MAX_HP,int dmg,int p_resist,int x,int y):Critter(MAX_HP,dmg,p_resist,x,y)
    {
        this->heroin=0;
        this->agrrange=0;
    }

    void Set_agrrange(int n);
    int Get_agrrange();

private:
    int heroin,
        agrrange;
};

#endif // MONSTR_H
