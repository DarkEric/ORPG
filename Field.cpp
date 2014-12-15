#include "Field.h"
#include "CreateCritter.h"

char Field[50][215];


int q=0,s=0,t=0;



QNPC* Quest;
BUM* Bum;
Critter* Trolls[15];

void WriteField(int x, int y,int n,int m)
{
    for (int j = 1; j <= 119; j++)printf("*");
    printf("\n");
    if (m>=100)m=100;
    for (int i = x-15; i <= x+15; i++){
        printf("*");
        for (int j = y-30; j <= y+80; j++)
            if (Field[i][j]=='H'){
                SetConsoleText(4);
                printf("%c", Field[i][j]);
                SetConsoleText(3);
            }else{
            printf("%c", Field[i][j]);
            }
        printf("*\n");
    }
    for (int j = 1; j <= 119; j++)printf("*");
    printf("\n");
    return;
}
void ReadField(std::string TownMap,int& n,int& m,int**quest,int**citizens,int**troll ){
    freopen(TownMap.c_str(),"r",stdin);


    scanf("%d %d",&n,&m);
    for (int i=1;i<=49;i++){
        for (int j=1;j<=214;j++)Field[i][j]=' ';
    }

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char c;
            scanf("%c",&c);
            if (c=='\n')Field[i][j]=' ';
            else if (c=='Q'){
                Field[i][j]='Q';
                ++q;
                quest[q][1]=i;
                quest[q][2]=j;
            }else if (c=='C'){
               Field[i][j]='C';
               ++s;
               citizens[s][1]=i;
               citizens[s][2]=j;
            }else if (c=='T'){
                Field[i][j]='T';
                ++t;
                troll[t][1]=i;
                troll[t][2]=j;
             }else Field[i][j]=c;
        }

    Quest=CreateQuest(q,Quest,quest);
    Bum=CreateBum(s,Bum,citizens);
    CreateTroll(t,Trolls,troll);
    system("cls");
}

void MoveHero(std::string TownMap,Hero* Player){


    int** quest=new int*[11];
    int** citizens=new int*[11];
    int** troll=new int*[11];
    for(int i=1;i<=11;i++){
        quest[i]=new int[3];
        citizens[i]=new int[3];
        troll[i]=new int[3];
    }
    int n,m;


    ReadField(TownMap,n,m,quest,citizens,troll);
    int x = 17, y = 11;
    Field[x][y] = 'H';
    WriteField(x, y,n,m);
    fclose(stdin);
    char c = getch();
    while (c != 27){
        if (c == 72){
            if (x - 1 > 1 && Field[x - 1][y] != '#'){
                if (Field[x - 1][y]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x-1,y,Quest,q);
                    Quest[numQuest].Dialog(numQuest/*номер квестовика*/);
                    system("cls");
                    WriteField(x, y,n,m);
                }else if (Field[x - 1][y]=='C'){
                    system("cls");
                    int numBum=FindBum(x-1,y,Bum,s);
                    Bum[numBum].Dialog(numBum/*номер гражд*/);
                    system("cls");
                    WriteField(x, y,n,m);
                }else if (Field[x - 1][y]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x-1,y,Trolls,t);
                    Fight(Player,Trolls[numTroll]);
                    system("cls");
                    WriteField(x, y,n,m);
                }else{
                    system("cls");
                    Field[x--][y] = ' ';
                    Field[x][y] = 'H';
                    WriteField(x, y,n,m);
                }
            }
        }
        else if (c == 75){
            if (y - 1 > 1 && Field[x][y - 1] != '#'){
                if (Field[x][y - 1]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x,y-1,Quest,q);
                    Quest[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteField(x, y,n,m);
                }else if (Field[x][y - 1]=='C'){
                    system("cls");
                    int numBum=FindBum(x,y-1,Bum,s);
                    Bum[numBum].Dialog(numBum/*номер гражд*/);
                    system("cls");
                    WriteField(x, y,n,m);
                }else if (Field[x][y - 1]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x,y-1,Trolls,t);
                    Fight(Player,Trolls[numTroll]);
                    system("cls");
                    WriteField(x, y,n,m);
                }else {
                    system("cls");
                    Field[x][y--] = ' ';
                    Field[x][y] = 'H';
                    WriteField(x, y,n,m);
                }
            }
        }
        else if (c == 80){
            if (x + 1 > 1 && Field[x + 1][y] != '#'){
                if (Field[x + 1][y]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x+1,y,Quest,q);
                    Quest[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteField(x, y,n,m);
                }else if (Field[x + 1][y]=='C'){
                    system("cls");
                    int numBum=FindBum(x+1,y,Bum,s);
                    Bum[numBum].Dialog(numBum/*номер гражд*/);
                    system("cls");
                    WriteField(x, y,n,m);
                }else if (Field[x + 1][y]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x+1,y,Trolls,t);
                    Fight(Player,Trolls[numTroll]);
                    system("cls");
                    WriteField(x, y,n,m);
                }else{
                    system("cls");
                    Field[x++][y] = ' ';
                    Field[x][y] = 'H';
                    WriteField(x, y,n,m);
                }
            }
        }
        else if (c == 77){
            if (y + 1 > 1 && Field[x][y + 1] != '#'){
                if (Field[x][y + 1]=='Q'){
                    system("cls");
                    int numQuest=FindQuest(x,y+1,Quest,q);
                    Quest[numQuest].Dialog(numQuest);
                    system("cls");
                    WriteField(x, y,n,m);
                }else if (Field[x][y+1]=='C'){
                    system("cls");
                    int numBum=FindBum(x,y+1,Bum,s);
                    Bum[numBum].Dialog(numBum/*номер гражд*/);
                    system("cls");
                    WriteField(x, y,n,m);
                }else if (Field[x][y + 1]=='T'){
                    system("cls");
                    int numTroll=FindTroll(x,y+1,Trolls,t);
                    Fight(Player,Trolls[numTroll]);
                    system("cls");
                    WriteField(x, y,n,m);
                }else{
                    system("cls");
                    Field[x][y++] = ' ';
                    Field[x][y] = 'H';
                    WriteField(x, y,n,m);
                }
            }
        }//else if (c==32) MoveHero("Field.txt",Player);
        c = getch();
    }
}
