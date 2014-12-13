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
    ~QNPC();
private:
    int x;
    int y;
    bool status;
};

#endif
