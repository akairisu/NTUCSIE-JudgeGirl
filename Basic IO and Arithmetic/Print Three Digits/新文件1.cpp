#include<stdio.h>
main()
{
	int x, a ,b ,c;
	scanf("%d", &x);
	a = x / 100;
	x = x - 100 * a;
	b = x / 10;
	x = x - 10 * b;
	c = x;
	printf("%d\n", a);
	printf("%d\n", b); 
	printf("%d\n", c);   
 } 
