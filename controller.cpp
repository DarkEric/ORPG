#include <string.h>
#include <stdlib.h>
#include <iostream>
#include "controller.h"
#include <fstream>
#include "conio.h"
#include "hero.h"
using std::string;

void Controller::Create(){
    int x,y;
    scanf("%d %d",&PosHero_x,&PosHero_y);
    Reset_x=PosHero_x;
    Reset_y=PosHero_y;
    int n,l=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        Map[x][y]='Q';
        QuestNpc[i].Set_x(x);
        QuestNpc[i].Set_y(y);
        QuestNpc[i].Set_Id(i);
    }
    l=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        Map[x][y]='C';
        Npc[i].Set_x(x);
        Npc[i].Set_y(y);
    }
    l=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        Map[x][y]='T';
        Trolls[i].Set_x(x);
        Trolls[i].Set_y(y);
    }
    l=1;
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        Map[x][y]='D';
        Drag[i].Set_x(x);
        Drag[i].Set_y(y);
    }
    scanf("%d %d",&Enter_x,&Enter_y);
    scanf("%d %d",&Exit_x,&Exit_y);
    std::cin>>breakMap>>nextMap;
    //std::cout<<breakMap<<nextMap;
    //_getch();
    //scanf("%s %s",&breakMap,&nextMap);
    return;
}

void Controller::ReadMap(string Mname){
    //std::ifstream in(Mname.c_str());]
    if (Flag==1)return;
    Flag=1;


    freopen(Mname.c_str(),"r",stdin);
    int x,y;
    scanf("%d %d",&x,&y);
    Maplen_x=x;
    Maplen_y=y;
    for (int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            char c=getchar();
            if (c=='\n')Map[i][j]=' ';
            else Map[i][j]=c;
        }
    }
    fclose(stdin);
    std::string Mnameinfo=Mname.operator +=("info");
    std::cout<<Mname;
    freopen(Mnameinfo.c_str(),"r",stdin);
    Create();
    fclose(stdin);
}
void Controller::WriteMap(){
    system("cls");
    int x=PosHero_x,
        y=PosHero_y;
    Map[x][y]='H';
    if (Maplen_x<40&&Maplen_y<120){
        x=16;
        y=56;
    }
    for (int j = 1; j <= 119; j++)std::cout<<"*";
    std::cout<<"\n";
    for (int i=x-15;i<=x+15;i++){
        std::cout<<"*";
        int j=0;
        for (j=y-55; j<=y+61;j++)
            if (Map[i][j]=='H'){
                SetConsoleText(4);
                std::cout<<Map[i][j];;
                SetConsoleText(3);
            }else std::cout<<Map[i][j];
        std::cout<<"*\n";
    }
    for (int j = 1; j <= 119; j++)std::cout<<"*";
    std::cout<<"\n";
    return;
}
char Controller::Get(int i,int j){
    return Map[i][j];
}
int Controller::TalkCreate(int c,int num,Hero* Player){
    switch(c){
    case 1:
        Npc[num].Dialog(1);
        break;
    case 2:
        QuestNpc[num].Dialog(1);
        break;
    case 3 :
        if (Fight(Player,&Trolls[num])){
            Map[PosHero_x][PosHero_y]=' ';
            PosHero_x=Reset_x;
            PosHero_y=Reset_y;
            return 0;
        }return 1;
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
        for (int i=1;i<=10;i++)
            if (x==Npc[i].Get_x()&&y==Npc[i].Get_y()+1)
                return i;
        break;
    case 'Q':
        for (int i=1;i<=10;i++)
            if (x==QuestNpc[i].Get_x()&&y==QuestNpc[i].Get_y()+1)
                return i;
        break;
    case 'T':
        for (int i=1;i<=50;i++)
            if (x==Trolls[i].Get_x()&&y==Trolls[i].Get_y()+1)
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

void Controller::BotMap(Hero* Player){
    for (int i=1;i<=2;i++){
        Player->SearchMob(Trolls,2,Map);
        for (int j=1;j<=7;j++){
            if(!Trolls[j].Status_Life())continue;
            Trolls[j].Move(Map);
            if (Map[PosHero_x-1][PosHero_y]=='T'||
                Map[PosHero_x-1][PosHero_y-1]=='T'||
                Map[PosHero_x-1][PosHero_y+1]=='T'||
                Map[PosHero_x][PosHero_y-1]=='T'||
                Map[PosHero_x][PosHero_y+1]=='T'||
                Map[PosHero_x+1][PosHero_y]=='T'||
                Map[PosHero_x+1][PosHero_y-1]=='T'||
                Map[PosHero_x+1][PosHero_y+1]=='T')
                if (Fight(Player,&Trolls[j])){
                    Map[PosHero_x][PosHero_y]=' ';
                    PosHero_x=Reset_x;
                    PosHero_y=Reset_y;
                }else {
                    Trolls[j].Set_Life(false);
                    Map[Trolls[j].Get_x()][Trolls[j].Get_y()]=' ';
                }
        }
    }

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
void Controller::Set_Exit(int x, int y){
    Exit_x=x;
    Exit_y=y;
    return;
}
void Controller::Set_Enter(int x, int y){
    Enter_x=x;
    Enter_y=y;
    return;
}
int Controller::Get_PositionHero_x(){
    return PosHero_x;
}
int Controller::Get_PositionHero_y(){
    return PosHero_y;
}
int Controller::Get_Exit_x(){
    return Exit_x;
}
int Controller::Get_Exit_y(){
    return Exit_y;
}
int Controller::Get_Enter_x(){
    return Enter_x;
}
int Controller::Get_Enter_y(){
    return Enter_y;
}
std::string Controller::NextMap(){
  return nextMap;
}
std::string Controller::BreakMap(){
  return breakMap;
}
int Controller::Get_Reset_x(){
    return Reset_x;
}
int Controller::Get_Reset_y(){
    return Reset_y;
}
int Controller::Dialog(Quest* N){
    do{
        switch(N->Choos()){
        case 1:{if (N->Get_Choose1()==NULL)return N->get_flag();
            Dialog(N->Get_Choose1());break;}
        case 2:{if (N->Get_Choose1()==NULL)return N->get_flag();
            Dialog(N->Get_Choose2());break;}
        case 3:{if (N->Get_Choose1()==NULL)return N->get_flag();
            Dialog(N->Get_Choose3());break;}
        case 4:return N->get_flag();
        }
    }while(N->get_flag()!=0)
}
