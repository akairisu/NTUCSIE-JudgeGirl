#include<stdio.h>

int main(void)
{
	int n , k = 0 , temp ;
	scanf("%d" , &n);
	int a[n] , b[n];
	for(int i = 0; i < n ; i++){
		scanf("%d" , &a[i]);
	}
	for(int i = 0 ; i < n ; i++){
		if (a[i] % 2 != 0){
		b[k] = a[i];
		k++;
	    }
	}
	temp = k;
	for(int i = 0 ; i < k ; i++){
		printf("%d" , b[i]);
		if(i != k-1)
			printf(" ");
			else printf("\n");
	}
	for(int i = 0; i < n ; i++){
		if (a[i] % 2 == 0){
		b[k] = a[i];
		k++;
		}
	}
	for(int i = temp ; i < n ; i++){
		printf("%d" , b[i]);
		if(i != n-1)
			printf(" ");
	}
	return 0;
 } 
