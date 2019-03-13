#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d" , &n);
	int a[n];
	for(int i = 0; i < n ; i++){
		scanf("%d" , &a[i]);
	}
	for(int i = n-1; i >= 1; i--){
		printf("%d ", a[i]);
	}
	printf("%d" , a[0]);
	return 0;
} 
