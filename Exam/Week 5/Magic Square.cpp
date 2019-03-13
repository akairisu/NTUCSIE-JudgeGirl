#include<stdio.h>
 
int square[1000][1000];
 
int main(void)
{
    int n , k ;
    scanf("%d%d" , &n , &k);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            square[i][j] = 0;
        }
    }
    int x , y;
    scanf("%d%d" , &x , &y);
    square[x][y] = k;
    int tempx = x;
    int tempy = y;
    for(int i = k - 1; i > 0; i--){
        if(y - 1 >= 0 && x + 1 < n - 1  && square[x+1][y-1] == 0){
            y = y - 1;
            x = x + 1;
            square[x][y] = i;
        }
        else if(y - 1 >= 0 && x + 1 < n - 1 && square[x-1][y+1] != 0){
            if(x == 0){
                x = n - 1;
            }
            else x = x - 1;
            square[x][y] = i;
        }
        else {
            if(y - 1 == -1){
                y = n - 1; 
            }
                else y -= 1;
            if(x + 1 == n){
                x = 0;
            }
                else x += 1;
            if(square[x][y] != 0){
                x -= 1;
            }
            square[x][y] = i;
        }
    }
    x = tempx;
    y = tempy;
    for(int i = k + 1; i <= n * n; i++){
        if(y + 1 < n && x - 1 > -1  && square[x-1][y+1] == 0){
            y = y + 1;
            x = x - 1;
            square[x][y] = i;
        }
        else if(y + 1 < n && x - 1 >= 0 && square[x-1][y+1] != 0){
            if(x == n - 1){
                x = 0;
            }
            else x = x + 1;
            square[x][y] = i;
        }
        else {
            tempx = x;
            tempy = y;
            if(y + 1 == n){
                y = 0;
            }
                else y += 1;
            if(x - 1 == -1){
                x = n - 1;
            }
                else x -= 1;
            if(square[x][y] != 0){
                x = tempx + 1;
                y = tempy;
            }
            square[x][y] = i;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            printf("%d" , square[i][j]);
            if(j != n - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
 }

