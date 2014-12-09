#ifndef WARRIORMOB_H
#define WARRIORMOB_H
#include "warriormob.h"
#include "stats.h"

class WarriorMob : public Monstr
{
public:
    WarriorMob(int x, int y):Monstr(MOB_START_HP,MOB_PATTACK,MOB_PDEFENSE,x,y ){}
    int PSkill();
};

#endif // WARRIORMOB_H
