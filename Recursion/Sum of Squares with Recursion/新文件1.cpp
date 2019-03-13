#include<stdio.h>

int sumofsquare(int n)
{
	if(n == 1){
		return 1;
	}
	else{
		return(n * n + sumofsquare(n - 1));
	}
}

int main(void)
{
	int n;
	scanf("%d" , &n);
	printf("%d\n" , sumofsquare(n));
	return 0;
 }

