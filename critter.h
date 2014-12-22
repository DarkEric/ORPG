#ifndef CRITTER_H
#define CRITTER_H
#include <string>
#include <stdlib.h>
#include <stats.h>
#include <ID.h>
class Critter
{
public:
    Critter(){}
    Critter(std::string name,int type,int MAX_HP,int dmg,int p_resist,int x,int y,int Level,int MAX_energy,int m_resist); //конструктор существа

    void Set_HP(int n){HP=n;} //установка здоровья на определённый уровень(чит)
    int Get_HP()const; //вернуть текущее здоровье
    void Get_dmg(int n);//получить урон
    void Heal(int n);//излечение

    void Set_MAX_HP(int n){MAX_HP=n;}
    int Get_MAX_HP()const{return MAX_HP;}

    void Set_attack(int n);//установить силу атаки
    int Get_attack()const;//узнать силу атаки

     void Set_m_resist(int n);
     int Get_m_resist()const;

    void Set_p_resist(int n);//установить уровень защиты
    int Get_p_resist()const;//узнать уровень защиты

    void Set_x(int n);
    int Get_x()const;

    void Set_energy(int n){energy=n;}
    int Get_energy()const{return energy;}

    void Set_MAX_energy(int n){MAX_energy=n;}
    int Get_MAX_energy()const{return MAX_energy;}

    void Set_y(int n);
    int Get_y()const;

    void Set_name(std::string n){n.copy(this->name,n.length());}
    std::string Get_name()const{return name;}

    bool Status_Life()const;
    void Set_Life(bool n){life=n;}

    void Set_type(int n){type=n;}
    int Get_type()const{return type;}

    void Set_Level(int n);
    int Get_Level()const;

    void Set_name_SP(int n,std::string name){name.copy(this->name_SP[n],name.length()); name.operator +=('\0');}
    std::string Get_name_SP(int n)const{return name_SP[n];}

    void Set_energy_coast(int n,int a){energy_coast[n]=a;}
    int Get_energy_coast(int n)const{return energy_coast[n];}

    void Set_filename(std::string n){n.copy(this->filename,n.length());}
    std::string Get_filename()const{return filename;}

    virtual void LevelUp();
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
        m_resist,
        p_resist,
        x,y;
    bool life;
    char name[20];
    int type;
    int energy,MAX_energy;
    char name_SP[8][20];
    char filename[20];
    int energy_coast[8];
};

#endif // CRITTER_H
