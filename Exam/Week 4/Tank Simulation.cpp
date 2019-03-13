#include<stdio.h>

int main(void)
{
	int N , M , L , W ;
	scanf("%d%d%d%d" , &N , &M , &L , &W);
	int O;
	int a[N][M];
	int X , Y;
	X = Y = 0;
	scanf("%d" , &O);
	int x , y;
	int k;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			a[i][j] = 0;
		}
	} 
	for(int i = 0 ; i < O ; i++){
		scanf("%d%d" , &x , &y);
		a[y][x] = 2 ;
	}
	for(int i = 0 ; i < L ; i++){
		for(int j = 0; j < W ; j++){
			a[i][j] = 1;
		}
	}
	int move;
	while(scanf("%d" , &move) != EOF){
		switch(move){
			case 0:
				for(int i = 0 ; i < N ; i++){
					for(int j = 0 ; j < M ; j++){
					printf("%d" , a[i][j]);
					}
					printf("\n");
				}
			break;
			case 1:
				k = 0;
				for(int i = Y ; i < (Y + L) && X + W < M ; i++){
				 	if(a[i][X + W] == 2){
				 		k++;
					}
				}
				if(k >= 2){
					continue;
				}
				else if(X + W >= M){
					continue;
				}
				else {
					for(int i = Y ; i < (Y + L) ; i++){
						a[i][X + W] = 1;
						a[i][X] = 0;
					}
					X++;
				}
			break;
			case 2:
				k = 0;
				for(int i = X ; i < (X + W) && Y + L < N ; i++){
				 	if(a[Y + L][i] == 2){
				 		k++;
					}
				}
				if(k >= 2){
					continue;
				}
				else if(Y + L >= N){
					continue;
				}
				else {
					for(int i = X ; i < (X + W) ; i++){
						a[Y + L][i] = 1;
						a[Y][i] = 0;
					}
					Y++;
				}
			break;
			case 3:
				k = 0;
				for(int i = Y ; i < (Y + L) && X - 1 >= 0 ; i++){
				 	if(a[i][X - 1] == 2){
				 		k++;
					}
				}
				if(k >= 2){
					continue;
				}
				else if(X - 1 < 0){
					continue;
				}
				else {
					for(int i = Y ; i < (Y + L) ; i++){
						a[i][X - 1] = 1;
						a[i][X + W - 1] = 0;
					}
					X--;
				}
			break;
			case 4:
				k = 0;
				for(int i = X ; i < (X + W) && Y - 1 >= 0 ; i++){
				 	if(a[Y - 1][i] == 2){
				 		k++;
					}
				}
				if(k >= 2){
					continue;
				}
				else if(Y - 1 < 0){
					continue;
				}
				else {
					for(int i = X ; i < (X + W) ; i++){
						a[Y - 1][i] = 1;
						a[Y + L - 1][i] = 0;
					}
					Y--;
				}
			break;
			case 5:
				k = 0;
				for(int i = Y + 1 ; (i <= (Y + L)) && ((X + W) < M) ; i++){
				 	if(a[i][X + W] == 2){
				 		k++;
					}
				}
				for(int i = X + 1 ; (i < (X + W)) && ((Y + L) < N) ; i++){
				 	if(a[Y + L][i] == 2){
				 		k++;
					}
				} 
				if(k >= 2){
					continue;
				}
				else if(((X + W)>= M) || ((Y + L)>= N)){
					continue;
				}
				else {
					for(int i = Y + 1 ; i <= (Y + L) ; i++){
						a[i][X + W] = 1;
					}
					for(int i = X + 1 ; i <= (X + W) ; i++){
						a[Y + L][i] = 1;
					}
					for(int i = X ; i < (X + W) ; i++){
						a[Y][i] = 0;
					}
					for(int i = Y ; i < (Y + L) ; i++){
						a[i][X] = 0;
					}
					X++;
					Y++;
				}
			break;
		}
 	} 
 	return 0;
}
