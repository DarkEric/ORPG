#ifndef HERO_H
#define HERO_H
#include "critter.h"
#include "Weapon.h"
#include "Armor.h"
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
    virtual void Set_stat(int n){ }
    virtual int Get_stat(){ }
    virtual Armor* Get_armor()const{ }
    virtual void Set_armor(Armor* Arm){}
    virtual void Unset_armor(Armor* Arm){}
    virtual Weapon* Get_weapon()const{}
    virtual void Set_weapon(Weapon* THWeap){}
    virtual void Unset_weapon(Weapon* THWeap){}
private:
    int EXP;
};

#endif // HERO_H
