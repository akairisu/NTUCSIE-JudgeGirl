#include<stdio.h>

int main(void)
{
	int n , m;
	scanf("%d%d" , &n , &m);
	int a[n][m];
	int aver[m];
	for(int j = 0; j < m ; j++){
		aver[j] = 0;
	}
	for(int i = 0 ; i < n ; i++){
		for(int j = 0; j < m ; j++){
			scanf("%d" , &a[i][j]);
			aver[j] += a[i][j];
		}
	}
	for(int i = 0 ; i < m ; i++){
		printf("%d\n" , aver[i] / n);
	}
	return 0;
}
