#ifndef CREATECRITTER_H
#define CREATECRITTER_H
#include "QNPC.h"
#include "troll.h"
#include "BUM.h"
#include "dragon.h"
QNPC *CreateQuest(int ,QNPC* ,int** );
BUM *CreateBum(int , BUM * , int** );
void CreateTroll(int ,Monstr** ,int** );
Dragon *CreateBum(int , Dragon * , int** );
#endif // CREATECRITTER_H
