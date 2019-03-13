#include<stdio.h>

int main(void)
{
	int N , e;
	scanf("%d%d" , &N , &e);
	int friends[N][N];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			friends[i][j] = 0;
			if(i == j){
				friends[i][j] = 1;
			}
		}	
	}
	int k = 1;
	int x , y;
	while(k <= e){
		scanf("%d%d", &x , &y);
		friends[x][y] = 1;
		friends[y][x] = 1;
		k++;
	}
	int notinvited[N];
	for(int i = 0 ; i < N ; i++){
		notinvited[i] = 0;
	}
	int invitor;
	int count = 0;
	while(scanf("%d" , &invitor) != EOF){
		for(int i = 0 ; i < N ; i++){
			if(friends[invitor][i] == 0){
				notinvited[i]++;
			}
		}
		count++;
	}
	for(int i = 0 ; i < N ; i++){
		if(notinvited[i] == count){
			printf("%d\n" , i);
		}
	}
	return 0;
 }

