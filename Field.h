
//#include <stdlib.h>
//#include <stdio.h>
//#include <iostream>
//#include <conio.h>
#include <string.h>
#include <Consol.h>
char Field[50][215];
void WriteField(int x, int y)
{
    for (int j = 1; j <= 73; j++)printf("*");
	printf("\n");

    for (int i = x - 8; i <= x + 8; i++){
		printf("*");
        for (int j = y - 35; j <= y + 35; j++)
            if (Field[i][j]=='H'){
                SetConsoleText(4);
                printf("%c", Field[i][j]);
                SetConsoleText(3);
            }else{
            printf("%c", Field[i][j]);
            }
        printf("*\n");
	}
	for (int j = 1; j <= 73; j++)printf("*");
	printf("\n");
	return;
}
void ReadField(std::string TownMap){
    freopen(TownMap.c_str(),"r",stdin);
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        //Field[i]=new char[m+2];
        for (int j=1;j<=m;j++)Field[i][j]=' ';
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++){
            char c;
            scanf("%c",&c);
            if (c=='\n')Field[i][j]=' ';
            else Field[i][j]=c;
        }
    system("cls");
}
void MoveHero(std::string TownMap){
    ReadField(TownMap);
    system("mode con cols=100 lines=30");
    int x = 14, y = 12;
    Field[x][y] = 'H';
    WriteField(x, y);
	fclose(stdin);
	char c = getch();
	while (c != 27){
		if (c == 72){
            if (x - 1 > 1 && Field[x - 1][y] != '#'){
				system("cls");
                Field[x--][y] = ' ';
                Field[x][y] = 'H';
                WriteField(x, y);
			}
		}
		else if (c == 75){
            if (y - 1 > 1 && Field[x][y - 1] != '#'){
				system("cls");
                Field[x][y--] = ' ';
                Field[x][y] = 'H';
                WriteField(x, y);
			}
		}
		else if (c == 80){
            if (x + 1 > 1 && Field[x + 1][y] != '#'){
				system("cls");
                Field[x++][y] = ' ';
                Field[x][y] = 'H';
                WriteField(x, y);
			}
		}
		else if (c == 77){
            if (y + 1 > 1 && Field[x][y + 1] != '#'){
				system("cls");
                Field[x][y++] = ' ';
                Field[x][y] = 'H';
                WriteField(x, y);
			}
		}
		c = getch();
	}
}
