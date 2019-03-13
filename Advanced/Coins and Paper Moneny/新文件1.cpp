#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include<sys/stat.h>
int main(void)
{
	int amount;
	while(scanf("%d" , &amount) != EOF){
		printf("%d " , amount/1000);
		amount %= 1000;
		printf("%d " , amount/500);
		amount %= 500;
		printf("%d " , amount/100);
		amount %= 100;
		printf("%d " , amount/50);
		amount %= 50;
		printf("%d " , amount/10);
		amount %= 10;
		printf("%d " , amount/5);
		amount %= 5;
		printf("%d\n" , amount);
	}
	return 0;
 }

