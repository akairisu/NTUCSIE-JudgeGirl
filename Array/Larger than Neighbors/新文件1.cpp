#include<stdio.h>

int main(void)
{
	int n , m;
	scanf("%d%d" , &n , &m);
	int a[n+2][m+2];
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			scanf("%d" , &a[i][j]);
		}
	}
	int k = 0;
	while(k < m + 2){
		a[0][k] = -1;
		a[n + 1][k] = -1;
		k++;
	}
	k = 0;
	while(k < n + 2){
		a[k][0] = -1;
		a[k][m + 1] = -1;
		k++;
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			if( ( a[i][j] > a[i-1][j] ) && ( a[i][j] > a [i+1][j] ) && ( a[i][j] > a[i][j-1] ) && ( a[i][j] > a[i][j+1] ) ){
				printf("%d\n" , a[i][j]);
			}
			else continue;
		}
	}
	return 0;
 } 
