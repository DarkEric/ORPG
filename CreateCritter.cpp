#include "CreateCritter.h"

QNPC *CreateQuest(int d,QNPC* Quest,int** quest){
    Quest=new QNPC[d+2];
    for (int i=1;i<=d;i++){
        Quest[i].Set_x(quest[i][1]);
        Quest[i].Set_y(quest[i][2]);
    }
    return Quest;
}
BUM* CreateBum(int d, BUM* Bum, int** citizens){
    Bum=new BUM[d+1];
    for (int i=1;i<=d;i++){
        Bum[i].Set_x(citizens[i][1]);
        Bum[i].Set_y(citizens[i][2]);
    }
    return Bum;
}

void CreateTroll(int d, Monstr **Trolls, int** troll){
    for(int i=0;i<15;i++){
        Trolls[i]=new Troll();
    }
    //std::cout<<Trolls[1]->Get_name();
    for (int i=1;i<=d;i++){
        Trolls[i]->Set_x(troll[i][1]);
        Trolls[i]->Set_y(troll[i][2]);
    }
}
