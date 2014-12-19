#include <iostream>
#include <fstream>
#include "Menu.h"
#include "Weapon.h"
#include "Armor.h"
#include "hero.h"
int Kweapon,Karmor;
Weapon Mweapon[100];
Armor Marmor[100];

int main()
{
    std::setlocale(LC_ALL,"Russian_Russia.1251");
    std::ifstream in("data/Weapon.bon",std::ios::binary|std::ios::in);
    int Kweapon=-1;
    in>>Kweapon;
    for(int i=0;i<=Kweapon;i++){
        in.read((char*)&Mweapon[i],sizeof(Weapon));
    }
    in.close();
    in.open("data/Armor.bon",std::ios::binary|std::ios::in);
    Karmor=-1;
    in>>Karmor;
    for(int i=0;i<=Karmor;i++){
        in.read((char*)&Marmor[i],sizeof(Armor));
    }
    in.close();
    MENU();
    return 0;
}
