#include<stdio.h>

int main(void)
{
	int number;
	while(scanf("%d" , &number) != EOF){
		int length = 0;
		int maxlength = 0;
		while(number != 0){
			if(number & 1){
				length++;
				if(length >= maxlength){
					maxlength = length;
				}
			}
			else length = 0;
			number = number >> 1;
		}
		printf("%d\n" , maxlength);
	}
	return 0;
 }

