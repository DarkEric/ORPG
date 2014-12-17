#include "Dungeon.h"
#include "Dungeon.h"
#include "CreateCritter.h"
#include "Consol.h"
#include <conio.h>

char Dungeon[50][215];


int qd=0,sd=0,td=0;



QNPC* QuestDung;
BUM* BumDung;
Monstr* TrollsDung[15];


void WriteDungeon(int x, int y,int n,int m)
{
    for (int j = 1; j <= 119; j++)printf("*");
    printf("\n");
    if (m>=100)m=100;
    for (int i =x-7; i <= x+20; i++){
        printf("*");
        for (int j = y-7; j <= y+40; j++)
            if (Dungeon[i][j]=='H'){
                SetConsoleText(4);
                printf("%c", Dungeon[i][j]);
                SetConsoleText(3);
            }else{
            printf("%c", Dungeon[i][j]);
            }
        printf("*\n");
    }
    for (int j = 1; j <= 119; j++)printf("*");
    printf("\n");
    return;
}
void ReadDungeon(std::string TownMap,int& n,int& m,int**quest,int**citizens,int**troll ){
    freopen(TownMap.c_str(),"r",stdin);


    scanf("%d %d",&n,&m);
    for (int i=1;i<=49;i++){
        for (int j=1;j<=214;j++)Dungeon[i][j]=' ';
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char c;
            scanf("%c",&c);
            if (c=='\n')Dungeon[i][j]=' ';
            else if (c=='Q'){
                Dungeon[i][j]='Q';
                ++qd;
                quest[qd][1]=i;
                quest[qd][2]=j;
            }else if (c=='C'){
               Dungeon[i][j]='C';
               ++sd;
               citizens[sd][1]=i;
               citizens[sd][2]=j;
            }else if (c=='T'){
                Dungeon[i][j]='T';
                ++td;
                troll[td][1]=i;
                troll[td][2]=j;
             }else Dungeon[i][j]=c;
        }

    QuestDung=CreateQuest(qd,QuestDung,quest);
    BumDung=CreateBum(sd,BumDung,citizens);
    CreateTroll(td,TrollsDung,troll);
    system("cls");
}

void DungeonMap(std::string TownMap,Hero* Player){


    int** quest=new int*[11];
    int** citizens=new int*[11];
    int** troll=new int*[11];
    for(int i=1;i<=11;i++){
        quest[i]=new int[3];
        citizens[i]=new int[3];
        troll[i]=new int[3];
    }
    int n,m;


    ReadDungeon(TownMap,n,m,quest,citizens,troll);
    int x = 17, y = 11;
    Dungeon[x][y] = 'H';
    WriteDungeon(x, y,n,m);
    fclose(stdin);
    char c = getch();
    while (c != 27){
        if (Dungeon[x-1][y-1]=='T'||Dungeon[x-1][y]=='T'||Dungeon[x][y-1]=='T'||Dungeon[x+1][y]=='T'||Dungeon[x-1][y+1]=='T'||Dungeon[x-1][y+1]=='T'||Dungeon[x+1][y+1]=='T'||Dungeon[x+1][y-1]=='T'){
            system("cls");
            int numTroll=FindTroll(x-1,y-1,TrollsDung,td);
            if (numTroll=0)numTroll=FindTroll(x-1,y,TrollsDung,td);
            if (numTroll=0)numTroll=FindTroll(x,y-1,TrollsDung,td);
            if (numTroll=0)numTroll=FindTroll(x+1,y,TrollsDung,td);
            if (numTroll=0)numTroll=FindTroll(x,y+1,TrollsDung,td);
            if (numTroll=0)numTroll=FindTroll(x-1,y+1,TrollsDung,td);
            if (numTroll=0)numTroll=FindTroll(x+1,y-1,TrollsDung,td);
            if (numTroll=0)numTroll=FindTroll(x+1,y+1,TrollsDung,td);
            Fight(Player,TrollsDung[numTroll]);
            Dungeon[TrollsDung[numTroll]->Get_x()][TrollsDung[numTroll]->Get_y()]=' ';
            system("cls");
            WriteDungeon(x, y,n,m);
        }
        if (c == 72){
            if (x - 1 > 1 && Dungeon[x - 1][y] != '#'){
                if (Dungeon[x - 1][y]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x-1,y,QuestDung,qd);
                    QuestDung[numQuest].Dialog(numQuest/*номер квестовик */);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }else if (Dungeon[x - 1][y]=='C'){
                    system("cls");
                    int numBum=FindBum(x-1,y,BumDung,sd);
                    BumDung[numBum].Dialog(numBum/*номер гр жд*/);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }/*else if (Dungeon[x - 1][y]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x-1,y,TrollsDung,td);
                    Fight(Player,TrollsDung[numTroll]);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }*/else{
                    system("cls");
                    Dungeon[x--][y] = ' ';
                    Dungeon[x][y] = 'H';
                    WriteDungeon(x, y,n,m);
                }
            }
        }
        else if (c == 75){
            if (y - 1 > 1 && Dungeon[x][y - 1] != '#'){
                if (Dungeon[x][y - 1]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x,y-1,QuestDung,qd);
                    QuestDung[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }else if (Dungeon[x][y - 1]=='C'){
                    system("cls");
                    int numBum=FindBum(x,y-1,BumDung,sd);
                    BumDung[numBum].Dialog(numBum/*номер гр жд*/);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }/*else if (Dungeon[x][y - 1]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x,y-1,TrollsDung,td);
                    Fight(Player,TrollsDung[numTroll]);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }*/else {
                    system("cls");
                    Dungeon[x][y--] = ' ';
                    Dungeon[x][y] = 'H';
                    WriteDungeon(x, y,n,m);
                }
            }
        }
        else if (c == 80){
            if (x + 1 > 1 && Dungeon[x + 1][y] != '#'){
                if (Dungeon[x + 1][y]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x+1,y,QuestDung,qd);
                    QuestDung[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }else if (Dungeon[x + 1][y]=='C'){
                    system("cls");
                    int numBum=FindBum(x+1,y,BumDung,sd);
                    BumDung[numBum].Dialog(numBum/*номер гр жд*/);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }/*else if (Dungeon[x + 1][y]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x+1,y,TrollsDung,td);
                    Fight(Player,TrollsDung[numTroll]);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }*/else{
                    system("cls");
                    Dungeon[x++][y] = ' ';
                    Dungeon[x][y] = 'H';
                    WriteDungeon(x, y,n,m);
                }
            }
        }
        else if (c == 77){
            if (y + 1 > 1 && Dungeon[x][y + 1] != '#'){
                if (Dungeon[x][y + 1]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x,y+1,QuestDung,qd);
                    QuestDung[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }else if (Dungeon[x][y+1]=='C'){
                    system("cls");
                    int numBum=FindBum(x,y+1,BumDung,sd);
                    BumDung[numBum].Dialog(numBum/*номер гр жд*/);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }/*else if (Dungeon[x][y + 1]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x,y+1,TrollsDung,td);
                    Fight(Player,TrollsDung[numTroll]);
                    system("cls");
                    WriteDungeon(x, y,n,m);
                }*/else{
                    system("cls");
                    Dungeon[x][y++] = ' ';
                    Dungeon[x][y] = 'H';
                    WriteDungeon(x, y,n,m);
                }
            }
        }//else if (c==32) MoveHero("Dungeon.txt",Player);
        c = getch();
    }
}



