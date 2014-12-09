#include "hero.h"

Hero::Hero(int MAX_HP, int dmg, int p_resist, int x, int y, int EXP, int Level):Critter(MAX_HP,dmg,p_resist,x,y)
{
    this->EXP=EXP;
    this->Level=Level;
}

void Hero::Set_EXP(int n){EXP=n;}
int Hero::Get_Level()const{return Level;}
int Hero::Get_EXP()const{return EXP;}
void Hero::Set_Level(int n){Level=n;}

void Hero::Add_EXP(int n){
    EXP=EXP+n;
}
void Hero::LevelUp(){
    Level++;
}
void Hero::Lose_EXP(int n){
    EXP=EXP-n;
}
