#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "controller.h"
#include "CreateCritter.h"
#include "Consol.h"
#include "QNPC.h"
#include "NPC.h"
#include ""
class Controller
{
public:
    Controller();
    static void GlobalMap();
    static void FieldMap();
    static int PositionHero();
private:
   int Map[300][300];
   int Maplen_x;
   int Maplen_y;

   int Flag;
};

#endif // CONTROLLER_H
