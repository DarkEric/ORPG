#ifndef CRITTER_H
#define CRITTER_H

class Critter
{
public:
    Critter();

    void Set_HP(int n);
    int Get_HP()const;
    int Get_dmg(int n);


    void Set_attack(int n);
    int Get_attack()const;

//    void Set_m_resist(int n);
//    int Get_m_resist();

    void Set_p_resist(int n);
    int Get_p_resist()const;

    void Set_x(int n);
    int Get_x()const;

    void Set_y(int n);
    int Get_y()const;

    virtual void Move(int n);
private:
    int HP,MAX_HP,
        dmg,
//      m_resist,
        p_resist,
        x,y;
};

#endif // CRITTER_H
