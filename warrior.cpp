#include "warrior.h"

void Warrior::Set_armor(Plate* Armor){
    this->Set_p_resist(this->Get_p_resist()+Armor->Get_armor());
    this->Set_str(this->Get_str()+Armor->Get_stat());
}

void Warrior::Unset_armor(Plate* Armor){
    this->Set_p_resist(this->Get_p_resist()-Armor->Get_armor());
    this->Set_str(this->Get_str()-Armor->Get_stat());
}
