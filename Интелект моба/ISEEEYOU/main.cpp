#include <iostream>

using namespace std;

int next_x=0; // первый шаг
int next_y=0;
int next1_x=0; // последний шаг
int next1_y=0;

 bool Visible(Monstr mob,char** Field ){
      next_x=0; // первый шаг
      next_y=0;
      next1_x=0; // последний шаг
      next1_y=0;
     int flag=0;
     int n, m;
     int ih=x;
     int jh=y;
     int im=mob.Get_x();
     int jm=mob.Get_y();

         if (ih == im){
             if (jh > jm){
                 n = jh;
                 m = jm;
             }
             else{
                 n = jm;
                 m = jh;
             }
             for (int w = m + 1; w < n; w++){
                 if (Field[ih][w] != ' '){
                     next_x=0;
                     next_y=0;
                     return 0;
                 }
                 if (!flag){
                     next_x=ih;
                     next_y=w;
                     flag=1;
                 }
                 next1_x=ih;
                 next1_y=w;
             }
         }
         if (jh == jm){
             if (ih > im){
                 n = ih;
                 m = im;
             }
             else{
                 n = im;
                 m = ih;
             }
             for (int w = m + 1; w < n; w++){
                 if(Field[w][jw]!=' '){
                     next_x=0;
                     next_y=0;
                 }
                 if(!falg){
                     next_x=w;
                     next_y=jh;
                 }
                 next1_x=w;
                 next1_y=jh;
             }
         }

         if ((ih < im && jh > jm) || (ih > im && jh < jm)){
             int mini, minj, maxi, maxj;
             if (ih < im){
                 n = im - ih - 1;
                 m = jh - jm - 1;
                 i = ih + 1;
                 j = jh - 1;
                 mini = ih;
                 minj = jm;
                 maxi = im;
                 maxj = jh;
             }
             else {
                 n = ih - im - 1;
                 m = jm - jh - 1;
                 i = im + 1;
                 j = jm - 1;
                 mini = im;
                 minj = jh;
                 maxi = ih;
                 maxj = jm;
             }
             if (n < m) {
                 if (n == 0){
                     for (int w = minj + 1; w <= maxj / 2 + 1; w++){
                         if (Field[mini+1][w]!=' '){
                             next_x=0;
                             next_y=0;
                             return 0;
                         }
                         if(!falg){
                             next_x=mini+1;
                             next_y=w;
                         }
                         next1_x=mini+1;
                         next1_y=w;
                     }
                     for (int w = maxj / 2 + 1; w < maxj; w++){
                         if (Field[mini][w]!=' '){
                             next_x=0;
                             next_y=0;
                             return 0;
                         }
                         if(!falg){
                             next_x=mini;
                             next_y=w;
                         }
                         next1_x=mini;
                         next1_y=w;
                     }
                 }
                 else{
                     k = m / n;
                     kk = m - k*n;
                     while ((i < maxi) || (j > minj)){
                         if (Field[i][j+1]!=' '){
                             next_x=0;
                             newt_y=0;
                             return 0;
                         }
                         if(!falg){
                             next_x=i;
                             next_y=j+1;
                         }
                         next1_x=i;
                         next1_y=j+1;
                         for (int w = 1; w <= k; w++){
                             if(Field[i][j]!=' '){
                                 next_x=0;
                                 newt_y=0;
                                 return 0;
                             }
                             next1_x=i;
                             next1_y=j--;
                         }
                         if (i - mini <= kk / 2){
                             if(Field[i][j]!=' '){
                                 next_x=0;
                                 newt_y=0;
                                 return 0;
                             }
                             next1_x=i;
                             next1_y=j--;
                         }
                         if (maxi - i - mini < kk / 2 - 1){
                             if(Field[i][j]!=' '){
                                 next_x=0;
                                 newt_y=0;
                                 return 0;
                             }
                             next1_x=i;
                             next1_y=j--;
                         }

                         if (j == m / 2 + 2 + mini){
                             if (kk % 2 != 0){
                                 if(Field[i][j]!=' '){
                                     next_x=0;
                                     newt_y=0;
                                     return 0;
                                 }
                                 next1_x=i;
                                 next1_y=j--;
                             }
                         }
                         i++;
                     }
                     if(Field[i][j+1]!=' '){
                         next_x=0;
                         newt_y=0;
                         return 0;
                     }
                     next1_x=i;
                     next1_y=j+1;
                 }
             }
             else {
                 if (m == 0){
                     for (int w = mini + 1; w <= maxi / 2 + 1; w++){
                         if (Field[w][minj+1]!=' '){
                             next_x=0;
                             next_y=0;
                             return 0;
                         }
                         if(!falg){
                             next_x=w;
                             next_y=minj+1;
                         }
                         next1_x=w;
                         next1_y=minj+1;
                     }
                     for (int w = maxi / 2 + 1; w < maxi; w++){
                         l[w][minj] = 1;
                         if (Field[w][minj]!=' '){
                             next_x=0;
                             next_y=0;
                             return 0;
                         }
                         if(!falg){
                             next_x=w;
                             next_y=minj;
                         }
                         next1_x=w;
                         next1_y=minj;
                     }
                 }
                 else{
                     k = n / m;
                     kk = n - k*m;
                     while ((i < maxi) || (j > minj)){
                         if (Field[i-1][j]!=' '){
                             next_x=0;
                             newt_y=0;
                             return 0;
                         }
                         if(!falg){
                             next_x=i-1;
                             next_y=j;
                         }
                         next1_x=i-1;
                         next1_y=j;
                         for (int w = 1; w <= k; w++){
                             if(Field[i][j]!=' '){
                                 next_x=0;
                                 newt_y=0;
                                 return 0;
                             }
                             next1_x=i++;
                             next1_y=j;
                         }
                         if (j - minj <= kk / 2){
                             if(Field[i][j]!=' '){
                                 next_x=0;
                                 newt_y=0;
                                 return 0;
                             }
                             next1_x=i++;
                             next1_y=j;
                         }
                         if (maxj - j - minj < kk / 2 - 1){
                             if(Field[i][j]!=' '){
                                 next_x=0;
                                 newt_y=0;
                                 return 0;
                             }
                             next1_x=i++;
                             next1_y=j;
                         }

                         if (i == n / 2 + 2 + minj){
                             if (kk % 2 != 0){
                                 if(Field[i][j]!=' '){
                                     next_x=0;
                                     newt_y=0;
                                     return 0;
                                 }
                                 next1_x=i++;
                                 next1_y=j;
                             }
                         }
                         j--;
                     }
                     if(Field[i-1][j]!=' '){
                         next_x=0;
                         newt_y=0;
                         return 0;
                     }
                     next1_x=i-1;
                     next1_y=j;
                 }
             }
         }




         if ((ih < im && jh<jm) || (ih > im && jh > jm)){
             int mini,minj,maxi,maxj;
             if (ih < im){
                 n = im - ih - 1;
                 m = jm - jh - 1;
                 i = ih + 1;
                 j = jh + 1;
                 mini = ih;
                 minj = jh;
                 maxi = im;
                 maxj = jm;
             }
             else {
                 n = ih - im - 1;
                 m = jh - jm - 1;
                 i = im + 1;
                 j = jm + 1;
                 mini = im;
                 minj = jm;
                 maxi = ih;
                 maxj = jh;
             }
                 if (n < m) {
                     if (n == 0){
                         for (int w = minj + 1; w <= maxj / 2+1; w++){
                             if (Field[mini][w]!=' '){
                                 next_x=0;
                                 next_y=0;
                                 return 0;
                             }
                             if(!falg){
                                 next_x=mini;
                                 next_y=w;
                             }
                             next1_x=mini;
                             next1_y=w;
                         }
                         for (int w = maxj/2+1; w < maxj; w++){
                             l[mini+1][w] = 1;
                             if (Field[mini+1][w]!=' '){
                                 next_x=0;
                                 next_y=0;
                                 return 0;
                             }
                             if(!falg){
                                 next_x=mini+1;
                                 next_y=w;
                             }
                             next1_x=mini+1;
                             next1_y=w;
                         }
                     }
                     else{
                         if (Field[i-1][j]!=' '){
                             next_x=0;
                             newt_y=0;
                             return 0;
                         }
                         if(!falg){
                             next_x=i-1;
                             next_y=j;
                         }
                         next1_x=i-1;
                         next1_y=j;

                         k = m / n;
                         kk = m - k*n;
                         while ((i < maxi) || (j < maxj)){
                             for (int w = 1; w <= k; w++){
                                 if (Field[i][j]!=' '){
                                     next_x=0;
                                     newt_y=0;
                                     return 0;
                                 }
                                 next1_x=i;
                                 next1_y=j++;
                             }
                             if (i - mini <= kk / 2){
                                 if (Field[i][j]!=' '){
                                     next_x=0;
                                     newt_y=0;
                                     return 0;
                                 }
                                 next1_x=i;
                                 next1_y=j++;
                             }
                             if (maxi - i - mini < kk / 2 - 1){
                                 if (Field[i][j]!=' '){
                                     next_x=0;
                                     newt_y=0;
                                     return 0;
                                 }
                                 next1_x=i;
                                 next1_y=j++;
                             }

                             if (j == m / 2 + 2 + mini){
                                 if (kk % 2 != 0){
                                     if (Field[i][j]!=' '){
                                         next_x=0;
                                         newt_y=0;
                                         return 0;
                                     }
                                     next1_x=i;
                                     next1_y=j++;
                                 }
                             }
                             l[i + 1][j - 1] = 1;
                             if (Field[i+1][j-1]!=' '){
                                 next_x=0;
                                 newt_y=0;
                                 return 0;
                             }
                             next1_x=i+1;
                             next1_y=j-1;
                             i++;
                         }
                     }
                 }
                 else {
                     if (m == 0){
                         for (int w = mini + 1; w <= maxi / 2 + 1; w++){
                             if (Field[w][minj]!=' '){
                                 next_x=0;
                                 next_y=0;
                                 return 0;
                             }
                             if(!falg){
                                 next_x=w;
                                 next_y=minj;
                             }
                             next1_x=w;
                             next1_y=minj;
                         }
                         for (int w = maxi / 2 + 1; w < maxi; w++){
                             if (Field[w][minj+1]!=' '){
                                 next_x=0;
                                 next_y=0;
                                 return 0;
                             }
                             if(!falg){
                                 next_x=w;
                                 next_y=minj+1;
                             }
                             next1_x=w;
                             next1_y=minj+1;
                         }
                     }
                     else {
                         if (Field[i][j-1]!=' '){
                             next_x=0;
                             newt_y=0;
                             return 0;
                         }
                         if(!falg){
                             next_x=i;
                             next_y=j-1;
                         }
                         next1_x=i;
                         next1_y=j-1;

                         k = n / m;
                         kk = n - k*m;
                         while ((i < maxi) || (j < maxj)){
                             for (int w = 1; w <= k; w++){
                                 if (Field[i][j]!=' '){
                                     next_x=0;
                                     newt_y=0;
                                     return 0;
                                 }
                                 next1_x=i++;
                                 next1_y=j;
                             }
                             if (j - minj <= kk / 2){
                                 if (Field[i][j]!=' '){
                                     next_x=0;
                                     newt_y=0;
                                     return 0;
                                 }
                                 next1_x=i++;
                                 next1_y=j;
                             }
                             if (maxj - j - minj < kk / 2 - 1){
                                 if (Field[i][j]!=' '){
                                     next_x=0;
                                     newt_y=0;
                                     return 0;
                                 }
                                 next1_x=i++;
                                 next1_y=j;
                             }


                             if (i == n / 2 + 2 + minj){
                                 if (kk % 2 != 0){
                                     if (Field[i][j]!=' '){
                                         next_x=0;
                                         newt_y=0;
                                         return 0;
                                     }
                                     next1_x=i++;
                                     next1_y=j;
                                 }
                             }
                             l[i - 1][j + 1] = 1;
                             if (Field[i-1][j+1]!=' '){
                                 next_x=0;
                                 newt_y=0;
                                 return 0;
                             }
                             next1_x=i-1;
                             next1_y=j+1;
                             j++;
                         }
                     }
                 }
             }

     return 1;

 }


 void SearchMob(Monstr* mob ,int n,char** Field){
     for(int i=1;i<=n;i++){
         if ((mob[i].Get_x()-x)*(mob[i].Get_x()-x)+(mob[i].Get_y()-y)*(mob[i].Get_y()-y) <=10){
              if (Visible(mob[i],Field)){
                  if (!mob[i].Get_heroin()) mob[i].Change_heroin();// героин = 1
                  if ((abs(next_x-mod[i].Get_x())<=1)&&(abs(next_y-mod[i].Get_y())<=1)){
                      mob[i].Set_next_step(next_x,next_y);
                  }
                  if ((abs(next1_x-mod[i].Get_x())<=1)&&(abs(next1_y-mod[i].Get_y())<=1)){
                      mob[i].Set_next_step(next1_x,next1_y);
                  }
              }
         }
         else {
             if(mob[i].Get_heroin()){
                 mob[i].Change_heroin(); // героин =0;
             }
     }


 }


int main()
{



    cout << "Hello World!" << endl;


    return 0;
}

