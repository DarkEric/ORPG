#include "berserk.h"
#include "troll.h"
#include "FightWindow.h"

    int main()
    {
        setlocale(LC_ALL,"rus");
        Berserk Vasya("Vasya");
        Troll Kolya(1,1);
        Fight(&Vasya,&Kolya);
        return 0;
    }
