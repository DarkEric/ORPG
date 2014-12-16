#ifndef FIELD_H
#define FIELD_H
#include <string.h>
#include <conio.h>
#include "Consol.h"
#include "CheckMob.h"
#include "FightWindow.h"
#include "hero.h"
#include "CreateCritter.h"

void WriteField(int, int,int,int);


void ReadField(std::string, int&, int&, int **quest, int **citizens, int **troll);


void MoveHero(std::string,Hero*);
#endif
