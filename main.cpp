#include "Menu.h"
#include "FightWindow.h"
#include "berserk.h"
#include "troll.h"
int main()
{
    setlocale(LC_ALL, "rus");
    system("mode con cols=80 lines=40");
    Berserk Vasya("Vasya");
    Troll mob;
    Fight(&Vasya,&mob);
    return 0;
}
