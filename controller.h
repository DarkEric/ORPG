#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "controller.h"
#include "CreateCritter.h"
#include "Consol.h"
#include "QNPC.h"
#include "NPC.h"
#include "dragon.h"
#include "troll.h"
#include "FightWindow.h"
#include "berserk.h"

class Controller
{
public:
    Controller();
    void Create();
    static void GlobalMap();
    static void FieldMap();
    static int PositionHero();
    void TalkCreate(int , int , Hero *);
    int FiendCreate(int,int);
    void WriteMap(int,int);
    char Get(int,int);
    void AmendMap(int,int,int,int,int);
    void ReadMap(std::string );

private:
   int Map[300][300];
   int Maplen_x;
   int Maplen_y;
   QNPC Quest[10];
   NPC Npc[10];
   Monstr Drag[50];
   Troll Trolls[50];
   int Flag;
   int PosHero_x;
   int PosHero_y;
};

#endif // CONTROLLER_H
