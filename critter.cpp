#include "critter.h"

Critter::Critter(std::string name, int type, char sumbol, int MAX_HP, int dmg, int p_resist, int x, int y, int Level)
{

    this->type=type;
    this->sumbol=sumbol;
    this->name=name;
    this->HP=MAX_HP;
    this->MAX_HP=MAX_HP;
    this->dmg=dmg;
    this->p_resist=p_resist;
    this->x=x;
    this->y=y;
    this->Level=Level;
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
void Critter::Set_attack(int n){dmg=n;}
int Critter::Get_attack()const{return dmg;}
int Critter::Get_p_resist()const{return p_resist;}
void Critter::Attack(Critter* whom){
    if(whom->Status_Life()==true){
        whom->Get_dmg((this->Get_attack())-whom->Get_p_resist());
    }
}
int Critter::Get_Level()const{return Level;}

void Critter::Set_Level(int n){Level=n;}


void Critter::LevelUp(){
    Level++;
}