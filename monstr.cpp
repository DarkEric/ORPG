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

void Monstr::Move(char mas[300][300]){
    if (this->heroin==0) {
        int h=1;
        int mob_x=this->Get_x(),mob_y=this->Get_y();
        /*while (h>0){
            int r=rand()%4;
            switch (r){
                case 0:{if (mas[mob_x+1][mob_y]==' ') {mob_x++; h--;} break;}
                case 1:{if (mas[mob_x-1][mob_y]==' ') {mob_x--; h--;} break;}
                case 2:{if (mas[mob_x][mob_y+1]==' ') {mob_y++; h--;} break;}
                case 3:{if (mas[mob_x][mob_y-1]==' ') {mob_y--; h--;} break;}
            }
        }*/
        Set_next_step(mob_x,mob_y);
    }
    mas[this->Get_x()][this->Get_y()]=' ';
    mas[next_x][next_y]=(char)(this->Get_type());
    this->Set_x(next_x);
    this->Set_y(next_y);
}

void Monstr::Set_exp_reward(int n){
    exp_reward=n;
}

int Monstr::Get_exp_reward(){return exp_reward;}

