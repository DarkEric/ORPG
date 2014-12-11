#include "warrior.h"

void Warrior::Set_armor(Armor* Arm){
    this->Set_p_resist(this->Get_p_resist()+Arm->Get_armor());
    this->Set_stat(this->Get_stat()+Arm->Get_stat());
}

void Warrior::Unset_armor(Armor* Arm){
    this->Set_p_resist(this->Get_p_resist()-Arm->Get_armor());
    this->Set_stat(this->Get_stat()-Arm->Get_stat());
}
