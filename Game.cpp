#include "Game.h"
Controller Map[2];

int MapChoice(int n){

}

void Game(Hero* Player,std::string MapName,int n){


   //создание карты 1-го леса
   Map[n].ReadMap(MapName);
   Map[n].WriteMap();

   int i=Map[n].Get_PositionHero_x(),
       j=Map[n].Get_PositionHero_y();
    int f=0;
   char c=_getch();
   while(c!=27){
       if (c==72||c==75||c==80||c==77){
           char ch;
           if (c==72)ch=Map[n].Get(i-1,j);
           else if (c==75)ch=Map[n].Get(i,j-1);
           else if (c==80)ch=Map[n].Get(i+1,j);
           else if (c==77)ch=Map[n].Get(i,j+1);
           int Num;
           switch(ch){
           case ' ':
               if (c==72)Map[n].AmendMap(1,i,j,i-1,j);
               else if (c==75)Map[n].AmendMap(1,i,j,i,j-1);
               else if (c==80)Map[n].AmendMap(1,i,j,i+1,j);
               else if (c==77)Map[n].AmendMap(1,i,j,i,j+1);
               Map[n].WriteMap();
               break;
           case 'C':
               if (c==72)Num=Map[n].FiendCreate(i-1,j,1);
               else if (c==75)Num=Map[n].FiendCreate(i,j-1,3);
               else if (c==80)Num=Map[n].FiendCreate(i+1,j,2);
               else if (c==77)Num=Map[n].FiendCreate(i,j+1,4);
               Map[n].TalkCreate(1,Num,Player);
               //проиграл или выиграл
               Map[n].WriteMap();
               break;
           case 'Q':
               if (c==72)Num=Map[n].FiendCreate(i-1,j,1);
               else if (c==75)Num=Map[n].FiendCreate(i,j-1,3);
               else if (c==80)Num=Map[n].FiendCreate(i+1,j,2);
               else if (c==77)Num=Map[n].FiendCreate(i,j+1,4);
               Map[n].TalkCreate(2,Num,Player);
               //проиграл или выиграл
               Map[n].WriteMap();
               break;
           case 'T':
               if (c==72)Num=Map[n].FiendCreate(i-1,j,1);
               else if (c==75)Num=Map[n].FiendCreate(i,j-1,3);
               else if (c==80)Num=Map[n].FiendCreate(i+1,j,2);
               else if (c==77)Num=Map[n].FiendCreate(i,j+1,4);
               Map[n].TalkCreate(3,Num,Player);
               break;
           case 'D':

               break;
           default:
               break;
           }

       }
       i=Map[n].Get_PositionHero_x();
       j=Map[n].Get_PositionHero_y();
       if (i==Map[n].Get_Exit_x()&&(j==Map[n].Get_Exit_y())&&f==1)
           Game(Player,Map[n].NextMap(),n+1);
       else if (i==Map[n].Get_Enter_x()&&(j==Map[n].Get_Enter_y())&&f==1)
           Game(Player,Map[n].BreakMap(),n-1);
       f=1;
        c=_getch();
   }
}
