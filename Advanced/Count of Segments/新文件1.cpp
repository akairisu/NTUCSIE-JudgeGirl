#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>
#include<sys/stat.h>
int main(void)
{
	int N;
	int numbers;
	int lastnumber;
	int segments = 1;
	while(scanf("%d" , &N) != EOF){
		for(int i = 0 ; i < N ; i++){
			scanf("%d" , &numbers);
			if(i > 0){
				if(numbers != lastnumber){
					segments++;
				}
			}
			lastnumber = numbers;
		}
		printf("%d\n" , segments);
		segments = 1;
	}
	return 0;
 }

