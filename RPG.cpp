// RPG.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <stdlib.h>
#include <iostream>
char mas[52][202];
void ReadField(){
	for (int i = 1; i <= 50; i++)
		for (int j = 1; j <= 200;j++)
		scanf("%c", &mas[i][j]);
}
void WriteField(int x,int y){
	int k=76,k1=20;
	x = 1;
	if (y - 38 < 1){
		y = 1; 
	}
	else
	if (y + 38> k)y = k - 38-y;
	else y = y - 38;
	for (int j = 1; j <= 78; j++)printf("*");
	printf("\n");
	for (int i = x; i <= 21; i++){
		printf("*");
		for (int j = y; j <= 76; j++)
			printf("%c", mas[i][j]);
		printf("*\n");
	}
	for (int j = 1; j <= 78; j++)printf("*");
	printf("\n");
	return;
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
			}
		}
		else if (c == 75){
			if (y - 1 > 1 && mas[x ][y- 1] != '#'){
				mas[x][y--] = ' ';
				mas[x][y] = 'S';
			}
		}else if(c == 80){
			if (x + 1 > 1 && mas[x + 1][y] != '#'){
				mas[x++][y] = ' ';
				mas[x][y] = 'S';
			}
		}
		else if (c == 77){
			if (y+1 > 1 && mas[x ][y+1] != '#'){
				mas[x][y++] = ' ';
				mas[x][y] = 'S';
			}
		}
		WriteField(x, y);
		c = getch();		
	}


	_gettch();
	return 0;
}

