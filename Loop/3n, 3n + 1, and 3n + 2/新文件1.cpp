#include<stdio.h>
main()
{
	int i, n, a, b, c;
	a = b = c = 0;
	scanf("%d", &n);
	int d[n];
	for( i = 0 ; i < n ; i++){
		scanf("%d", &(d[i]));
    }
	for( i = 0 ; i < n ; i++){
		if(d[i] % 3 == 0)
			a++;
			else if(d[i] % 3 == 1)
			        b++;
				else 
					c++;
    }
	printf("%d %d %d" , a , b , c);
	return 0;
 } 
