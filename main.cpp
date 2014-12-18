#include <iostream>
#include <fstream>
//#include "Menu.h"
#include "Weapon.h"
#include "Armor.h"

Weapon Mweapon[100];
Armor Marmor[100];

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream in("data/Weapon.bon",std::ios::binary|std::ios::in);
    int k=-1;
    in>>k;
    for(int i=0;i<=k;i++){
        in.read((char*)&Mweapon[i],sizeof(Weapon));
    }
    in.close();
    in.open("data/Armor.bon",std::ios::binary|std::ios::in);
    k=-1;
    in>>k;
    for(int i=0;i<=k;i++){
        in.read((char*)&Marmor[i],sizeof(Armor));
    }
    in.close();
//    system("mode con cols=80 lines=40");
//    MENU();

    return 0;
}
