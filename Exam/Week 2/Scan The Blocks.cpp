#include<stdio.h>

int main(void)
{
	int N , a , max , min , k = 1;
	while (scanf("%d" , &N) != EOF){
		for(int i = 1 ; i <= N ; i++){
			if(scanf("%d" , &a) != EOF){
				  if(i == 1){
				max = a;
				min = a;
				} if(a >= max){
				max = a;
				} if(a <= min){
				min = a;
				} if(i == N){
				printf("%d\n" , max);
				}	
			}
			else{
			printf("%d" , min);
			k = 0;
			break;
			}
		}
		if (k == 0)
		break;
	}
	return 0;
 } 
