#include<stdio.h>
 main()
 {
 	int a, b, c, d, e, surface, volume;
 	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
 	surface = a * b * 2 + b * c * 2 + a * c * 2 + ( ( a - 2 * e ) + ( c - 2 * e ) + ( b - 2 * e )) * d * 8 ;
 	volume = a * b * c - ( a - 2 * e) * ( b - 2 * e ) * 2 * d - ( a - 2 * e) * ( c - 2 * e ) * 2 * d - ( b - 2 * e ) * ( c - 2 * e ) * 2 * d ;
 	printf("%d\n", surface);
 	printf("%d\n", volume);
 	return 0;
 }
 
