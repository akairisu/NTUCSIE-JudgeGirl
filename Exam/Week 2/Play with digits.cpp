#include<stdio.h>

int main(void)
{
	int n , temp , k , odd , even , l;
	k = odd = even = 0;
	l = 1;
	while(scanf("%d" , &n) != EOF){
		temp = n;
		if(n == 0)
		k++;
		if(l % 2 != 0)
		odd = odd + n;
		else 
		even = even + n;
		l++;
	}
	printf("%d\n" , l-1);
	if (temp % 2 == 0)
	printf("%d\n" , 1);
	else printf("%d\n" , 0);
	printf("%d\n" , k);
	if((odd - even) % 11 == 0)
	printf("%d\n" , 1);
	else printf("%d\n" , 0);
	return 0;
}
