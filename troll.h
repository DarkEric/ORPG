#ifndef TROLL_H
#define TROLL_H
#include "monstr.h"
class Troll : public Monstr
{
public:
    Troll():Monstr("Troll",ID_TYPE_TROLL,TROLL_START_HP,TROLL_PATTACK,TROLL_PDEFENSE,1,1,TROLL_LEVEL,TROLL_START_ENERGY,TROLL_MDEFENSE){
        this->Set_exp_reward(TROLL_EXPERIENCE);
        for (int i=1;i<=7;i++) {
            this->Set_name_SP(i,"0");
            this->Set_energy_coast(i,0);
        }
        this->Set_name_SP(1,"1");
        this->Set_energy_coast(1,10);
        this->Set_name_SP(2,"1");
        this->Set_energy_coast(1,25);
    }
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
};

#endif // TROLL_H
