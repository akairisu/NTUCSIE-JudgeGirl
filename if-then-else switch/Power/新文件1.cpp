#include<stdio.h>
main()
{
	int i , n , j ,power;
	scanf("%d%d" , &n , &i );
	power = n;
	for( j=1 ; j<i ; j++){
		power = power*n;
	}
	printf("%d" , power);
 } 
