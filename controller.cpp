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
    //Maplen_x=x;
    //Maplen_y=y;
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

}
/*    char c = getch();
    while (c != 27){
        if (c == 72){
            if (x - 1 > 1 && Map[x - 1][y] != '#'){
                if (Map[x - 1][y]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x-1,y,Quest,q);
                    Quest[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteMap(x, y);
                }else if (Map[x - 1][y]=='C'){
                    system("cls");
                    int numBum=FindBum(x-1,y,Bum,s);
                    Bum[numBum].Dialog(numBum);
                    system("cls");
                    WriteMap(x, y);
                }else if (Map[x - 1][y]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x-1,y,Trolls,t);
                    Fight(Player,Trolls[numTroll]);
                    system("cls");
                    WriteMap(x, y);
                }else if (Map[x - 1][y]=='D'){
                    system("cls");
                    int numDrag=FindDrag(x-1,y,Trolls,50);
                    Fight(Player,Drag[numDrag]);
                    system("cls");
                    WriteMap(x, y);
                }else{
                    system("cls");
                    Map[x--][y] = ' ';
                    Map[x][y] = 'H';
                    WriteMap(x, y);
                }
            }
        }
        else if (c == 75){
            if (y - 1 > 1 && Map[x][y - 1] != '#'){
                if (Map[x][y - 1]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x,y-1,Quest,q);
                    Quest[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteMap(x, y);
                }else if (Map[x][y - 1]=='C'){
                    system("cls");
                    int numBum=FindBum(x,y-1,Bum,s);
                    Bum[numBum].Dialog(numBum);
                    system("cls");
                    WriteMap(x, y);
                }else if (Map[x][y - 1]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x,y-1,Trolls,t);
                    Fight(Player,Trolls[numTroll]);
                    system("cls");
                    WriteMap(x, y);
                }else {
                    system("cls");
                    Map[x][y--] = ' ';
                    Map[x][y] = 'H';
                    WriteMap(x, y);
                }
            }
        }
        else if (c == 80){
            if (x + 1 > 1 && Map[x + 1][y] != '#'){
                if (Map[x + 1][y]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x+1,y,Quest,q);
                    Quest[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteMap(x, y);
                }else if (Map[x + 1][y]=='C'){
                    system("cls");
                    int numBum=FindBum(x+1,y,Bum,s);
                    Bum[numBum].Dialog(numBum);
                    system("cls");
                    WriteMap(x, y);
                }else if (Map[x + 1][y]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x+1,y,Trolls,t);
                    Fight(Player,Trolls[numTroll]);
                    system("cls");
                    WriteMap(x, y);
                }else{
                    system("cls");
                    Map[x++][y] = ' ';
                    Map[x][y] = 'H';
                    WriteMap(x, y);
                }
            }
        }
        else if (c == 77){
            if (y + 1 > 1 && Map[x][y + 1] != '#'){
                if (Map[x][y + 1]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x,y+1,Quest,q);
                    Quest[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteMap(x, y,n,m);
                }else if (Map[x][y+1]=='C'){
                    system("cls");
                    int numBum=FindBum(x,y+1,Bum,s);
                    Bum[numBum].Dialog(numBum);
                    system("cls");
                    WriteMap(x, y);
                }else if (Map[x][y + 1]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x,y+1,Trolls,t);
                    Fight(Player,Trolls[numTroll]);
                    system("cls");
                    WriteMap(x, y);
                }else{
                    system("cls");
                    Map[x][y++] = ' ';
                    Map[x][y] = 'H';
                    WriteMap(x, y);
                }
            }
        }else if (c==32) DungeonMap("Map.txt",Player);
        c = getch();
    }*/
