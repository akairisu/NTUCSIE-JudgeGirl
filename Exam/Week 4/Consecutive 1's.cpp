#include<stdio.h>

int main(void)
{
	int n ;
	scanf("%d" , &n);
	int a[n][n];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			scanf("%d" , &a[i][j]);
		} 
	}
	int k = 0;
	int max = 0;
	int temp = 0;
	while(k < n){
		for(int i = 0 ; i < n ; i ++){
			if(a[k][i] == 1){
				temp ++;
			}
			else temp = 0;
			if(temp > max){
				max = temp;
			}
		}
		temp = 0;
		k++;
	}
	k = 0;
	while(k < n){
		for(int i = 0 ; i < n ; i ++){
			if(a[i][k] == 1){
				temp ++;
			}
			else temp = 0;
			if(temp > max){
				max = temp;
			}
		}
		temp = 0;
		k++;
	}
	k = n - 1;
	while(k > 0){
		int l = 0;
		for(int i = k ; i < n ; i++){
			if(a[l][i] == 1){
				temp ++;
			}
			else temp = 0;
			if(temp > max){
				max = temp;
			}
			l++;
		}
		temp = 0;
		k--;
	}
	while(k < n){
		int l = 0; 
		for(int i = k ; i < n ; i++){
			if(a[i][l] == 1){
				temp++;
			}
			else temp = 0;
			if(temp > max){
				max = temp;
			}
			l++;
		}
		temp = 0;
		k++;
	}
	printf("%d" , max);
	return 0;
 } 
