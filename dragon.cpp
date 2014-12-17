#include "dragon.h"
#include <iostream>
#include <math.h>
#include "monstr.h"
void Dragon::Attack(Critter *whom){
    if(whom->Status_Life()==true){
        whom->Get_dmg(this->Get_attack()-whom->Get_p_resist());
    }
}

void Dragon::SP1(Critter *whom){
    if(whom->Status_Life()==true){
        int damage=(this->Get_attack())+(this->Get_attack())/2-whom->Get_p_resist();
        damage+=floor(damage*(float)(rand()%10+95)/100);
        whom->Get_dmg(damage);
        this->Set_energy(this->Get_energy()-this->Get_energy_coast(1));
    }
}

void Dragon::SP2(Critter *whom){
    if(whom->Status_Life()==true){
        int damage=((this->Get_attack())*2)-whom->Get_p_resist();
        damage+=floor(damage*(float)(rand()%20+95)/100);
        whom->Get_dmg(damage);
        this->Set_energy(this->Get_energy()-this->Get_energy_coast(2));
    }
}

void Dragon::SP3(Critter *whom){
    if(whom->Status_Life()==true){
        int damage=floor((float)(this->Get_Level())*1.5)-whom->Get_m_resist();
        damage+=floor(damage*(float)(rand()%12+95)/100);
        whom->Get_dmg(damage);
        this->Set_energy(this->Get_energy()-this->Get_energy_coast(3));
    }
}
