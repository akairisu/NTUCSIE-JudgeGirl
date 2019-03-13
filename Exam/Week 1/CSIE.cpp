#include<stdio.h>
main()
{
	int h , w , a , area , length;
	scanf("%d%d%d" , &h , &w , &a);
	area = h * w * 3 + h * a - ( h - 2 * a) * ( w - a) - ( h - 3 * a) * ( w - a) * 2;
	length = h * 8 + w * 6 + ( w - a ) * 10 + 2 * a;
	printf("%d\n%d" , area , length);
 } 
