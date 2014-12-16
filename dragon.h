#ifndef DRAGON_H
#define DRAGON_H

class Dragon : public Monstr
{
public:
    Dragon():Monstr("Dragon",ID_TYPE_TROLL,TROLL_START_HP,TROLL_PATTACK,TROLL_PDEFENSE,1,1,TROLL_LEVEL,TROLL_START_ENERGY,TROLL_MDEFENSE){
        this->Set_exp_reward(TROLL_EXPERIENCE);
        for (int i=1;i<=7;i++) {
            this->Set_name_SP(i,"0");
        }
//        this->Set_name_SP(1,"Power Strike");
//        this->Set_name_SP(2,"Tail Strike");
//        this->Set_name_SP(3,"Flame Breath");
//        this->Set_name_SP(4,"Flame Breath");
    }
    void Attack(Critter *whom);
    void SP1(Critter *whom);
    void SP2(Critter *whom);
};

#endif // DRAGON_H
