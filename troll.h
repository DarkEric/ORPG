#ifndef TROLL_H
#define TROLL_H
#include "monstr.h"
class Troll : public Monstr
{
public:
    Troll(std::string name,int type,int x,int y,int Level):Monstr(name,type,TROLL_START_HP,TROLL_PATTACK,TROLL_PDEFENSE,x,y,Level){
        this->Set_exp_reward(TROLL_EXPERIENCE);
    }
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
};

#endif // TROLL_H
