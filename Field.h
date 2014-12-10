
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <windows.h>


void SetConsoleText2(int m){
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
            SetConsoleTextAttribute(hwnd, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
        }

}
char mas[60][302];
//выввод карты
void WriteField(int x, int y)
{
    for (int j = 1; j <= 73; j++)printf("*");
	printf("\n");

	for (int i = x - 8; i <= x + 8; i++){
		printf("*");
		for (int j = y - 35; j <= y + 35; j++)
            if (mas[i][j]=='H'){
                SetConsoleText2(4);
                std::cout<<mas[i][j];
                //printf("%c", mas[i][j]);
                SetConsoleText2(3);
            }else
			printf("%c", mas[i][j]);
		printf("*\n");
	}
	for (int j = 1; j <= 73; j++)printf("*");
	printf("\n");
	return;
}

//считывание карты 
void ReadField(){
	freopen("1.txt", "r", stdin);
	for (int i = 1; i <= 40; i++){
		for (int j = 1; j <= 214; j++)
			scanf("%c", &mas[i][j]);
	}

	int x = 9, y = 11;
	mas[x][y] = 'H';
	WriteField(x, y);
	fclose(stdin);
	char c = getch();
	while (c != 27){
		if (c == 72){
			if (x - 1 > 1 && mas[x - 1][y] != '#'){
				system("cls");
				mas[x--][y] = ' ';
				mas[x][y] = 'H';
				WriteField(x, y);
			}
		}
		else if (c == 75){
			if (y - 1 > 1 && mas[x][y - 1] != '#'){
				system("cls");
				mas[x][y--] = ' ';
				mas[x][y] = 'H';
				WriteField(x, y);
			}
		}
		else if (c == 80){
			if (x + 1 > 1 && mas[x + 1][y] != '#'){
				system("cls");
				mas[x++][y] = ' ';
				mas[x][y] = 'H';
				WriteField(x, y);
			}
		}
		else if (c == 77){
			if (y + 1 > 1 && mas[x][y + 1] != '#'){
				system("cls");
				mas[x][y++] = ' ';
				mas[x][y] = 'H';
				WriteField(x, y);
			}
		}
		c = getch();
	}
}
