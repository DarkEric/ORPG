#ifndef HERO_H
#define HERO_H

class Hero
{
public:
    Hero();

    void Set_HP(int n);
    int Get_HP();

    void Set_dmg(int n);
    int Get_dmg();

    void Set_XP(int n);
    int Get_XP();

    void Set_m_resist(int n);
    int Get_m_resist();

    void Set_p_resist(int n);
    int Get_p_resist();

    void Set_Level(int n);
    int Get_Level();

private:
    int HP,
        dmg,
        XP,
        m_resist,
        p_resist,
        Level;
};

#endif // HERO_H
