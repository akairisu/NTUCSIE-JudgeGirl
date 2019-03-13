#include<stdio.h>
int gcd(int a , int b)
{
	int max;
	int min;
	min = (a > b) ? b : a;
	for(int i = 1 ; i <= min ; i++){
		if(a % i == 0 && b % i == 0){
			max = i;
		}
	}
	return max;
}

int main(void)
{
	int a , max  , sum;
	scanf("%d" , &a);
	max = a;
	sum = a;
	while(scanf("%d" , &a) != EOF){
		max = gcd(sum , a);
		sum *= a;
		sum /= max;
	}
	printf("%d" , sum);
	return 0;
 }

