#ifndef TROLL_H
#define TROLL_H
#include "monstr.h"
class Troll : public Monstr
{
public:
    Troll(int x,int y):Monstr("Troll",ID_TYPE_TROLL,TROLL_START_HP,TROLL_PATTACK,TROLL_PDEFENSE,x,y,TROLL_LEVEL){
        this->Set_exp_reward(TROLL_EXPERIENCE);
        for (int i=1;i<=7;i++) {
            this->Set_name_SP(i,"0");
        }
        this->Set_name_SP(1,"Hammer Crush");
        this->Set_name_SP(2,"Crush of Doom");
    }
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
};

#endif // TROLL_H
