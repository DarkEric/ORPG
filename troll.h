#ifndef TROLL_H
#define TROLL_H
#include "monstr.h"
class Troll : public Monstr
{
public:
    Troll():Monstr("Troll",ID_TYPE_TROLL,TROLL_START_HP,TROLL_PATTACK,TROLL_PDEFENSE,1,1,TROLL_LEVEL){
        this->Set_exp_reward(TROLL_EXPERIENCE);
    }
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
};

#endif // TROLL_H
