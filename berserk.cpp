#include "berserk.h"
#include "iostream"
void Berserk::Attack(Critter *whom){
    if(whom->Status_Life()==true){
        whom->Get_dmg((this->Get_attack())+(this->Get_weapon()->Attack())+this->Get_stat()*2-whom->Get_p_resist());
        std::cout<<"III"<<std::endl;
    }
}
void Berserk::Set_weapon(Weapon *THWeap){
    this->Set_attack(this->Get_attack()+THWeap->Attack());
}

void Berserk::Unset_weapon(Weapon *THWeap){
    this->Set_attack(this->Get_attack()-THWeap->Attack());
}
