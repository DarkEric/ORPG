#ifndef MONSTR_H
#define MONSTR_H
#include "critter.h"
class Monstr:public Critter
{
public:
    Monstr(){}
    Monstr(std::string name,int type,int MAX_HP,int dmg,int p_resist,int x,int y,int Level,int MAX_energy,int m_resist):Critter(name,type,MAX_HP,dmg,p_resist,x,y,Level,MAX_energy,m_resist)
    {
        this->heroin=0; //флаг, видит ли моб героя
        this->agrrange=10;//радиус агра
        this->exp_reward=10; //опыт, получаемый за убийство моба
    }

    void Change_heroin(); //изменить флажок видимости героя
    int Get_heroin(); //вывести флаг видимости

    void Set_next_step(int value_x, int value_y);//установить следующий шаг
    int Get_next_x();//вывести x шага
    int Get_next_y();//вывести у шага

    void Move(char mas[300][300]); //передвинуть моба

    void Set_exp_reward(int n); //назначить опыт за убийство моба
    int Get_exp_reward();//вывести опыт за убийство моба

    //===
    void Mob_read();
private:
    int heroin,
        agrrange,
        exp_reward,
        next_x,
        next_y;
    char Mob_Mas[60][60];
};

#endif // MONSTR_H
