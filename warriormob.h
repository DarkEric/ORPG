#ifndef WARRIORMOB_H
#define WARRIORMOB_H
#include "monstr.h"

class WarriorMob : public Monstr
{
public:
    WarriorMob(std::string name,int type,int MAX_HP,int dmg,int p_resist,int x,int y,int Level):Monstr(name,type,MAX_HP,dmg,p_resist,x,y,Level){};
};

#endif // WARRIORMOB_H
