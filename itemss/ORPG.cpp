
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "items.h"
#include <conio.h>
#include "Weapon.h"
#include "DblHWeapon.h"
#include "Leather.h"

using namespace std;

int main()
{

	Weapon b("lyk", "2H", 50);
	items* a=new Weapon("lyk", "2H", 50);
	
	cout << a->Get_name() << " " << a->Get_type()<< " " << a->Attack();

	_getch();
	return 0;
}

