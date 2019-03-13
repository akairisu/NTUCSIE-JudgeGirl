#include<stdio.h>

int main(void)
{
	int N;
	scanf("%d" , &N);
	int a[N];
	for(int i = 0 ; i < N ; i++){
		scanf("%d" , &a[i]);
	}
	int M;
	scanf("%d" , &M);
	int mod[M];
	for(int i = 0 ; i < M ; i++){
		mod[i] = 0;
	}
	for(int i = 0 ; i < N ; i++){
		mod[a[i]%M]++;
	}
	for(int i = 0 ; i < M ; i++){
		printf("%d\n" , mod[i]);
	}
	return 0;
 } 
