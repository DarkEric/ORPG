#include "Game.h"

void Game(Hero* Player){
   Controller* Map[10];
   int i=15;int j=15;
   Map[1]->ReadMap("LES1.txt");
   Map[1]->WriteMap(i,j);

   char c=_getch();
   while(c!=27){
       if (c==72||c==75||c==80||c==77){
           char ch;
           if (c==72)ch=Map[1]->Get(i-1,j);
           else if (c==75)ch=Map[1]->Get(i,j-1);
           else if (c==80)ch=Map[1]->Get(i+1,j);
           else if (c==77)ch=Map[1]->Get(i,j+1);
           int Num;
           switch(ch){
           case ' ':
               Map[1]->AmendMap(1,i,j,i-1,j);

               break;
           case 'C':
               Num=Map[1]->FiendCreate(i,j-1);
               Map[1]->TalkCreate(1,Num,Player);
               Map[1]->AmendMap(1,i,j,i-1,j-1);
               Map[1]->WriteMap(i,j-1);
               break;
           case 'Q':
               Num=Map[1]->FiendCreate(i,j);
               Map[1]->TalkCreate(2,Num,Player);
               break;
           case 'T':
               Num=Map[1]->FiendCreate(i,j);
               Map[1]->TalkCreate(3,Num,Player);
               break;
           case 'D':

               break;
           default:
               break;
           }
           c=_getch();
       }

   }
}
