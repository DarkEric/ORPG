#ifndef HERO_H
#define HERO_H
#include "critter.h"
class Hero:public Critter
{
public:
    Hero(std::string name,int type,int MAX_HP, int dmg, int p_resist, int x, int y):Critter(name,type,MAX_HP,dmg,p_resist,x,y,1)
    {
        this->EXP=0;
    }

    void Set_EXP(int n);
    int Get_EXP()const;
    void Add_EXP(int n);
    void Lose_EXP(int n);


private:
    int EXP;
};

#endif // HERO_H