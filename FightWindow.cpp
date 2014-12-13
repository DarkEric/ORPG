#include "FightWindow.h"



using namespace std;

void PrintPictures(){
    system("cls");
    for (int i=1;i<=62;i++)printf("*");
    printf("\n");
    for (int i=2;i<=29;i++){
        printf("*");
        for (int j=2;j<=30;j++) printf("0");
        printf("**");
        for (int j=33;j<=61;j++) printf("0");
        printf("*\n");
    }
    for (int i=1;i<=62;i++)printf("*");
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
        mas[l+p-1]=a%10;
        a/=10;
    }
}

int Fight(Critter* character,Critter* mob)
{
    system("mode con cols=91 lines=50");
    int prior=1;
    string n1=character->Get_name();
    string n2=mob->Get_name();
    int hp_prev_c=character->Get_MAX_HP(),hp_prev_m=mob->Get_MAX_HP();
    int razn_c=0,razn_m=0;
    while ((character->Status_Life())&&(mob->Status_Life())){
        PrintPictures();
        printf("\n\n");
        cout << n1 << "                  " <<n2<<endl;
        cout << character->Get_HP() << " ( " << razn_c << " )" <<"            " << mob->Get_HP()<< " ( " << razn_m << " )" <<endl;
      //  cout << character->Get_energy()<<"             "<<mob->Get_energy()<<endl;
        if (prior==1){
            character->Attack(mob);
            razn_c=hp_prev_c-character->Get_HP();
            hp_prev_c=character->Get_HP();
            prior+=1; // Смена приоритета
            prior%=2; //
            Sleep(1000);
            if (mob->Get_HP()<0) {
                mob->Set_Life(false);
                cout << mob->Get_name() << " побежден!!";
                break;
            }
        }
        else if (prior==0){
            mob->Attack(character);
            razn_m=hp_prev_m-mob->Get_HP();
            hp_prev_m=mob->Get_HP();
            Sleep(1000);
            prior+=1;
            prior%=2;
            if (character->Get_HP()<0) {
                character->Set_Life(false);
                cout << "Вы погибли...Игра окончена";
                break;
            }
        }
    }
        
    return 0;
}
