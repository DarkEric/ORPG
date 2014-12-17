#include "FightWindow.h"
#include "Consol.h"
#include "conio.h"

using namespace std;

void infoPrint(Hero* character,Monstr* mob,string n1,string n2,int razn_c,int razn_m){
//        printMob(mobp,a2,b2);
        cout <<endl<< n2<<endl;
        cout <<"HP: "<< mob->Get_HP();
        if (razn_m!=0){
            cout<< " ( ";
            if (razn_m>0) cout<<"-";
            else if (razn_m<0) cout<<"+";
            cout<< razn_m << " )";
        }
        cout<<endl;
        cout<<"Energy: "<< mob->Get_energy()<<endl<<endl;

//        printHero(herop,a1,b1);
        cout<<endl<<n1<<endl;
        cout<<"HP: "<< character->Get_HP();
        if (razn_c!=0){
            cout<< " ( ";
            if (razn_c>0) cout<<"-";
            else if (razn_c<0) cout<<"+";
            cout<< razn_c << " )";
        }
        cout<<endl;
        cout<<"Energy: "<< character->Get_energy()<<endl;
}


void SkillChoice(Hero* character,Monstr* mob,string n1,string n2,int razn_c,int razn_m){
    std::string mas[6];
    setlocale(LC_ALL, "rus");
//    int status[6];
//    for(int i=1;i<=5;i++)status[i]=0;
    string s="Атака";
    mas[1]=s;
    for(int i=2;i<=4;i++)mas[i]=character->Get_name_SP(i-1);
    infoPrint(character,mob,n1,n2,razn_c,razn_m);
    SetConsoleText(1);
    cout<<mas[1]<<"\n";
    SetConsoleText(2);
    for (int i=2;i<=5;i++)cout<<mas[i]<<"\n";
    int f=1,ff=0;
    char c=_getch();
    while(1){
        switch (c) {
        case 72:
            if (f!=1){
                f--;
                ff=1;

            }
            break;
        case 80:
            if (f!=4){
                f++;
                ff=1;
            }
            break;
        case 13:
            //атака
            SetConsoleText(3);
            cout<<"атака, использ скил "<<f;
            return;
            _getch();
            break;
        default:
            break;
        }
        if (ff){
            system("cls");
            SetConsoleText(3);
            infoPrint(character,mob,n1,n2,razn_c,razn_m);
            SetConsoleText(2);
        for (int i=1;i<=5;i++)
            if (f==i){
                SetConsoleText(1);
                cout<<mas[i]<<"\n";
                SetConsoleText(2);
                ff=0;
            }else {cout<<mas[i]<<"\n";ff=1;}
        }
        c=_getch();
    }


}



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
    }
}

int Fight(Hero* character,Monstr* mob)
{
//    system("mode con cols=91 lines=50");
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

        if (prior==1){


            SkillChoice(character,mob,n1,n2,razn_c,razn_m);
            character->Attack(mob);
            razn_c=hp_prev_c-character->Get_HP();
            hp_prev_c=character->Get_HP();
            razn_m=0;
            prior+=1; // Смена приоритета
            prior%=2; //
            //Sleep(2000);
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
            razn_c=0;
           // Sleep(2000);
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
