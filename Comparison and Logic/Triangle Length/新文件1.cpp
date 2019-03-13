#include<stdio.h>
main()
{
	int a, b, c;
	scanf("%d%d%d" , &a ,&b ,&c );
	if(a+b>c && a+c>b && b+c>a)
		printf("%d" , 1);
		else printf("%d" , 0);
		return 0;
 } 
