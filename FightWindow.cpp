#include "FightWindow.h"



using namespace std;

void PrintPictures(){
    system("cls");
    for (int i=1;i<=61;i++)printf("*");
    printf("\n");
    for (int i=2;i<=29;i++){
        printf("*");
        for (int j=2;j<=30;j++) printf("0");
        printf("**");
        for (int j=33;j<=61;j++) printf("0");
        printf("*\n");
    }
    for (int i=1;i<=61;i++)printf("*");
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

/*void FormStatsMas(Critter* character, Critter* mob, char** mas){

    int hp_char=character->Get_HP(),hp_mob=mob->Get_HP();
    int energy_char=character->Get_energy();
    int energy_mob=mob->Get_energy();
    IntToChar(hp_char,mas[2],1); //Вписываем
    IntToChar(hp_mob,mas[2],32);
    IntToChar(energy_char,mas[3],1);
    IntToChar(energy_mob,mas[3],32);

}*/

/*void PrintStats(char** mas){
    for (int i=1;i<=3;i++){
        for (int j=1;j<=61;j++) printf("%c",mas[i][j]);
        printf("\n");
    }

}*/

int Fight(Critter* character,Critter* mob)
{
    system("mode con cols=91 lines=50");
    int prior=1;
   /* char** mas=new char*[4];
    for (int i=0;i<4;i++){
        mas[i]=new char[62];
    }*/
    string n1=character->Get_name();
    string n2=mob->Get_name();
   // int ln1=n1.size();
  //  int ln2=n2.size();
  //  for (int i=1;i<=ln1;i++) mas[1][i]=n1[i-1];
  //  for (int i=32;i<=32+ln2;i++) mas[1][i]=n2[i-1];
    while ((character->Status_Life())&&(mob->Status_Life())){
       //PrintPictures();
        printf("\n\n");
        //FormStatsMas(character,mob,mas);
        cout << n1 << "                  " <<n2<<endl;
        cout << character->Get_HP() << "            " << mob->Get_HP()<< endl;
      //  cout << character->Get_energy()<<"             "<<mob->Get_energy()<<endl;
       // PrintStats(mas);
        if (prior==1){
            character->Attack(mob);
            cout<< "Герой атаковал" << endl;
            prior+=1; // Смена приоритета
            prior%=2; //
            Sleep(1);
            if (mob->Get_HP()<0) {
                mob->Set_Life(false);
                system("cls");
                cout<< mob->Get_name() <<" побежден!!";
                break;
            }
        }
        if (prior==0){
            mob->Attack(character);
            cout<< "Mob атаковал" << endl;
            Sleep(1);
            prior+=1;
            prior%=2;
            if (character->Get_HP()<0) {
                character->Set_Life(false);
                system("cls");
                cout << "Вы погибли...Игра окончена";
                break;
            }
        }
    }
        
    return 0;
}
