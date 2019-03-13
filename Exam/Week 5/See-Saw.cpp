#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d" , &n);
	int number[n];
	for(int i = 0 ; i < n ; i++){
		scanf("%d" , & number[i]);
	}
	int k = 0;
	int l = 1;
	int temp;
	while(k < l){
		for(int i = 0 ; i < n ; i++){
			int right = 0;
			int left = 0;
			for(int j = 1 ; j < n - i ; j++){
				right += number[i + j] * j;
			}
			for(int j = 1 ; j < i + 1 ; j++){
				left += number[i - j] * j;
			}
			if(right == left){
				number[i] = -1;
				k++;
				break; 
			}
		}
		if(k < l){
			temp = number[k];
			number[k] = number[n - l];
			number[n - l] = temp;
			k++;
			l++; 
		}
	}
	for(int i = 0 ; i < n ; i++){
		if(number[i] < 0){
			printf("v");
		}
		else printf("%d" , number[i]);
		if(i != n - 1){
			printf(" ");
		}
	}
	return 0;
 }

