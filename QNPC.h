#ifndef QNPC_H
#define QNPC_H
#include "NPC.h"
class QNPC:public NPC
{
public:
    QNPC();
    bool Dialog(int n );
    void Set_x(int n);
    int Get_x();
    void Set_y(int n);
    int Get_y();
    void Set_Id(int n);
    int Get_Id();
    ~QNPC();
private:
    int Id;
    int x;
    int y;
    bool status;
};

#endif
