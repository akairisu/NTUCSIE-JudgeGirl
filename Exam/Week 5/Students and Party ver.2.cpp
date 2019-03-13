#include<stdio.h>

int friends[32768][256];
int nowfriend[32768] = {0};
int invitation[32768] = {0};

int main(void)
{
	int N , e; 
	scanf("%d%d" , &N , &e);
	int x , y;
	for(int i = 0 ; i < e ; i++){
		scanf("%d%d" , &x , &y);
		friends[x][nowfriend[x]] = y;
		friends[y][nowfriend[y]] = x;
		nowfriend[x]++;
		nowfriend[y]++;
	}
	for(int i = 0 ; i < N ; i++){
		invitation[i] = 0;
	}
	int invitor;
	while(scanf("%d" , &invitor) != EOF){
		invitation[invitor] = 1;
		for(int i = 0 ; i < nowfriend[invitor] ; i++){
			invitation[friends[invitor][i]] = 1;
		} 
	}
	for(int i = 0 ; i < N ; i++){
		if(invitation[i] == 0){
			printf("%d\n" , i);
		}
	}
	return 0;
 }

