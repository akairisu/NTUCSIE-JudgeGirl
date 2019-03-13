#include<stdio.h>
int fib(int N)
{
	if(N == 0 || N == 1){
		return N;
	}
	else return(fib(N - 1) + fib(N - 2)); 
}
 
int main(void)
{	
	int N;
	scanf("%d" , &N);
	for(int i = 0 ; i < N ; i++){
		printf("fib(%d) = %d\n" , i , fib(i));
	}
	printf("fib(%d) = %d\n" , N , fib(N));
	return 0;
 }

