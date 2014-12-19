#ifndef DUNGEON_H
#define DUNGEON_H
#include "CheckMob.h"
#include "FightWindow.h"
#include "hero.h"
 

void WriteField(int, int,int,int);
void ReadField(std::string, int&, int&, int **quest, int **citizens, int **troll);
void DungeonMap(std::string,Hero*);


#endif
