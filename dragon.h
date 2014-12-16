#ifndef DRAGON_H
#define DRAGON_H
#include "monstr.h"
class Dragon : public Monstr
{
public:
    Dragon():Monstr("Dragon",ID_TYPE_DRAGON,DRAGON_START_HP,DRAGON_PATTACK,DRAGON_PDEFENSE,1,1,DRAGON_LEVEL,DRAGON_START_ENERGY,DRAGON_MDEFENSE){
        this->Set_exp_reward(DRAGON_EXPERIENCE);
        for (int i=1;i<=7;i++) {
            this->Set_name_SP(i,"0");
            this->Set_energy_coast(i,0);
        }
        this->Set_name_SP(1,"1");
        this->Set_energy_coast(1,5);
        this->Set_name_SP(2,"1");
        this->Set_energy_coast(2,10);
        this->Set_name_SP(3,"1");
        this->Set_energy_coast(3,15);
    }
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
    void SP3(Critter *whom);
};

#endif // DRAGON_H
