#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d" , &n);
	int co1[n];
	for(int i = n - 1 ; i >=0 ; i--){
		scanf("%d" , &co1[i]);
	}
	int m;
	scanf("%d" , &m);
	int co2[m];
	for(int i = m - 1 ; i >= 0 ; i--){
		scanf("%d" , &co2[i]);
	}
	for(int i = 0 ; i < n ; i++){
		int sum = 0;
		for(int j = 0 ; j <= i ; j++){
			if(j == i/2){
				sum += co1[n - j - 1] * co2[m - j - 1];
			}
			else {
				sum += co1[n - j - 1] * co2[m - i + j - 1];
			}
		}
		printf("%d" , sum);
		if(i !=  n - 1){
			printf(" ");
		}
	}		
	return 0;
 }

