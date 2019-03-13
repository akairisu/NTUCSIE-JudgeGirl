#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include<sys/stat.h>
int main(void)
{
	int number;
	int sum = 0;
	while(scanf("%d" , &number) != EOF){
		sum += number;	
	}
	printf("%d\n" , sum);
	return 0;
 }

