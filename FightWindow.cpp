#include "FightWindow.h"
#include <string.h>
#include <windows.h>

using std::string;

int Fight(Critter* character,Critter* mob)
{
    setlocale(LC_ALL, "ru");
    system("mode con cols=31 lines=80");
    string n1=character->Get_name();
    string n2=mob->Get_name();
//    int ln1=strlen(n1); //ПШЕ
//    string hp_char=character->Get_HP(); // HP В INT
//    string hp_mob=mob->Get_HP();
//    HANDLE hw = GetStdHandle(STD_OUTPUT_HANDLE);
    while ((character->Status_Life())||(mob->Status_Life())){
        system("cls");
        for (int i=1;i<=31;i++)printf("*");
        printf("\n");
        for (int i=2;i<=39;i++){
            printf("*");
            for (int j=2;j<=14;j++) printf("0");
            printf("*");
            for (int j=16;j<=30;j++) printf("0");
            printf("*\n");
        }
        for (int i=1;i<=31;i++)printf("*");
        printf("\n\n");
        
 //       printf("%s",n1);
 //       for (int i=ln1+1;i<=16;i++)printf(" ");
  //      printf("%s\n",n2);
        
        //SetConsoleCursorPosition(hw,)
        
    }
        
    return 0;
}
