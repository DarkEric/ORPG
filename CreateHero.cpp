#include "CreateHero.h"


Hero* NewHero(int n,std::string name){
    Hero* a;
    switch (n) {
    case 1:
       a=new Berserk(name);
        break;
    default:
        break;
    }
    return a;
}

std::string EnterName(){
    SetConsoleText(3);
    std::string name;
    std::cout<<"\n\n\tEnter name: ";
    SetConsoleText(1);
    std::getline(std::cin,name);
    SetConsoleText(3);
    name.operator +=("\0");
    return name;
}

int SelectNewHero(){


    std::cout<<"\tSelect new hero:\n";
    SetConsoleText(1);
    std::cout<< "\t1.Berserk\n";
    SetConsoleText(2);
    // новые герои
    int c = _getch();
    while(c!=13)c = _getch();
    return 1;



    /*при добавлении игроков
     *
     *
    int c = _getch();
    while (ff == 0){
        switch (c){
        case 72:{
            if (f == 2){
                system("cls");
                for (int i = 1; i <= 5; i++)std::cout << "\n";
                SetConsoleText(1);
                std::cout << "\tNew game\n";
                SetConsoleText(2);
                std::cout << "\tLoad game\n";
                std::cout << "\tExit\n";
                f = 1;
            }
            else
                if (f == 3){
                system("cls");
                for (int i = 1; i <= 5; i++)std::cout << "\n";
                SetConsoleText(2);
                std::cout << "\tNew game\n";
                SetConsoleText(1);
                std::cout << "\tLoad game\n";
                SetConsoleText(2);
                std::cout << "\tExit\n";
                f = 2;
                }
            break;
        }
        case 80:{
            if (f == 1){
                system("cls");
                for (int i = 1; i <= 5; i++)std::cout << "\n";
                SetConsoleText(2);
                std::cout << "\tNew game\n";
                SetConsoleText(1);
                std::cout << "\tLoad game\n";
                SetConsoleText(2);
                std::cout << "\tExit\n";
                f = 2;
            }
            else
                if (f == 2){
                system("cls");
                for (int i = 1; i <= 5; i++)std::cout << "\n";
                SetConsoleText(2);
                std::cout << "\tNew game\n";
                std::cout << "\tLoad game\n";
                SetConsoleText(1);
                std::cout << "\tExit\n";
                f = 3;
                }
            break;
        }
        case 13:{
            SetConsoleText(3);
            //system("cls");
            SetConsoleFont(6);
            system("mode con cols=80 lines=30");
            if (f == 1)ReadField();
            ff = 1;
            break; }
        default:break;
        }
        c = _getch();
    }*/

}

void CreateHero(){
    int a=SelectNewHero();
    std::string b=EnterName();
    b.operator +=('\0');
    Hero* Player=NewHero(a,b);
    SetConsoleFont(6);
    system("mode con cols=120 lines=50");

    Game(Player,"LES1",0);
}

