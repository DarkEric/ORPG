#include "quest.h"
#include <iostream>
#include <conio.h>
#include "Consol.h"



std::string Quest::Say_Npc(){}
void Quest::Set_Npc(std::string){

}
void Quest::set_flag(int n){Flag=n;}
int Quest::get_flag(){return Flag;}
int Quest::Choos(){
    system("cls");
    std::cout<<Say_Npc()<<"\n";
    SetConsoleText(2);
    std::cout<<Hero1;
    SetConsoleText(1);
    std::cout<<Hero2<<"\n";
    std::cout<<Hero3<<"\n";
    std::cout<<Hero4<<"\n";
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
            SetConsoleText(3);
            switch (f){
            case 1:{return 1;break;}
            case 2:{return 2;break;}
            case 3:{return 3;break;}
            case 4:{return 4;break;}
            }
            _getch();
            break;
        default:
            break;
        }
        if (ff){
            system("cls");
            if (f==1){
                std::cout<<Say_Npc()<<"\n";
                SetConsoleText(1);
                std::cout<<Hero1<<"\n";
                SetConsoleText(2);
                std::cout<<Hero2<<"\n";
                std::cout<<Hero3<<"\n";
                std::cout<<Hero4<<"\n";
                ff=0;
            }else if (f==2){
                std::cout<<Say_Npc()<<"\n";
                SetConsoleText(2);
                std::cout<<Hero1<<"\n";
                SetConsoleText(1);
                std::cout<<Hero2<<"\n";
                SetConsoleText(2);
                std::cout<<Hero3<<"\n";
                std::cout<<Hero4<<"\n";
            ff=0;
        }else if (f==3){
                std::cout<<Say_Npc()<<"\n";
                SetConsoleText(2);
                std::cout<<Hero1<<"\n";
                std::cout<<Hero2<<"\n";
                SetConsoleText(1);
                std::cout<<Hero3<<"\n";
                SetConsoleText(2);
                std::cout<<Hero4<<"\n";
                ff=0;
            }else if (f==4){
                std::cout<<Say_Npc()<<"\n";
                SetConsoleText(2);
                std::cout<<Hero1<<"\n";
                std::cout<<Hero2<<"\n";
                std::cout<<Hero3<<"\n";
                SetConsoleText(1);
                std::cout<<Hero4<<"\n";
                SetConsoleText(2);
                ff=0;
            } {/**/ff=1;}
        }
        c=_getch();
    }
}

void Quest::Set_Hero1(std::string){}
void Quest::Set_Hero2(std::string){}
void Quest::Set_Hero3(std::string){}
void Quest::Set_Choose1(Quest* ){}
void Quest::Set_Choose2(Quest* ){}
void Quest::Set_Choose3(Quest* ){}
std::string Quest::Get_Hero1(){}
std::string Quest::Get_Hero2(){}
std::string Quest::Get_Hero3(){}
Quest* Quest::Get_Choose1( ){}
Quest* Quest::Get_Choose2( ){}
Quest* Quest::Get_Choose3( ){}
