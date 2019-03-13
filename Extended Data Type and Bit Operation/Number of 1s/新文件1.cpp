#include<stdio.h>

int main(void)
{
	int number;
	while(scanf("%d" , &number)!= EOF){
		int sumof1s = 0;
		int count = 1;
		while(count != 32 && number != 0){
			if(number & 1){
				sumof1s++;
			}
			number = number >> 1; 
			count++;
		}
		printf("%d\n" , sumof1s);
	}
	return 0;
 }

