#ifndef HERO_H
#define HERO_H
#include "critter.h"
#include "items.h"
class Hero:public Critter
{
public:
    Hero(std::string name,int type,int MAX_HP, int dmg, int p_resist, int x, int y,int stat):Critter(name,type,MAX_HP,dmg,p_resist,x,y,1)
    {
        this->EXP=0;
        this->stat=stat;
    }

    void Set_EXP(int n);
    int Get_EXP()const;
    void Add_EXP(int n);
    void Lose_EXP(int n);

    items* Get_Fweapon()const{return FWearpon;}
    void Set_Fweapon(items* FWearpon);
    void Unset_Fweapon(items* FWearpon);

    items* Get_Sweapon()const{return SWearpon;}
    void Set_Sweapon(items* SWearpon);
    void Unset_Sweapon(items* SWearpon);

    void Set_str(int n){stat=n;}
    int Get_str(){return stat;}

    items* Get_armor()const{return Armor;}
    void Set_armor(items* Armor);
    void Unset_armor(items* Armor);
private:
    int EXP;
    int stat;
    items* Armor;
    items* FWearpon;
    items* SWearpon;
};

#endif // HERO_H
