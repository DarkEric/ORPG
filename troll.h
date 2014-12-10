#ifndef TROLL_H
#define TROLL_H
#include "monstr.h"
class Troll : public Warriormob
{
public:
    Troll(std::string name,int type):Warriormob(name,type,MOB_START_HP,MOB_PATTACK,MOB_PDEFENSE,x,y,Level){
        this->Set_exp_reward(TROLL_EXPERIENCE);
    }
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
};

#endif // TROLL_H
