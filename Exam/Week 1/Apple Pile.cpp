#include<stdio.h>

int main(void){
	int a , b , level;
	scanf("%d%d" , &a , &b);
	level = b - a + 1;
	printf("%d\n" , (a + b) * level / 2);
	printf("%d\n" , a + b + level * 2 - 4);
} 
