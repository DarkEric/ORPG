#ifndef READDIALOG
#define READDIALOG
#include "Dialogq.h"
#include <iostream>
#include <fstream>

Dialog* readDialog(std::ifstream* in,int treeLevel){
    Dialog* Dia= new Dialog();
    do{
        int who;
        std::string replica;
        int IDq;
        int nIDq;
        int rIDq;
        int flag;
        in->ignore(1,':');
        in>>who;
        in->ignore(1,':');
        in->getline(replica,255,':');
        in->ignore(1,':');
        in>>IDq;
        in->ignore(1,':');
        in>>nIDq;
        in->ignore(1,':');
        in>>rIDq;
        in->ignore(1,':');
        in>>flag;
        switch (who) {
        case 0:
            Dia->Set_Npc(replica);
            Dia->Set_IDquest(IDq);

            break;
        default:
            break;
        }
    }while(treeLevel);
}



#endif // READDIALOG

