#include "critter.h"

Critter::Critter(int MAX_HP, int dmg, int p_resist, int x, int y)
{
    this->HP=MAX_HP;
    this->MAX_HP=MAX_HP;
    this->dmg=dmg;
    this->p_resist=p_resist;
    this->x=x;
    this->y=y;
    this->life=true;
}
//void Hero::Set_m_resist(int n)const{m_resist=n;}
void Critter::Set_p_resist(int n){p_resist=n;}
int Critter::Get_HP()const{return HP;}
int Critter::Get_x()const{return x;}
int Critter::Get_y()const{return y;}
void Critter::Set_x(int n){x=n;}
void Critter::Set_y(int n){y=n;}
void Critter::Get_dmg(int n){
    HP=HP-n;
    if(HP<1)life=false;
}
void Critter::Move(int n){
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
void Critter::Heal(int n){
    HP=HP+n;
    if(HP>MAX_HP)HP=MAX_HP;
}
bool Critter::Status_Life()const{
    return life;
}
void Attack(Critter* who,Critter* whom){
    if(whom->Status_Life()==true){
        whom->Get_dmg(who->Get_attack()-whom->Get_p_resist());
    }
}
