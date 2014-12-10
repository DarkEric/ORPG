#ifndef WARRIORMOB_H
#define WARRIORMOB_H
#include "monstr.h"

class WarriorMob : public Monstr
{
public:
    WarriorMob(std::string name,int type,int MAX_HP,int dmg,int p_resist,int x,int y,int Level):Monstr(name,type,MOB_START_HP,MOB_PATTACK,MOB_PDEFENSE,x,y,Level){};
};

#endif // WARRIORMOB_H
