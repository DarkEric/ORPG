#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "controller.h"
#include "CreateCritter.h"
#include "Consol.h"
#include "NPC.h"
#include "dragon.h"
#include "troll.h"
#include "FightWindow.h"
#include "berserk.h"
#include "Dialogq.h"


class Controller
{
public:
    Controller(){}
    void Create();
    void BotMap(Hero *);
    static void FieldMap();
    void Set_PositionHero(int,int);
    int TalkCreate(int , int , Hero *);
    int FiendCreate(int, int, int);
    void WriteMap();
    char Get(int,int);
    void AmendMap(int,int,int,int,int);
    void ReadMap(std::string );
    int Get_PositionHero_x();
    int Get_PositionHero_y();
    int Get_Enter_x();
    int Get_Enter_y();
    int Get_Exit_x();
    int Get_Exit_y();
    void Set_Exit(int,int);
    void Set_Enter(int,int);
    std::string NextMap();
    std::string BreakMap();
    int Get_Reset_x();
    int Get_Reset_y();
    void Dialogq(Dialog *);

private:
   char Map[300][300];
   int Maplen_x;
   int Maplen_y;
   QNPC QuestNpc[10];
   Dialog* Mquest[20];
   BUM Npc[10];
   Monstr Drag[50];
   Troll Trolls[50];
   int PosHero_x;
   int PosHero_y;
   int Enter_x;
   int Enter_y;
   int Exit_x;
   int Exit_y;
   std::string nextMap;
   std::string breakMap;
   int Reset_x;
   int Reset_y;
   int Flag;
};

#endif // CONTROLLER_H
