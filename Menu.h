 
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Field.h"

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
        else if (m==3){
			HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hwnd, 0 | FOREGROUND_INTENSITY);
        }else if(m==4){
            HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hwnd, FOREGROUND_RED|FOREGROUND_INTENSITY);
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
            SetConsoleText(3);
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
