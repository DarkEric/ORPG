
#include "BUM.h"
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>



void BUM::Dialog(/*��� ��*/){
	srand(time(0));
	int i = rand() % 4 + 1;
	switch (i){
	case 1:{
		//����� ����
		std::cout << "���� ��������?";
		_getch();
		break;
	}
	case 2:{
		//����� ����
		std::cout << "�������?";
		_getch();
		break;
	}
	case 3:{
		//����� ����
		std::cout << "����������!";
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
