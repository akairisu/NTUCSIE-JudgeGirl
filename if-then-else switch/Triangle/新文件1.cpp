#include<stdio.h>
main()
{
	int i , n , j , a , b , c , max , mid , min ;
	scanf("%d" , &n);
	int d[n][6] , k[n];
	for( i = 0 ; i < n ; i++ ){
		for( j = 0 ; j < 6 ; j++ ){
			scanf( "%d" , &(d[i][j]));
		}
		a = ((d[i][0] - d[i][2]) * (d[i][0] - d[i][2])) + ((d[i][1] - d[i][3]) * (d[i][1] - d[i][3]));
	    b = ((d[i][0] - d[i][4]) * (d[i][0] - d[i][4])) + ((d[i][1] - d[i][5]) * (d[i][1] - d[i][5]));
	    c =	((d[i][2] - d[i][4]) * (d[i][2] - d[i][4])) + ((d[i][3] - d[i][5]) * (d[i][3] - d[i][5]));
	    if(a == b || a == c || b == c){
	    	k[i] = 0;
		}
		     else{
	         max = (a > b && a > c) ? a : (b > a && b > c)? b : c;
	         min = (a < b && a < c) ? a : (b < a && b < c) ? b : c;
	         mid = (a != max && a != min) ? a : (b != max && b != min) ? b : c;
	         if (max > mid + min)
	         	k[i] = 1; 
	         if ( max == mid + min)
     			k[i] = 2;
	         if ( max < mid + min)
			 	k[i] = 3;
	        }
	}
	for(i = 0 ; i < n ; i++ ){
	switch(k[i]){
	case 0:
	printf("isosceles\n");
	break;
	case 1:
	printf("obtuse\n");
	break;
	case 2:
	printf("right\n");
	break;
	case 3:
	printf("acute\n");
	break;
    }
}
	return 0;
}
