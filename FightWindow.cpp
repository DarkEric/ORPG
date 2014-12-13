#include "FightWindow.h"


using namespace std;

void PrintPictures(){
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
    return;
}

void IntToChar(int a,char* mas,int p){
    int b=a;
    int l=0;
    while (b>0){
        l++;
        b/=10;
    }
    while (a>0){
        mas[l+p-1]=a%10+48;
        a/=10;
    }
}

void FormStatsMas(Critter* character, Critter* mob, char** mas){

    int hp_char=character->Get_HP(),hp_mob=mob->Get_HP();
    int energy_char=character->Get_energy();
    int energy_mob=mob->Get_energy();
    IntToChar(hp_char,mas[2],1); //Вписываем
    IntToChar(hp_mob,mas[2],16);
    IntToChar(energy_char,mas[3],1);
    IntToChar(energy_mob,mas[3],16);

}

void PrintStats(char** mas){
    for (int i=1;i<=3;i++){
        for (int j=1;j<=31;j++) printf("%c",mas[i][j]);
        printf("\n");
    }
}

int Fight(Critter* character,Critter* mob)
{
    system("mode con cols=31 lines=80");
    int prior=1;
    char** mas=new char*[4];
    for (int i=0;i<4;i++){
        mas[i]=new char[32];
    }
    string n1=character->Get_name();
    string n2=mob->Get_name();
    int ln1=n1.size();
    int ln2=n2.size();
    for (int i=1;i<=ln1;i++) mas[1][i]=n1[i-1];
    for (int i=16;i<=16+ln2;i++) mas[1][i]=n2[i-1];
    while ((character->Status_Life())&&(mob->Status_Life())){
        PrintPictures();
        printf("\n\n");
        FormStatsMas(character,mob,mas);
        PrintStats(mas);
        if (prior){
            character->Attack(mob);
            prior+=1; // Смена приоритета
            prior%=2; //
            Sleep(2);
            if (mob->Get_HP()<0) {
                mob->Set_Life(false);
                system("cls");
                cout<< mob->Get_name() <<" побежден!!";
                break;
            }
        }
        if (prior){
            mob->Attack(character);
            Sleep(2);
            prior+=1;
            prior%=2;
            if (character->Get_HP()<0) {
                character->Set_Life(false);
                system("cls");
                printf("Вы погибли...Игра окончена");
                break;
            }
        }
    }
        
    return 0;
}
