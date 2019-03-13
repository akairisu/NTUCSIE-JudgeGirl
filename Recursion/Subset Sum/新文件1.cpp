#include<stdio.h>

int count = 0;
void findset(int n , int k , int number[] , int sum , int now){
	if(now == n){
		if(sum == k){
			count++;
		}
		return;
	}
	if(sum + number[now] <= k){
		findset(n , k , number , sum + number[now] , now + 1);
	}
	findset(n , k , number , sum  , now + 1);
}

int main(void)
{
	int n;
	scanf("%d" , &n);
	int number[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d" , &number[i]);
	}
	int k;
	while(scanf("%d" , &k) != EOF){
		findset(n , k , number , 0 , 0);
		printf("%d\n" , count);
		count = 0;
	}
	return 0;
 }

