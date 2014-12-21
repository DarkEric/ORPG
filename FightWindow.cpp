#include "FightWindow.h"
#include "Consol.h"
#include <conio.h>

using std::endl;
using std::cout;
using std::cin;
using std::string;


void printPicture(char** mas,int a,int b){
    for (int i=1;i<=a;i++){
        for (int j=1;j<=b;j++)
            cout<<mas[i][j];
        cout<<endl;
    }
}

void infoPrint(Hero* character,Monstr* mob,string n1,string n2,int razn_c,int razn_m){
//        printPicture(mobp,a2,b2);
        cout <<endl<< n2<<" lvl: "<<mob->Get_Level()<<endl;
        cout <<"HP: "<< mob->Get_HP();
        if (razn_m!=0){
            cout<< " ( ";
            if (razn_m>0) cout<<"-";
            else if (razn_m<0) cout<<"+";
            cout<< razn_m << " )";
        }
        cout<<endl;
        cout<<"Energy: "<< mob->Get_energy()<<endl<<endl;

//        printPicture(herop,a1,b1);
        cout<<endl<<n1<<" lvl: "<<character->Get_Level()<<endl;
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
    int n=0;
    for (int i=1;i<=2;i++) if (character->Get_energy()>=character->Get_energy_coast(i)) n++;
    string *mas= new string [n+2];
    setlocale(LC_ALL, "rus");
//    int status[6];
//    for(int i=1;i<=5;i++)status[i]=0;
//    string s=;
    mas[1]="Атака";
    for(int i=2;i<=n+1;i++)mas[i]=character->Get_name_SP(i-1);
    infoPrint(character,mob,n1,n2,razn_c,razn_m);
    SetConsoleText(1);
    cout<<mas[1]<<"\n";
    SetConsoleText(2);
    for (int i=2;i<=n+1;i++)cout<<mas[i]<<"\n";
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
            if (f!=n){
                f++;
                ff=1;
            }
            break;
        case 13:
            SetConsoleText(3);
            switch (f){
            case 1:{character->Attack(mob);break;}
            case 2:{character->SP1(mob);break;}
            case 3:{character->SP2(mob);break;}
            }

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
        for (int i=1;i<=n+1;i++)
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

void Fight(Hero* character,Monstr* mob)
{
    srand(time(NULL));
    int prior=1;
    string n1=character->Get_name();
    string n2=mob->Get_name();
    int hp_prev_c=character->Get_MAX_HP(),hp_prev_m=mob->Get_MAX_HP();
    int razn_c=0,razn_m=0;
    int chance_SP[8]={0,1,2,3,5,8,13,21};
    for (int i=1;i<=7;i++)
        if (mob->Get_name_SP(i)=="1")
            chance_SP[0]++;
        else break;
    while ((character->Status_Life())&&(mob->Status_Life())){
//    char** herop,mobp;
//    int a1,b1,a2,b2;
//    file* f=fopen(character->filename,"r");
//    cin>>a1,b1;
//    mobp=new mobp* [a1+1];
//    for (int i=1;i<=a1;i++) mobp[i]=new mobp[b1];
//    for (int i=1;i<=a1;i++)
//        for (int j=1;j<=b1;j++)
//            cin>>mobp[i][j];
//    fclose(f);
//    file* f1=fopen(mob->filename,"r");
//    cin>>a2,b2;
//    herop=new herop* [a2+1];
//    for (int i=1;i<=a2;i++) herop[i]=new herop[b2];
//    for (int i=1;i<=a2;i++)
//        for (int j=1;j<=b2;j++)
//            cin>>herop[i][j];
//    fclose(f1);

        system("cls");
        if (prior==1){


            SkillChoice(character,mob,n1,n2,razn_c,razn_m);
//            character->Attack(mob);
            razn_c=hp_prev_c-character->Get_HP();
            hp_prev_c=character->Get_HP();
            razn_m=0;
            prior+=1; // смена приоритета
            prior%=2; //
            if (mob->Get_HP()<=0) {
                mob->Set_Life(false);
                system("cls");
                infoPrint(character,mob,n1,n2,razn_c,razn_m);
                cout << mob->Get_name() << " побежден!!";
                character->Add_EXP(mob->Get_exp_reward());
                return;
            }
        }
        else if (prior==0){
            infoPrint(character,mob,n1,n2,razn_c,razn_m);
            int r=rand()%chance_SP[chance_SP[0]];
            for (int i=1;i<=chance_SP[0];i++){
                if (mob->Get_energy_coast(i)>mob->Get_energy()){
                    mob->Attack(character);
                    break;
                }
                else{
                    if (chance_SP[i]>r)
                        switch(i){
                        case 1:{mob->SP1(character); break;}
                        case 2:{mob->SP2(character); break;}
                        case 3:{mob->SP3(character); break;}
                        case 4:{mob->SP4(character); break;}
                        case 5:{mob->SP5(character); break;}
                        case 6:{mob->SP6(character); break;}
                        case 7:{mob->SP7(character); break;}
                        }
                }
            }

            razn_m=hp_prev_m-mob->Get_HP();
            hp_prev_m=mob->Get_HP();
            razn_c=0;
            prior+=1;
            prior%=2;
            Sleep(1500);
            if (character->Get_HP()<=0) {
                character->Set_Life(false);
                system("cls");
                infoPrint(character,mob,n1,n2,razn_c,razn_m);
                cout << "Поражение .. игра окончена.";
                if (mob->Get_Level()<character->Get_Level())
                    cout<<endl<<"Днище, иди руки выпрямляй.";
                Sleep(2000);
                character->Lose_EXP(mob->Get_exp_reward()*5);
                exit(0);
                return;
            }
        }
    }
        
    return;
}
