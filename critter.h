#ifndef CRITTER_H
#define CRITTER_H
#include <string>
#include <stdlib.h>
class Critter
{
public:
    Critter(std::string name,int type,int MAX_HP,int dmg,int p_resist,int x,int y,int Level); //конструктор существа

    void Set_HP(int n); //установка здоровья на определённый уровень(чит)
    int Get_HP()const; //вернуть текущее здоровье
    void Get_dmg(int n);//получить урон
    void Heal(int n);//излечение

    void Set_attack(int n);//установить силу атаки
    int Get_attack()const;//узнать силу атаки

//    void Set_m_resist(int n);
//    int Get_m_resist();

    void Set_p_resist(int n);//установить уровень защиты
    int Get_p_resist()const;//узнать уровень защиты

    void Set_x(int n);
    int Get_x()const;

    void Set_y(int n);
    int Get_y()const;

    bool Status_Life()const;


    void Set_Level(int n);
    int Get_Level()const;
    void LevelUp();
    virtual void Move(int n);
    virtual void Attack(Critter* whom);
    virtual void SP1(Critter* whom){whom->Get_dmg(0);}
    virtual void SP2(Critter* whom){whom->Get_dmg(0);}
    virtual void SP3(Critter* whom){whom->Get_dmg(0);}
    virtual void SP4(Critter* whom){whom->Get_dmg(0);}
    virtual void SP5(Critter* whom){whom->Get_dmg(0);}
    virtual void SP6(Critter* whom){whom->Get_dmg(0);}
    virtual void SP7(Critter* whom){whom->Get_dmg(0);}
private:
    int HP,MAX_HP,
        dmg,Level,
//      m_resist,
        p_resist,
        x,y;
    bool life;
    std::string name;
    int type;
};

#endif // CRITTER_H
