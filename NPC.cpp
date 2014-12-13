 
#include "NPC.h"


NPC::NPC(){
    x=0;
    y=0;
}
NPC::~NPC(){
}
void NPC::Dialog(){}
void NPC::Set_x(int n){
	x = n;
}
int NPC::Get_x(){
	return x;
}
void NPC::Set_y(int n){
	y = n;
}
int NPC::Get_y(){
	return y;
}
