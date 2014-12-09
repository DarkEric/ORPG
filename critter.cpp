#include "critter.h"

Critter::Critter()
{
}
//void Hero::Set_m_resist(int n)const{m_resist=n;}
void Critter::Set_p_resist(int n){p_resist=n;}
int Critter::Get_HP()const{return HP;}
int Critter::Get_x()const{return x;}
int Critter::Get_y()const{return y;}
void Critter::Set_x(int n){x=n;}
void Critter::Set_y(int n){y=n;}
int Critter::Get_dmg(int n){
    HP=HP-n;
    return Get_HP();
}
void Critter::move(int n){
    switch (n) {
    case 1:
        y++;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        x--;
        break;
    default:
        break;
    }
}
