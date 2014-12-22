#ifndef HERO_H
#define HERO_H
#include "critter.h"
#include "Weapon.h"
#include "Armor.h"
#include "monstr.h"
class Hero:public Critter
{
public:
    Hero(){}
    Hero(std::string name,int type,int MAX_HP, int dmg, int p_resist, int x, int y,int MAX_energy,int m_resist,int stat, int ID_Armor,int ID_Weapon):Critter(name,type,MAX_HP,dmg,p_resist,x,y,1,MAX_energy,m_resist)
    {
        this->ID_Armor=ID_Armor;
        this->ID_Weapon=ID_Weapon;
        this->stat=stat;
        this->EXP=0;
//        =======================
        this->EXP_to_lvl=100;
//        =================
    }
    void SearchMob(Monstr *mob , int n, char Field[300][300]);
    void Set_EXP(int n);
    int Get_EXP()const;
    void Add_EXP(int n);
    void Lose_EXP(int n);
    void Set_stat(int n){stat=n;}
    int Get_stat()const{return stat;}
    virtual int Get_armor()const{return ID_Armor;}
    virtual void Set_armor(int Arm);
    virtual void Unset_armor(int Arm);
    virtual int Get_weapon()const{return ID_Weapon;}
    virtual void Set_weapon(int Weap);
    virtual void Unset_weapon(int Weap);
    virtual void Start_Battle(){
        this->Set_energy(this->Get_MAX_energy());
        this->Set_HP(this->Get_MAX_HP());
    }

private:
    int EXP;
//    =======================================
    int EXP_to_lvl;
//    =================================
    int ID_Armor;
    int ID_Weapon;
    int stat;
};

#endif // HERO_H
