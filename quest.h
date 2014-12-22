#ifndef QUEST_H
#define QUEST_H
#include <stdlib.h>
#include <string>
//#include "ID.h"


class Quest
{
public:
    Quest(){Hero4="До свиданье!";}
    std::string Say_Npc();
    int Choos();
    void Set_Npc(std::string);
    void Set_Hero1(std::string);
    void Set_Hero2(std::string);
    void Set_Hero3(std::string);
    void Set_Choose1(Quest* );
    void Set_Choose2(Quest* );
    void Set_Choose3(Quest* );
    std::string Get_Hero1();
    std::string Get_Hero2();
    std::string Get_Hero3();
    Quest *Get_Choose1();
    Quest *Get_Choose2();
    Quest *Get_Choose3();
private:
    std::string Npc;
    std::string Hero1;
    std::string Hero2;
    std::string Hero3;
    std::string Hero4;
    Quest* Choose1;
    Quest* Choose2;
    Quest* Choose3;
};

#endif // QUEST_H
