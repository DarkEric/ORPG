#include <string.h>
#include <stdlib.h>
#include <iostream>

using std::string;

Controller::Controller()
{
    Flag=0;
    Maplen_x=0;
    Maplen_y=0;
}

void Controller::WriteMap(int x,int y){

    for (int j = 1; j <= 119; j++)printf("*");
    printf("\n");
    for (int i=x-8;i<=x+30;i++){
        printf("*");
        for (int j=y-8;j+110;j++)
            if (Field[i][j]=='H'){
                SetConsoleText(4);
                printf("%c", Field[i][j]);
                SetConsoleText(3);
            }else{
            printf("%c", Field[i][j]);
            }
        printf("*\n");
    }
    for (int j = 1; j <= 119; j++)printf("*");
    printf("\n");
    return;
}

void Controller::ReadMap(string Mname){
    freopen(Mname.c_str,"r",stdin);
    scanf("%d %d",&Maplen_x,&Maplen_y);

    for (int i=1;i<=Maplen_x;i++)
        for(int j=1;j<=Maplen_y;j++)
            scanf("%c",&Map[i][j]);
    fclose(stdin);

}

static void Controller::GlobalMap(){


}

static void Controller::FieldMap(){

}
static int Controller::PositionHero(){

}
