#ifndef QNPC_H
#define QNPC_H
#include "NPC.h"
#include "hero.h"
#include <iostream>

//============================
struct Phrase{
    int st;
    std::string s;
};
//============================

class QNPC:public NPC
{
public:
    QNPC();
    QNPC(std::string filename){
        Set_filename(filename);
    }
    void Set_filename(std::string n){n.copy(this->filename,n.length());}
    std::string Get_filename()const{return filename;}
    void Dialog(Hero* character);
    void Set_x(int n);
    int Get_x();
    void Set_y(int n);
    int Get_y();
    void Set_Id(int n);
    int Get_Id();
    void ReadDialog();
    ~QNPC();
private:
    int Id;
    int x;
    int y;
    char filename[20];
//============================
    Phrase dial[6][20];
//============================
    bool status;
};

#endif
