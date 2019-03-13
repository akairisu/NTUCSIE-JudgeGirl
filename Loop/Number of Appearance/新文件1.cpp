#include<stdio.h>

int main(void)
{
	int a , b ;
	int c[2] , d[7] ;
	scanf("%d%d" , &a , &b);
	int j = 10;
	for(int i = 0 ; i <= 1 ; i++){
		c[i] = a / j;
		a = a % j;
		j = j / 10;
	}
	j = 1000000;
	for(int i = 0 ; i <= 6 ; i++){
		d[i] = b / j;
		b = b % j;
		j = j / 10;
	} 
	j = 0;
	for(int i = 0 ; i<=5 ; i++){
		if(c[0] == d[i] && c[1] == d[i+1])
		j++;
	}
	printf("%d" , j);
	return 0;
 } 
