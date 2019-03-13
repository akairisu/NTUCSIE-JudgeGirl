#include<stdio.h>

int main(void)
{
	int st , a , b , at , bt ;
	at = bt = 0;
	while(scanf("%d%d%d" , &st , &a , &b) != EOF){
		if (st >= at){
			at = st + a;
		} 
		else at = at + a;
		if(at >= bt){
			bt = at + b;
		}
		else bt = bt + b;
		printf("%d\n" , bt);
	}
	return 0;
}
