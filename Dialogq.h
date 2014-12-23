#ifndef QUEST_H
#define QUEST_H
#include <stdlib.h>
#include <string>
//#include "ID.h"


class Dialog
{
public:
    Dialog(){Hero4="До свиданье!";}
    std::string Say_Npc();
    int Choos();
    void Set_Npc(std::string);
    void Set_Hero1(std::string);
    void Set_Hero2(std::string);
    void Set_Hero3(std::string);
    void Set_Choose1(Dialog* );
    void Set_Choose2(Dialog* );
    void Set_Choose3(Dialog* );
    std::string Get_Hero1();
    std::string Get_Hero2();
    std::string Get_Hero3();
    Dialog *Get_Choose1();
    Dialog *Get_Choose2();
    Dialog *Get_Choose3();
    void set_flag(int n);
    int get_flag();
    int Get_rIDquest(){return rIDquest;}
    int Get_IDquest(){return IDquest;}
    int Get_NeedIDquest(){return NeedIDquest;}
    void Set_rIDquest(int n){rIDquest=n;}
    void Set_IDquest(int n){IDquest=n;}
    void Set_NeedIDquest(int n){NeedIDquest=n;}
private:
    std::string Npc;
    std::string Hero1;
    std::string Hero2;
    std::string Hero3;
    std::string Hero4;
    Dialog* Choose1;
    Dialog* Choose2;
    Dialog* Choose3;
    int Flag;
    int rIDquest;
    int IDquest;
    int NeedIDquest;

};

#endif // QUEST_H
