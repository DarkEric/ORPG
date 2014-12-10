#include <iostream>
#include "hero.h"
#include "berserk.h"
#include "stats.h"
#include "warriormob.h"
#include "string"
using namespace std;

int main()
{
    Critter* MyChap= new Berserk("nameHero",1,'5');
    Monstr* NewEnemy= new WarriorMob("Enemy",1,'*',1,1,1);
    MyChap->Attack(NewEnemy);
    return 0;
}

