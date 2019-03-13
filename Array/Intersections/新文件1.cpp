#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d" , &n);
	int a[n+2][n+2];
	int intersection[4];
	for(int i = 1 ; i < n + 1 ; i++){
		for(int j = 1 ; j < n + 1 ; j++){
			scanf("%d" , &a[i][j]);
		}
	}
	int k = 0;
	while(k < 4){
		intersection[k] = 0;
		k++;
	}
	k = 0;
	while(k < n + 2){
		a[0][k] = 0;
		a[n + 1][k] = 0;
		a[k][0] = 0;
		a[k][n + 1] = 0; 
		k++;
	}
	for(int i = 1 ; i < n + 1 ; i++){
		for(int j = 1 ; j < n + 1 ; j++){
			k = -1;
			int l = 0;
			if(a[i][j] == 1){
				if(a[i - 1][j] == 1){
					k++;
					l++;
				}
				if(a[i + 1][j] == 1){
					k++;
					l++;
				}
				if(a[i][j - 1] == 1){
					k++;
					l--;
				}
				if(a[i][j + 1] == 1){
					k++;
					l--;
				} 
				if(k == 1 && l != 0){
					continue;
				}
				else intersection[k]++;
			} 
			else continue;
		}
	}
	k = 3;
	while(k >= 0){
		printf("%d\n" , intersection[k]);
		k--;
	}
	return 0;
 }

