#ifndef WARRIORMOB_H
#define WARRIORMOB_H
#include "monstr.h"
#include "stats.h"

class WarriorMob : public Monstr
{
public:
    WarriorMob(std::string name,int type,int Level,int x, int y):Monstr(name,type,MOB_START_HP,MOB_PATTACK,MOB_PDEFENSE,x,y,Level){};
};

#endif // WARRIORMOB_H
