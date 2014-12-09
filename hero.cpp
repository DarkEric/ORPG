#include "hero.h"

int Hero::Get_EXP()const{return EXP;}
void Hero::Set_EXP(int n){EXP=n;}

void Hero::Lose_EXP(int n){
    EXP=EXP-n;
}
void Hero::Add_EXP(int n){
    EXP=EXP+n;
}
