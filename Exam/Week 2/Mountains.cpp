#include<stdio.h>

int main(void)
{
	int n , m , temp , k , l , fuel = 0 ;
	scanf("%d" , &n);
	for (int i = 1; i <= n ; i++){
		scanf("%d" , &m);
		if(i == 2){
			l = m - temp;
			if(l > 0){
				fuel = fuel + l * 3 ;
				k = 0;
			}
			if(l <= 0){
				l = -l;
				fuel = 	fuel + l * 2;
				k = 1;
			}
		}
		if(i >= 3){
			l = m - temp ;
			if(l > 0){
				if(k == 0){
					fuel = fuel + l * 4;
				}
				else
					fuel = fuel + l * 3;	
				k = 0;
			}
			if(l <= 0){
				l = -l;
				if(k == 0){
					fuel = fuel + l * 3;
				}
				else
					fuel = fuel + l * 2;	
				k = 1;
			}
		}
		temp = m;
	}
	printf("%d" , fuel);
	return 0;
}
