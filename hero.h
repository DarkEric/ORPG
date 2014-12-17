#ifndef HERO_H
#define HERO_H
#include "critter.h"
#include "Weapon.h"
#include "Armor.h"
#include "monstr.h"
class Hero:public Critter
{
public:
    Hero(std::string name,int type,int MAX_HP, int dmg, int p_resist, int x, int y,int MAX_energy,int m_resist):Critter(name,type,MAX_HP,dmg,p_resist,x,y,1,MAX_energy,m_resist)
    {
        this->EXP=0;
    }
    void SearchMob(Monstr **mob , int n, char** Field);
    void Set_EXP(int n);
    int Get_EXP()const;
    void Add_EXP(int n);
    void Lose_EXP(int n);
    virtual void Set_stat(int n){}
    virtual int Get_stat(){}
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
