#include<stdio.h>
main()
{
	int a , b , c , d , e , f ;
	scanf("%d%d%d%d%d%d" , &a, &b , &c , &d , &e , &f);
	printf("%d\n" , a * d + b * e + c * f);
	printf("%d %d %d" , b * f - c * e , c * d - a * f , a * e - b * d );
	return 0;
 } 
