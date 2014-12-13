 
#include "QNPC.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
QNPC::QNPC(){
    status=false;
    x=0;
    y=0;
}
QNPC::~QNPC(){
}
void QNPC::Set_x(int n){
    x = n;
}
int QNPC::Get_x(){
    return x;
}
void QNPC::Set_y(int n){
    y = n;
}
int QNPC::Get_y(){
    return y;
}
bool QNPC::Dialog(int n){


    char file[20]={'q','u','e','s','t',n+48,'.','t','x','t',0};
//    if (n==1) file="quest1.txt";
//    else if (n==2)file="quest2.txt";
    freopen(file,"r",stdin);
    char mas[4][30];
    for (int i=1;i<=4;i++) gets(mas[i]);
    //for (int i=1;i<=4;i++) std::cout<<file;

    if (status==false){
        status=true;
        bool a;
        std::cout << mas[1] << std::endl;
        for (int j = 2; j <= 3; j++){
            std::cout << "\t" << mas[j] << std::endl;
        }
        char f =_getch();
        while (f == '1' || f == '2'){
            if (f == '1'){
                a = true;
                break;
            }
            if (f == '2'){
                a = false;
                break;
            }
        }
            return a;
    }else{
        std::cout<<mas[4];
        _getch();
    }


}
