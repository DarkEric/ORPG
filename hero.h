#ifndef HERO_H
#define HERO_H
#include "critter.h"
class Hero:public Critter
{
public:
    Hero(int MAX_HP,int dmg,int p_resist,int x,int y,int EXP=0,int Level=1);


    void Set_EXP(int n);
    int Get_EXP()const;
    void Add_EXP(int n);
    void Lose_EXP(int n);


    void Set_Level(int n);
    int Get_Level()const;
    void LevelUp();

    virtual void Move(int h);

private:
    int EXP,
        Level;
};

#endif // HERO_H
