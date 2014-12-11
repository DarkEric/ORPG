#include "monstr.h"

void Monstr::Set_agrrange(int n){agrrange=n;}
int Monstr::Get_agrrange(){return agrrange;}

void Monstr::Change_heroin(){
    heroin++;
    heroin%=2;
}
int Monstr::Get_heroin(){return heroin;}

void Monstr::Set_exp_reward(int n){
    exp_reward=n;
}

int Monstr::Get_exp_reward(){return exp_reward;}

