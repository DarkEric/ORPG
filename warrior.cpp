#include "hero.h"

void Hero::Set_armor(Armor* Arm){
    this->Set_p_resist(this->Get_p_resist()+Arm->Get_armor());
    this->Set_stat(this->Get_stat()+Arm->Get_stat());
}

void Wa::Unset_armor(Armor* Arm){
    this->Set_p_resist(this->Get_p_resist()-Arm->Get_armor());
    this->Set_stat(this->Get_stat()-Arm->Get_stat());
}
