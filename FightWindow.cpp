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

//void PrintPictures(){
//    for (int i=1;i<=62;i++)printf("*");
//    printf("\n");
//    for (int i=2;i<=29;i++){
//        printf("*");
//        for (int j=2;j<=30;j++) printf("0");
//        printf("**");
//        for (int j=33;j<=61;j++) printf("0");
//        printf("*\n");
//    }
//    for (int i=1;i<=62;i++)printf("*");
//    return;
//}

void printHero(char** herop,int a1,int b1){
    for (int i=1;i<=a1;i++){
        for (int j=1;j<=b1;j++)
            cout<<herop[i][j];
        cout<<endl;
    }
}

void printMob(char** mobp,int a2, int b2){
    for (int i=1;i<=a2;i++){
        for (int j=1;j<=b2;j++)
            cout<<mobp[i][j];
        cout<<endl;

int Fight(Hero* character,Monstr* mob)
{
    system("mode con cols=91 lines=50");
    srand(time(NULL));
    int prior=1;
    string n1=character->Get_name();
    string n2=mob->Get_name();
    int hp_prev_c=character->Get_MAX_HP(),hp_prev_m=mob->Get_MAX_HP();
    int razn_c=0,razn_m=0;
    while ((character->Status_Life())&&(mob->Status_Life())){
//    char** herop,mobp;
//    int a1,b1,a2,b2;
//    file* f=fopen(character->picture,"r");
//    cin>>a1,b1;
//    mobp=new mobp* [a1+1];
//    for (int i=1;i<=a1;i++) mobp[i]=new mobp[b1];
//    for (int i=1;i<=a1;i++)
//        for (int j=1;j<=b1;j++)
//            cin>>mobp[i][j];
//    fclose(f);
//    file* f1=fopen(mob->picture,"r");
//    cin>>a2,b2;
//    herop=new herop* [a2+1];
//    for (int i=1;i<=a2;i++) herop[i]=new herop[b2];
//    for (int i=1;i<=a2;i++)
//        for (int j=1;j<=b2;j++)
//            cin>>herop[i][j];
//    fclose(f1);

        system("cls");
        //PrintPictures();

//        printMob(mobp,a2,b2);
//        cout <<endl<< n2<<endl;
//        cout << mob->Get_HP();
//        if (razn_m!=0){
//            cout<< " ( ";
//            if (razn_m<0) cout<<"-";
//            else if (razn_m>0) cout<<"+";
//            cout<< razn_m << " )";
//        }
//        cout<<endl;
//        cout<<mob->Get_energy()<<endl<<endl;

//        printHero(herop,a1,b1);
//        cout<<endl<<n1<<endl;
//        cout<<character->Get_HP();
//        if (razn_c!=0){
//            cout<< " ( ";
//            if (razn_c<0) cout<<"-";
//            else if (razn_c>0) cout<<"+";
//            << razn_c << " )";
//        }
//        cout<<endl;
//        cout<<character->Get_energy()<<endl;

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
                character->Add_EXP(mob->Get_exp_reward());
                break;
            }
        }
        else if (prior==0){
            int r=rand()%10;
            if (mob->Get_HP() > mob->Get_MAX_HP()*0.1){
                if ((r>2)||(mob->Get_energy()<5)) mob->Attack(character);
                else mob->SP1(character);
            }
            else{
                if ((r>8)||(mob->Get_energy()<15)) mob->Attack(character);
                else mob->SP2(character);
            }

            razn_m=hp_prev_m-mob->Get_HP();
            hp_prev_m=mob->Get_HP();
            Sleep(1000);
            prior+=1;
            prior%=2;
            if (character->Get_HP()<0) {
                character->Set_Life(false);
                cout << "Вы погибли...Игра окончена";
                character->Lose_EXP(mob->Get_exp_reward()*5);
                break;
            }
        }
    }
        
    return 0;
}
