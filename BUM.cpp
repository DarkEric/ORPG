
#include "BUM.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
BUM::BUM(){
    x=0;
    y=0;

}
BUM::~BUM(){

}


void BUM::Dialog(int i){
    i=1;
	switch (i){
    case 1:{
        std::cout << "?ÿð¸øñþ ?ðü,¢ªþ ÷ð?ø?ðõªõ ýð¸!";
		_getch();
		break;
	}
	case 2:{
		//ò?òþô ¯¨ð÷
		std::cout << "?þ°ðûøü?";
		_getch();
		break;
	}
	case 3:{
		//ò?òþô ¯¨ð÷
		std::cout << "?¨þòðûøòðù!";
		_getch();
		break;
	}
	default:break;
	}
}
void BUM::Set_x(int n){
	x = n;
}
int BUM::Get_x(){
	return x;
}
void BUM::Set_y(int n){
	y = n;
}
int BUM::Get_y(){
	return y;
}
