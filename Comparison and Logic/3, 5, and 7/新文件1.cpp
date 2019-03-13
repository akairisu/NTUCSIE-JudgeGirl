#include<stdio.h> 
main()
{
	int x;
	scanf("%d" , &x);
	if(x % 3 == 0 && x % 5 == 0 && x % 7 != 0)
		printf("%d" , 0);
		else printf("%d" , 1);
	return 0;
}
