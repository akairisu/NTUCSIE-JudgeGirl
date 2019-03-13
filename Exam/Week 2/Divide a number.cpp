#include<stdio.h>

int main(void)
{
	int a , n , k , l;
	scanf("%d" , &a);
	k = 0;
	while(scanf("%d" , &n) != EOF){
		if(k == 0){
			if((n / a) != 0){
				printf("%d\n" , n / a);
				l = n % a;
			}
			if(n / a == 0){
				l = n ;
			}
		}
		if(k > 0){
			printf("%d\n" , (l * 10 + n) / a);
			l = (l * 10 + n) % a;
		}
		k++;
	}
	if(k == 1 && (n / a) == 0){
		printf("%d" , 0);
	}
	return 0;
 } 
