#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "controller.h"
using std::string;

void Controller::Create(){
    int x,y;
    scanf("%d %d",&x,&y);
    PosHero_x=x;
    PosHero_y=y;
    int n,l=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        Quest[l].Set_x(x);
        Quest[l++].Set_y(y);
    }
    l=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        Npc[l].Set_x(x);
        Npc[l++].Set_y(y);
    }
    l=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        Trolls[l].Set_x(x);
        Trolls[l++].Set_y(y);
    }
    l=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        Drag[l].Set_x(x);
        Drag[l++].Set_y(y);
    }
    return;
}

void Controller::ReadMap(string Mname){
    freopen(Mname.c_str(),"r",stdin);
    int x,y;
    scanf("%d %d",&x,&y);
    Maplen_x=x;
    Maplen_y=y;
    for (int i=1;i<=x;i++)
        for(int j=1;j<=y;j++){
            char c;
            scanf("%c",&c);
            Map[i][j]=c;
        }
    fclose(stdin);
    Create();
}
void Controller::WriteMap(int x,int y){

    for (int j = 1; j <= 119; j++)printf("*");
    printf("\n");
    for (int i=x-8;i<=x+30;i++){
        printf("*");
        for (int j=y-8;j+110;j++)
            if (Map[i][j]=='H'){
                SetConsoleText(4);
                printf("%c", Map[i][j]);
                SetConsoleText(3);
            }else{
            printf("%c", Map[i][j]);
            }
        printf("*\n");
    }
    for (int j = 1; j <= 119; j++)printf("*");
    printf("\n");
    return;
}
char Controller::Get(int i,int j){
    return Map[i][j];
}
void Controller::TalkCreate(int c,int num,Hero* Player){
    switch(c){
    case 1:
        Npc[num].Dialog();
        break;
    case 2:
        Quest[num].Dialog(1);
        break;
    case 3 :
        Fight(Player,&Trolls[num]);
        break;
    case 4:
        Fight(Player,&Drag[num]);
        break;
    default:
        break;
    }
}

int Controller::FiendCreate(int x,int y){
    char ch=Map[x][y];
    switch(ch){
    case ' ':
        break;
    case 'C':
        for (int i=1;i<=10;i++)
            if (x==Npc[i].Get_x()&&y==Npc[i].Get_y())
                return i;
        break;
    case 'Q':
        for (int i=1;i<=10;i++)
            if (x==Quest[i].Get_x()&&y==Quest[i].Get_y())
                return i;
        break;
    case 'T':
        for (int i=1;i<=50;i++)
            if (x==Trolls[i].Get_x()&&y==Trolls[i].Get_y())
                return i;
        break;
    case 'D':
        for (int i=1;i<=50;i++)
            if (x==Drag[i].Get_x()&&y==Drag[i].Get_y())
                return i;
        break;
    default:
        break;
    }
    return 0;
}

void Controller::GlobalMap(){


}

void Controller::AmendMap(int n,int i,int j,int x,int y){
    switch(n){
    case 1:
        std::swap(Map[i][j],Map[x][y]);
        break;
    case 2:

        break;
    }
}
int Controller::PositionHero(){
    return 0;
}


