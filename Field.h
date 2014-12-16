#ifndef FIELD_H
#define FIELD_H
<<<<<<< HEAD

=======
>>>>>>> origin/master
#include <string.h>
#include <conio.h>
#include "Consol.h"
#include "CheckMob.h"
<<<<<<< HEAD

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
=======
#include "FightWindow.h"
#include "hero.h"
#include "CreateCritter.h"

void WriteField(int, int,int,int);
>>>>>>> origin/master


void ReadField(std::string, int&, int&, int **quest, int **citizens, int **troll);


void MoveHero(std::string,Hero*);
#endif
