#include<stdio.h>
main()
{
	int h, w, d;
	scanf("%d", &h);
	scanf("%d", &w);
	scanf("%d", &d);
	printf("%d\n", h*d*2+w*d*2+w*h*2);
	printf("%d\n", h*d*w);
 } 
