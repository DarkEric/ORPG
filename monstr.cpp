#include "monstr.h"

void Monstr::Set_agrrange(int n){agrrange=n;}
int Monstr::Get_agrrange(){return agrrange;}

void Monstr::Change_heroin(){
    heroin++;
    heroin%=2;
}
int Monstr::Get_heroin(){return heroin;}
/*void Monstr::Move(int n){
    if (this->heroin==0) {
        int mob_x=this->Get_x(),mob_y=this->Get_y();
        while (n>0){
            int r=rand()%4;
            switch (r){
                case 0:{if (mob_x+1!='#') {mob_x++; n--;} break;}
                case 1:{if (mob_x-1!='#') {mob_x--; n--;} break;}
                case 2:{if (mob_y+1!='#') {mob_y++; n--;} break;}
                case 3:{if (mob_x+1!='#') {mob_y--; n--;} break;}
            }
        }
        char c= mas[this->Get_x()][this->Get_y()];

}
    else{
        BFS(this->Get_x(),this->Get_y()); Нужно найти кротчайший путь до героя
        PATH();   восстановить его
        на каждом шаге сначала смотреть не стал ли герой находиться
        ближе в данном маршруте, если да, то обрезать путь, если нет,
        то осмотреть соседние клетки от конечной(т.к. шаг перса 1).
    }

}*/

void Monstr::Set_exp_reward(int n){
    exp_reward=n;
}

int Monstr::Get_exp_reward(){return exp_reward;}

