#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d" , &N);
	int a[3][3];
	int x , y;
	int k = 1;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			a[i][j] = 0;
		}
	}
	int j = 0;
	int w = 0;
	int i = 0;
	while(i < N){
		scanf("%d%d" , &x , &y);
		if (k % 2 == 1 && -1 < x < 3 && -1 < y < 3){
			if(a[y][x] == 0){
				a[y][x] = 1;
				k++;
			}
			for(j = 0 ; j < 3 ; j++){
				if(a[y][j] == 1){
					continue;
				}
				else break;
			}
			if(j == 3){
				w = 1;
				break;
			}
			for(j = 0 ; j < 3 ; j++){
				if(a[j][x] == 1){
					continue;
				}
				else break;
			}
			if(j == 3){
				w = 1;
				break;
			}
			if( (x == 0 && (y == 0||2) ) || ( (x == 1) || (y == 1) ) || (x == 2 && (y == 0||2) )){
				for(j = 0 ; j < 3 ; j++){
					if(a[j][j] == 1){
						continue;
					}
					else break;
				}
				if(j == 3){
					w = 1;
					break;
				}
				for(j = 2 ; j > -1 ; j--){
					if(a[2-j][j] == 1){
						continue;
					}
					else break;
				}
				if(j == -1){
					w = 1;
					break;
				}
			}
		}
		if (k % 2 == 0 && -1 < x < 3 && -1 < y < 3){
			if(a[y][x] == 0){
				a[y][x] = 2;
				k++;
			}
			for(j = 0 ; j < 3 ; j++){
				if(a[y][j] == 2){
					continue;
				}
				else break;
			}
			if(j == 3){
				w = 2;
				break;
			}
			for(j = 0 ; j < 3 ; j++){
				if(a[j][x] == 2){
					continue;
				}
				else break;
			}
			if(j == 3){
				w = 2;
				break;
			}
			if( (x == 0 && (y == 0||2) ) || ( (x == 1) || (y == 1) ) || (x == 2 && (y == 0||2) )){
				for(j = 0 ; j < 3 ; j++){
					if(a[j][j] == 2){
						continue;
					}
					else break;
				}
				if(j == 3){
					w = 2;
					break;
				}
				for(j = 2 ; j > -1 ; j--){
					if(a[2-j][j] == 2){
						continue;
					}
					else break;
				}
				if(j == -1){
					w = 2;
					break;
				}
			}
		}
		i++;
	}
	if(w == 0){
		printf("There is a draw.");
	}
	if(w == 1){
		printf("Black wins.");
	}
	if(w == 2){
		printf("White wins.");
	}
	return 0;
 }

