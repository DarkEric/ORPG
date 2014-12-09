#ifndef CRITTER_H
#define CRITTER_H

class Critter
{
public:
    Critter(int MAX_HP,int dmg,int p_resist,int x,int y,int Level); //конструктор существа

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

    virtual void Move(int n);
    virtual void Attack(Critter* whom);
private:
    int HP,MAX_HP,
        dmg,Level,
//      m_resist,
        p_resist,
        x,y;
    bool life;
};

#endif // CRITTER_H
