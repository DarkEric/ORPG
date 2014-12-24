#include <iostream>
#include <fstream>
#include "QNPC.h"
#include <time.h>
#include <stdlib.h>
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
void QNPC::Set_Id(int n){
    Id = n;
}
int QNPC::Get_Id(){
    return Id;
}
bool QNPC::Dialog(int n){


}
