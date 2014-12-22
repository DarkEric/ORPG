#include "monstr.h"

void Monstr::Set_next_step(int value_x, int value_y){
    next_x=value_x;
    next_y=value_y;
}

int Monstr::Get_next_x(){return next_x;}
int Monstr::Get_next_y(){return next_y;}

void Monstr::Change_heroin(){
    heroin++;
    heroin%=2;
}
int Monstr::Get_heroin(){return heroin;}

void Monstr::Move(char** mas){
    if (this->heroin==0) {
        int h=3;
        int mob_x=this->Get_x(),mob_y=this->Get_y();
        while (h>0){
            int r=rand()%4;
            switch (r){
                case 0:{if (mob_x+1==' ') {mob_x++; h--;} break;}
                case 1:{if (mob_x-1==' ') {mob_x--; h--;} break;}
                case 2:{if (mob_y+1==' ') {mob_y++; h--;} break;}
                case 3:{if (mob_y-1==' ') {mob_y--; h--;} break;}
            }
        }
        Set_next_step(mob_x,mob_y);
    }
//    mas[this->Get_x()][this->Get_y()]=' ';
//    mas[next_x][next_y]=this->Get_type();
}

void Monstr::Set_exp_reward(int n){
    exp_reward=n;
}

int Monstr::Get_exp_reward(){return exp_reward;}

