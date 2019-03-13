#include<stdio.h>

int main(void)
{
	int a , b , c , d , e , f , g , h ;
	scanf("%d%d%d%d%d%d%d%d" , &a , &b , &c , &d , &e , &f , &g , &h);
	if((a * d) - (b * c) > 0 && (c * f) - (d * e) > 0 && (e * h) - (f * g) > 0 && (g * b) - (h * a) > 0)
		printf("%d" , 1);
		else printf("%d" , 0);
	return 0;
}
