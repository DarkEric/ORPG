// RPG.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
void SetConsoleFont(int m)
{
	typedef BOOL(WINAPI *SETCONSOLEFONT)(HANDLE, DWORD);
	SETCONSOLEFONT SetConsoleFont;
	HMODULE hmod = GetModuleHandleA("KERNEL32.DLL");
	SetConsoleFont = (SETCONSOLEFONT)GetProcAddress(hmod, "SetConsoleFont");
	if (!SetConsoleFont)  exit(1);//íóæíî ïîäîáðàòü ðàçìåð øðèôòà - Win7x64 = 9
	SetConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), m);
}
void SetConsoleText(int m){
	if (m == 1){
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	else
		if (m == 2){
		HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hwnd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		}
		else {
			HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hwnd, 0 | FOREGROUND_INTENSITY);
		}

}
char mas[60][202];
void WriteField(int x, int y)
{
	int a, b;
	for (int j = 1; j <= 70; j++)printf("*");
	printf("\n");
	if (x - 7 < 1)a = 1;
	else if (x + 7 > 25)a = 7;
	else a = x - 7;
	if (y - 5 < 1)b = 1;
	else
		if (y + 38 > 160)b = 90;
		else b = y - 5;

		for (int i = a; i <= 14; i++){
			std::cout << "*";
			for (int j = b; j <= 68; j++)
				std::cout << mas[i][j];
			std::cout << "*\n";
		}

		for (int j = 1; j <= 70; j++)printf("*");
		printf("\n");
		return;
}
void ReadField(){
	freopen("1.txt", "r", stdin);
	for (int i = 1; i <= 25; i++){
		int j = 1;

		for (int j = 1; j <= 152; j++)
			scanf("%c", &mas[i][j]);
		char c;
		scanf("%c", &c);
		while (c != '\n')
			scanf("%c", &c);
	}

	int x = 2, y = 2;
	mas[x][y] = 'S';
	WriteField(x, y);
	fclose(stdin);
	char c = getch();
	while (c != 27){
		if (c == 72){
			system("cls");
			if (x - 1 > 1 && mas[x - 1][y] != '#'){
				mas[x--][y] = ' ';
				mas[x][y] = 'S';
				WriteField(x, y);
			}
		}
		else if (c == 75){
			system("cls");
			if (y - 1 > 1 && mas[x][y - 1] != '#'){
				mas[x][y--] = ' ';
				mas[x][y] = 'S';
				WriteField(x, y);
			}
		}
		else if (c == 80){
			system("cls");
			if (x + 1 > 1 && mas[x + 1][y] != '#'){
				mas[x++][y] = ' ';
				mas[x][y] = 'S';
				WriteField(x, y);
			}
		}
		else if (c == 77){
			system("cls");
			if (y + 1 > 1 && mas[x][y + 1] != '#'){
				mas[x][y++] = ' ';
				mas[x][y] = 'S';
				WriteField(x, y);
			}
		}
		c = getch();
	}


}
void MENU(){
	for (int i = 1; i <= 5; i++)std::cout << "\n";
	SetConsoleFont(8);
	SetConsoleText(1);
	std::cout << "\tNew game\n";
	SetConsoleText(2);
	std::cout << "\tLoad game\n";
	std::cout << "\tExit\n";
	int f = 1, ff = 0;
	int c = _getch();
	while (ff == 0){
		switch (c){
		case 72:{
			if (f == 2){
				system("cls");
				for (int i = 1; i <= 5; i++)std::cout << "\n";
				SetConsoleText(1);
				std::cout << "\tNew game\n";
				SetConsoleText(2);
				std::cout << "\tLoad game\n";
				std::cout << "\tExit\n";
				f = 1;
			}
			else
				if (f == 3){
				system("cls");
				for (int i = 1; i <= 5; i++)std::cout << "\n";
				SetConsoleText(2);
				std::cout << "\tNew game\n";
				SetConsoleText(1);
				std::cout << "\tLoad game\n";
				SetConsoleText(2);
				std::cout << "\tExit\n";
				f = 2;
				}
			break;
		}
		case 80:{
			if (f == 1){
				system("cls");
				for (int i = 1; i <= 5; i++)std::cout << "\n";
				SetConsoleText(2);
				std::cout << "\tNew game\n";
				SetConsoleText(1);
				std::cout << "\tLoad game\n";
				SetConsoleText(2);
				std::cout << "\tExit\n";
				f = 2;
			}
			else
				if (f == 2){
				system("cls");
				for (int i = 1; i <= 5; i++)std::cout << "\n";
				SetConsoleText(2);
				std::cout << "\tNew game\n";
				std::cout << "\tLoad game\n";
				SetConsoleText(1);
				std::cout << "\tExit\n";
				f = 3;
				}
			break;
		}
		case 13:{
			SetConsoleText(5);
			//system("cls");
			SetConsoleFont(6);
			system("mode con cols=80 lines=30");
			if (f == 1)ReadField();
			ff = 1;
			break; }
		default:break;
		}
		c = _getch();
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	system("mode con cols=60 lines=30");
	MENU();
	return 0;
}
/*
#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>

char mas[60][202];
void ReadField(){
for (int i = 1; i <= 25; i++){
int j = 1;

for (int j = 1; j <= 152;j++)
scanf("%c", &mas[i][j]);
char c;
scanf("%c", &c);
while (c!='\n')
scanf("%c", &c);
}

}
void WriteField(int x,int y)
{
int a, b;
for (int j = 1; j <= 70; j++)printf("*");
printf("\n");
if (x - 7 < 1)a = 1;
else if (x + 7 > 25)a = 7;
else a = x - 7;
if (y - 5 < 1)b = 1;
else
if (y + 38 > 160)b = 90;
else b = y - 5;

for (int i = a; i <= 14; i++){
std::cout << "*";
for (int j = b; j <= 68; j++)
std::cout << mas[i][j];
std::cout << "*\n";
}

for (int j = 1; j <= 70; j++)printf("*");
printf("\n");



/*for (int j = 1; j <= 77; j++)printf("*");
printf("\n");
int l = 20,ll=76;
l++; ll++;

for (int i = x-10; i <= l; i++){
for (int j = y-10; j <= ll; j++)
printf("%c", mas[i][j]);
printf("\n");
}
for (int j = 1; j <= 78; j++)printf("*");
printf("\n");*/
/*return;
}
int main(){
freopen("1.txt", "r", stdin);
//freopen("0.txt", "w", stdout);
ReadField();

int x = 2, y = 2;
mas[x][y] = 'S';
WriteField(x,y);
fclose(stdin);
char c = getch();
while (c!=27){
system("cls");
if (c == 72){
if (x - 1 > 1 && mas[x - 1][y] != '#'){
mas[x--][y] = ' ';
mas[x][y] = 'S';
WriteField(x, y);
}
}
else if (c == 75){
if (y - 1 > 1 && mas[x ][y- 1] != '#'){
mas[x][y--] = ' ';
mas[x][y] = 'S';
WriteField(x, y);
}
}else if(c == 80){
if (x + 1 > 1 && mas[x + 1][y] != '#'){
mas[x++][y] = ' ';
mas[x][y] = 'S';
WriteField(x, y);
}
}
else if (c == 77){
if (y+1 > 1 && mas[x ][y+1] != '#'){
mas[x][y++] = ' ';
mas[x][y] = 'S';
WriteField(x, y);
}
}
c = getch();
}

_gettch();
return 0;
}
*/