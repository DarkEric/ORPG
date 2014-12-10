#include "stdafx.h"
#include "QNPC.h"
#include <iostream>
#include <fstream>
std::ifstream in("q1.txt");
int main()
{
	setlocale(LC_ALL, "ru");
	char** mas=new char*[4];
	for (int i = 1; i <= 4; i++)mas[i] = new char[30];
	int n;
	in >> n;
	in.getline(mas[1], 29);
	in.getline(mas[1], 29);
	in.getline(mas[2], 29);
	in.getline(mas[3], 29);
	QNPC a;
	a.Set_x(3);
	a.Set_y(4);
	if (a.Dialog(mas))std::cout<<"согласен!\n";
	else std::cout << "несогласен!\n";
	system("pause");
	return 0;
}

