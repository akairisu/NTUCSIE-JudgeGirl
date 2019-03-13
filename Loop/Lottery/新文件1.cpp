#include<stdio.h>

int main(void)
{
	int a1 , a2 , a3 ;
	int b1 , b2 , b3 ;
	int n;
	int k , i , temp;
	k = 1000;
	i = 0;
	int dollars = 0;
	scanf("%d%d%d%d%d%d" , &a1 , &a2 , &a3 , &b1 , &b2 , &b3);
	while(scanf("%d" , &n) != EOF){
		if((n == a1) || (n == a2) || (n == a3)){
			dollars += 2000000;
			continue;
		}
		else{
			while((n % k) == (b1 % k)){
				i++;
				k *= 10;
				if(i >= 6){
					break;
				}
			}
			temp = i;
			i = 0;
			k = 1000;
			while((n % k) == (b2 % k)){
				i++;
				k *= 10;
				if(i >= 6){
					break;
				}
			}
			if(i > temp){
				temp = i;
			}
			i = 0;
			k = 1000;
			while((n % k) == (b3 % k)){
				i++;
				k *= 10;
				if(i >= 6){
					break;
				}
			}
			if(i > temp){
				temp = i;
			}
			i = 0;
			k = 1000;
			switch(temp){
				case 0:
					break;
				case 1:	
					dollars += 200;	
					break;
				case 2:	
					dollars += 1000;	
					break;
				case 3:	
					dollars += 4000;	
					break;
				case 4:	
					dollars += 10000;	
					break;
				case 5:	
					dollars += 40000;	
					break;
				case 6:	
					dollars += 200000;	
					break;
			}
		}
	}
	printf("%d", dollars);
	return 0;
 } 
