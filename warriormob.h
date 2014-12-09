#ifndef WARRIORMOB_H
#define WARRIORMOB_H
#include "monstr.h"
#include "stats.h"

class WarriorMob : public Monstr
{
public:
    WarriorMob(std::string name,int type,int sumbol,int Level,int x, int y):Monstr(name,type,sumbol,MOB_START_HP,MOB_PATTACK,MOB_PDEFENSE,x,y,Level){}
    void PSkill(Critter* whom);
};

#endif // WARRIORMOB_H
