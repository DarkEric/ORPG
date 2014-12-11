#include "hero.h"

int Hero::Get_EXP()const{return EXP;}
void Hero::Set_EXP(int n){EXP=n;}

void Hero::Lose_EXP(int n){
    EXP=EXP-n;
}
void Hero::Add_EXP(int n){
    EXP=EXP+n;
}
void Berserk::Set_weapon(DblWeapon* THWeap){
    this->Set_attack(this->Get_attack()+THWeap->Attack());
}

void Berserk::Unset_weapon(DblWeapon* THWeap){
    this->Set_attack(this->Get_attack()-THWeap->Attack());
}
void Warrior::Set_armor(Plate* Armor){
    this->Set_p_resist(this->Get_p_resist()+Armor->Get_armor());
    this->Set_str(this->Get_str()+Armor->Get_stat());
}

void Warrior::Unset_armor(Plate* Armor){
    this->Set_p_resist(this->Get_p_resist()-Armor->Get_armor());
    this->Set_str(this->Get_str()-Armor->Get_stat());
}
