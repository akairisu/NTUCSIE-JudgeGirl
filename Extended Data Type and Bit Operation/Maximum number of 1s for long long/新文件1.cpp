#include<stdio.h>

int main(void)
{
	long long number;
	while(scanf("%lld" , &number)!= EOF){
		int sumof1s = 0;
		while(number != 0){
			if(number & 1){
				sumof1s++;
			}
			number = number >> 1;
		}
		printf("%d\n" , sumof1s);
	}
	return 0;
 }

