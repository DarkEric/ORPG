#include "berserk.h"
#include <math.h>
void Berserk::Attack(Critter *whom){
    if(whom->Status_Life()==true){
        whom->Get_dmg(floor((this->Get_attack()+this->Get_stat())*((float)(rand()%50+75)/100))-whom->Get_p_resist());
//        this->Set_energy(this->Get_energy()+20);
    }
}
void Berserk::Set_weapon(Weapon *THWeap){
    this->Set_attack(this->Get_attack()+THWeap->Attack());
}

void Berserk::Unset_weapon(Weapon *THWeap){
    this->Set_attack(this->Get_attack()-THWeap->Attack());
}

void Berserk::SP1(Critter *whom){
    whom->Get_dmg(floor(this->Get_MAX_HP()-this->Get_HP()));
    this->Get_dmg(this->Get_HP()*0.5);
}
