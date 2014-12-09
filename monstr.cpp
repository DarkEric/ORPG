#include "monstr.h"
#include <time.h>

Monstr::Monstr()
{
    HP=100;
    dmg=10;
    heroin=0;
}
void Set_HP(int n){HP=n;}
int Get_HP(){return HP;}

void Set_dmg(int n){dmg=n;}
int Get_dmg(){return dmg;}

void Set_p_resist(int n){p_resist=n;}
int Get_dmg(){return p_resist;}

/*void Set_m_resist(int n){m_resist=n;}
int Get_m_resist(){return m_resist;}*/

void Set_x(int n){x=n;}
int Get_x(){return x;}

void Set_y(int n){y=n;}
int Get_y(){return y;}

void Set_agrrange(int n){agrrange=n;}
int Get_agrrange(){return agrrange;}

virtual void Move(int h){
    int m_x=Get_x(),m_y=Get_y();
    <Array>[m_x][m_y]=' ';
    if (heroin){
        /*int h_x=Hero::Hero.Get_x,h_y=Hero::Hero.Get_y;
        if (m_x<h_x)
            while (h>0){
                h--;
                h_x--;
            }
        else if (m_x>h_x)
            while (h>0){
                h--;
                h_x++;
            }                       Заменить на BFS
        if (m_y<h_y)
            while (h>0){
                h--;
                h_y--;
            }
        else if (m_y>h_y)
            while (h>0){
                h--;
                h_y++;
            }
        Monstr::Set_x(m_x);
        Monstr::Set_y(m_y);*/
    }
    else{
        int x=m_x,y=m_y;
        srand(time(NULL));
        while (h>0){
            int r=rand()%4;
            switch(r){
                case 0:{
                    if (<Array>[x+1][y]!='#') x++;
                    h--;
                }
                case 1:{
                    if (<Array>[x-1][y]!='#') x--;
                    h--;
                }
                case 2:{
                    if (<Array>[x][y+1]!='#') y++;
                    h--;
                }
                case 3:{
                    if (<Array>[x][y-1]!='#') y--;
                    h--;
                }
            }
        }
        <Array>[m_x][m_y]='<Обозначение моба>';
    }


