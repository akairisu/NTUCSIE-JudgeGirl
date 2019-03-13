#include<stdio.h>
 
int main(void)
{
    int N , M;
    scanf("%d%d" , &N , &M);
    int map[N][M];
    for(int i = 0 ; i < N ; i ++){
        for(int j = 0 ; j < M ; j++){
            map[i][j] = 0;
        }
    }
    int dx[4] = {1 , 0 , -1 , 0};
    int dy[4] = {0 , 1 , 0 , -1};
    int x , y , energy;
    scanf("%d%d%d" , &y , &x , &energy);
    map[y][x] = energy;
    int O;
    scanf("%d" , &O);
    int rox[O] , roy[O] , w[O];
    for(int i = 0 ; i < O ; i++){
        scanf("%d%d%d" , &roy[i] , &rox[i] , &w[i]);
        map[roy[i]][rox[i]] = w[i];
    }
    int dir;
    while(scanf("%d" , &dir) != EOF){
        if(dir == 0){
            for(int i = 0 ; i < N ; i ++){
                for(int j = 0 ; j < M ; j++){
                    printf("%d" , map[i][j]);
                    if(j!= M-1){
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        else if(x + dx[dir - 1] != -1 && x + dx[dir - 1] != M && y + dy[dir - 1] != -1 && y + dy[dir - 1] != N){
                if(map[y + dy[dir - 1]][x + dx[dir - 1]] == 0){
                    map[y][x] = 0;
                    x += dx[dir - 1];
                    y += dy[dir - 1];
                    map[y][x] = energy;
                }
                else{
                    int sum = map[y + dy[dir - 1]][x + dx[dir - 1]];
                    int k = 2;
                     while(y + k * dy[dir - 1] != -1 && y + k * dy[dir - 1] != N && x + k * dx[dir - 1] != -1 && x + k * dx[dir - 1] != M){
                         if(map[y + k * dy[dir - 1]][x + k * dx[dir - 1]] == 0){
                             break;
                         }
                         else sum += map[y + k * dy[dir - 1]][x + k * dx[dir - 1]];
                         k++;
                    }
                    if(y + k * dy[dir - 1] != -1 && y + k * dy[dir - 1] != N && x + k * dx[dir - 1] != -1 && x + k * dx[dir - 1] != M){
                        if(energy >= sum){
                            energy = energy - sum;
                            map[y][x] = 0;
                            for(int i = k ; i > 1; i--){
                                map[y + i * dy[dir - 1]][x + i * dx[dir - 1]] = map[y + (i - 1) * dy[dir - 1]][x + (i - 1) * dx[dir - 1]];
                            }
                            x += dx[dir - 1];
                            y += dy[dir - 1];
                            map[y][x] = energy;
                        }
                        else continue;
                    }
                }
            }
    }
    return 0;
}

