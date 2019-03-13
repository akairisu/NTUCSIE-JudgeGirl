#include<stdio.h>

int main(void)
{
	int a , k , l , m , templ , temp , max;
	temp = 0;
	templ = -1;
	max = 0;
	while(scanf("%d" , &a) != EOF){
		l = a % 10;
		k = 1;
		while(a >= 10){
			a = a / 10;
			k++;
		}
		m = a;
		if(m == templ){
		temp = temp + k;
		}
		else {
			temp = k;
		}
		if(temp >= max){
			max = temp;
		}
		templ = l;
	}
	printf("%d" , max);
	return 0;
 } 
