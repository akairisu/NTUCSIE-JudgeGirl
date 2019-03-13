#include<stdio.h>
main()
{
	int x , score;
	score = 0 ;
	scanf("%d" , &x);
	if( x <= 0){
		printf("%d" , -100);
		return 0;
	}
	else {
	 if( x % 3 == 0){
		score = score + 3;
     }if( x % 5 == 0){
		score = score + 5 ;
	 }if (100 < x && 200 >= x){
		score = score + 50;
        }else {
	        score = score - 50;
	    }printf("%d" , score);
	}return 0;
}
