#include<stdio.h>

int main(void)
{
	int N , M , x , y ;
	scanf("%d%d" , &N , &M);
	x = y = 0;
	int a , r;
	for(scanf("%d" , &a)  ; a!= EOF ; scanf("%d" , &a)){
		r = a % 5;
		switch(r){
		case 0:
		break;
		case 1:
		if(x + a > N-1){
			break;
		}
		   else{
		   x = x + a;
		   printf("%d\n%d\n" , x , y);
		   }
		break;
		case 2:
		if(x - a < 0){
			break;
		}
			else{
			x = x - a;
			printf("%d\n%d\n" , x , y);
			}
		break;
		case 3:
		if(y + a > M-1){
			break;
		}
			else{
			y = y + a;
			printf("%d\n%d\n" , x , y);
			}
		break;
		case 4:
		if(y - a < 0){
			break;
		}
			else{
			y = y - a;
			printf("%d\n%d\n" , x , y);
			}
		break;
		}
	}
	return 0;
 } 
