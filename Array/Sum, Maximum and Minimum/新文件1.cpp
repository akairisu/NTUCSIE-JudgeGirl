#include<stdio.h>

int main(void){
	int N , m;
	scanf("%d%d" , &N , &m);
	int number;
	int sum[m];
	int max[m];
	int min[m];
	for(int i = 0 ; i < m ; i++){
		sum[i] = 0;
		max[i] = 0;
		min[i] = 10000;
	}
	for(int i = 0 ; i < N ; i++){
		scanf("%d" , &number);
		int re = number % m;
		sum[re] += number;
			if(max[re] <= number){
				max[re] = number;
			}
			if(min[re] >= number){
				min[re] = number;
			}
	}
	for(int i = 0 ; i < m ; i++){
		printf("%d %d %d\n" , sum[i] , max[i] , min[i]);
	}
	return 0;
} 
