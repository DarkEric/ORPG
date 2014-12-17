#ifndef MONSTR_H
#define MONSTR_H
#include "critter.h"
class Monstr:public Critter
{
public:
    Monstr(std::string name,int type,int MAX_HP,int dmg,int p_resist,int x,int y,int Level,int MAX_energy,int m_resist):Critter(name,type,MAX_HP,dmg,p_resist,x,y,Level,MAX_energy,m_resist)
    {
        this->heroin=0;
        this->agrrange=0;
        this->exp_reward=10;
    }

    void Set_agrrange(int n);
    int Get_agrrange();

    void Change_heroin();
    int Get_heroin();

    void Move(char** mas);

    void Set_exp_reward(int n);
    int Get_exp_reward();
private:
    int heroin,
        agrrange,
        exp_reward;
};

#endif // MONSTR_H
