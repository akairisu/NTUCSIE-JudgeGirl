#include<stdio.h>
main()
{
	int a , b , c , d , e , f ;
	scanf("%d%d%d%d%d%d" , &a , &b , &c , &d , &e , &f);
	printf("%d\n" , e + ( c - a));
	printf("%d\n" , f + ( d - b));
	printf("%d\n" , e + ( a - c));
	printf("%d\n" , f + ( b - d));
	printf("%d\n" , c + ( a - e));
	printf("%d\n" , d + ( b - f));
}
