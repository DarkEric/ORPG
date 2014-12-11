#include "troll.h"
#include <iostream>
#include <math.h>
#include "warriormob.h"
void Troll::Attack(Critter *whom){
    if(whom->Status_Life()==true){
        whom->Get_dmg(this->Get_attack()-whom->Get_p_resist());
    }
}

void Troll::SP1(Critter *whom){
    if(whom->Status_Life()==true){
        int damage=(this->Get_attack())+(this->Get_attack())/2-whom->Get_p_resist();
        damage+=floor(damage*(float)(rand()%10+95)/100);
        whom->Get_dmg(damage);
    }
}

void Troll::SP2(Critter *whom){
    if(whom->Status_Life()==true){
        int damage=floor((float)(this->Get_attack())*2.5)-whom->Get_p_resist();
        damage+=floor(damage*(float)(rand()%30+95)/100);
        whom->Get_dmg(damage);
    }
}
