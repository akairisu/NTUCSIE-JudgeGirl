#include<stdio.h>

int main(void){
	int M , k;
	scanf("%d" , &M);
	k = (M > 0 && M % 2 == 0 && (M<1000|| M > 10000));
	printf("%d" , k);
	return 0;
} 
