#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "controller.h"
#include <fstream>
#include "conio.h"
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
    //std::ifstream in(Mname.c_str());]
    freopen(Mname.c_str(),"r",stdin);
    int x,y;
    scanf("%d %d",&x,&y);
    Maplen_x=x;
    Maplen_y=y;
    Create();

    for (int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            char c=getchar();
            if (c=='\n')Map[i][j]=' ';
            else Map[i][j]=c;
        }
    }
    fclose(stdin);

//    freopen("0.txt","w",stdout);
//    for (int i=1;i<=x;i++){
//        printf("\n");
//        for(int j=1;j<=y;j++)
//            printf("%c",Map[i][j]);
//    }
//    printf("\n\n");
//    fclose(stdout);
}
void Controller::WriteMap(){
    system("cls");
    int x=PosHero_x,
        y=PosHero_y;
    Map[x][y]='H';
    for (int j = 1; j <= 119; j++)std::cout<<"*";//printf("*");
    std::cout<<"\n";//printf("\n");
    for (int i=x-8;i<=x+20;i++){
        std::cout<<"*";
        int j=0;
        for (j=y-8; j<=y+108;j++)
            if (Map[i][j]=='H'){
                SetConsoleText(4);
                std::cout<<Map[i][j];
                //printf("%c", Map[i][j]);
                SetConsoleText(3);
            }else{
            std::cout<<Map[i][j];
            //printf("%c", Map[i][j]);
            }
        std::cout<<"*\n";
        //printf("*\n");
    }
    for (int j = 1; j <= 119; j++)std::cout<<"*";//printf("*");
    std::cout<<"\n";
    //printf("\n");
    return;
}
char Controller::Get(int i,int j){
    return Map[i][j];
}
void Controller::TalkCreate(int c,int num,Hero* Player){
    switch(c){
    case 1:
        Npc[num].Dialog(1);
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

int Controller::FiendCreate(int x,int y,int n){
    char ch=Map[x][y];
    switch(ch){
    case ' ':
        break;
    case 'C':
//        if (n==1)x=x+1;
//        else if(n==2)x=x-1;
//        else if (n==3)y=y+1;
//        else if (n==4)y=y-1;
        for (int i=1;i<=10;i++)
            if (x==Npc[i].Get_x()&&y==Npc[i].Get_y()+1)
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
        PosHero_x=x;
        PosHero_y=y;
        break;
    case 2:
        Map[x][y]=Map[i][j];
        Map[i][j]=' ';
        PosHero_x=x;
        PosHero_y=y;
        break;
    }
}
void Controller::Set_PositionHero(int x, int y){
    PosHero_x=x;
    PosHero_y=y;
    return;
}
int Controller::Get_PositionHero_x(){
    return PosHero_x;
}
int Controller::Get_PositionHero_y(){
    return PosHero_y;
}
