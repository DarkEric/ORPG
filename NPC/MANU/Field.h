#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>

char mas[60][302];
//выввод карты
void WriteField(int x, int y)
{
	int a = 0, b = 0;
	for (int j = 1; j <= 73; j++)printf("*");
	printf("\n");

	for (int i = x - 8; i <= x + 8; i++){
		printf("*");
		for (int j = y - 35; j <= y + 35; j++)
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
		int j = 1;

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
