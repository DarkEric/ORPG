#ifndef FIELD_H
#define FIELD_H

#include <string.h>
#include <Consol.h>
#include "CheckMob.h"

char Field[50][215];
int q=0,s=0;
int quest[5][3];
int citizens[5][3];
QNPC* Quest;
BUM* Bum;

void CreateQuest(int d){
    Quest=new QNPC[d+2];
    for (int i=1;i<=d;i++){
        Quest[i].Set_x(quest[i][1]);
        Quest[i].Set_y(quest[i][2]);
    }
}

void CreateBum(int d){
    Bum=new BUM[d+2];
    for (int i=1;i<=d;i++){
        Bum[i].Set_x(citizens[i][1]);
        Bum[i].Set_y(citizens[i][2]);
    }
}
void WriteField(int x, int y,int n,int m)
{
    for (int j = 1; j <= 119; j++)printf("*");
	printf("\n");

    for (int i = 1; i <= n; i++){
		printf("*");
        for (int j = 1; j <= m; j++)
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


void ReadField(std::string TownMap,int& n,int& m ){
    freopen(TownMap.c_str(),"r",stdin);


    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        //Field[i]=new char[m+2];
        for (int j=1;j<=m;j++)Field[i][j]=' ';
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
            }else Field[i][j]=c;
        }

    CreateQuest(q);
    CreateBum(s);
    system("cls");
}


void MoveHero(std::string TownMap){
    int n,m;
    ReadField(TownMap,n,m);
    int x = 6, y = 9;
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
                }else if (Field[x - 1][y]=='С'){
                    system("cls");
                    int numBum=FindBum(x-1,y,Bum,s);
                    Bum[numBum].Dialog(numBum/*номер гражд*/);
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
                }else if (Field[x - 1][y]=='С'){
                    system("cls");
                    int numBum=FindBum(x-1,y,Bum,s);
                    Bum[numBum].Dialog(numBum/*номер гражд*/);
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
                }else if (Field[x + 1][y]=='С'){
                    system("cls");
                    int numBum=FindBum(x+1,y,Bum,s);
                    Bum[numBum].Dialog(numBum/*номер гражд*/);
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
                }else{
                    system("cls");
                    Field[x][y++] = ' ';
                    Field[x][y] = 'H';
                    WriteField(x, y,n,m);
                }
			}
        }else MoveHero("Field");
		c = getch();
	}
}
#endif
