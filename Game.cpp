#include "Game.h"

void Game(Hero* Player){
   Controller Map[1];
   //создание карты 1-го леса
   Map[0].ReadMap("LES1.txt");
   Map[0].WriteMap();

   int i=Map[0].Get_PositionHero_x(),
       j=Map[0].Get_PositionHero_y();

   char c=_getch();
   while(c!=27){
       if (c==72||c==75||c==80||c==77){
           char ch;
           if (c==72)ch=Map[0].Get(i-1,j);
           else if (c==75)ch=Map[0].Get(i,j-1);
           else if (c==80)ch=Map[0].Get(i+1,j);
           else if (c==77)ch=Map[0].Get(i,j+1);
           int Num;
           switch(ch){
           case ' ':
               if (c==72)Map[0].AmendMap(1,i,j,i-1,j);
               else if (c==75)Map[0].AmendMap(1,i,j,i,j-1);
               else if (c==80)Map[0].AmendMap(1,i,j,i+1,j);
               else if (c==77)Map[0].AmendMap(1,i,j,i,j+1);
               Map[0].WriteMap();
               break;
           case 'C':
               if (c==72){
                   Num=Map[0].FiendCreate(i-1,j);
                   Map[0].AmendMap(2,i,j,i-1,j);
               }
               else if (c==75){
                   Num=Map[0].FiendCreate(i,j-1);
                   Map[0].AmendMap(2,i,j,i,j-1);
               }
               else if (c==80){
                   Num=Map[0].FiendCreate(i+1,j);
                   Map[0].AmendMap(2,i,j,i+1,j);
               }
               else if (c==77){
                   Num=Map[0].FiendCreate(i,j+1);
                   Map[0].AmendMap(2,i,j,i,j+1);
               }
               Map[0].TalkCreate(1,Num,Player);
               //проиграл или выиграл
               Map[0].WriteMap();
               break;
           case 'Q':
               if (c==72)Num=Map[0].FiendCreate(i-1,j);
               else if (c==75)Num=Map[0].FiendCreate(i,j-1);
               else if (c==80)Num=Map[0].FiendCreate(i+1,j);
               else if (c==77)Num=Map[0].FiendCreate(i,j+1);
               Map[0].TalkCreate(2,Num,Player);
               //проиграл или выиграл
               Map[0].WriteMap();
               break;
           case 'T':
               if (c==72)Num=Map[0].FiendCreate(i-1,j);
               else if (c==75)Num=Map[0].FiendCreate(i,j-1);
               else if (c==80)Num=Map[0].FiendCreate(i+1,j);
               else if (c==77)Num=Map[0].FiendCreate(i,j+1);
               Map[0].TalkCreate(3,Num,Player);
               break;
           case 'D':

               break;
           default:
               break;
           }

       }
        c=_getch();
   }
}
