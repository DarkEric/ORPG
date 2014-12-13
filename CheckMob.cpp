#include "CheckMob.h"
int FindQuest(int x,int y,QNPC* Quest,int q){

    for (int i=1;i<=q;i++)
       if (x==Quest[i].Get_x()&&y==Quest[i].Get_y())return i;
}
int FindBum(int x,int y,BUM* Bum,int q){

    for (int i=1;i<=q;i++)
       if (x==Bum[i].Get_x()&&y==Bum[i].Get_y())return i;
}
