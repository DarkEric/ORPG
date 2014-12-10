#include "stdafx.h"
#include "QNPC.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

QNPC::QNPC()
{
}


QNPC::~QNPC()
{
}
bool QNPC::Dialog(char** mas){
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
}
