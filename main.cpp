#include "berserk.h"
#include "troll.h"
#include "FightWindow.h"
    int main()
    {
        Berserk Vasya("Vasya");
        Troll Kolya("Kolya",1,1,1,1);
        Fight(&Vasya,&Kolya);
        return 0;
    }
