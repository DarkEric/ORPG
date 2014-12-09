#include "hero.h"

Hero::Hero()
{}

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
