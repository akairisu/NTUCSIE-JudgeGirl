#include<stdio.h>

int main(void)
{
	int x , y;
	int maxx = -10000;
	int minx = 10000;
	int maxy = -10000;
	int miny = 10000;
	while(scanf("%d%d" , &x , &y) != EOF){
		if(x >= maxx){
			maxx = x;
		}
		if(x <= minx){
			minx = x;
		}
		if(y >= maxy){
			maxy = y;
		}
		if(y <= miny){
			miny = y;
		}
	}
	printf("%d" , (maxx - minx) * (maxy - miny));
	return 0;
 }

