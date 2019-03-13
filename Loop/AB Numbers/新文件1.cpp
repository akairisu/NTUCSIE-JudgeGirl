#include<stdio.h>

int main()
{
	int A , B , i , j , k , l;
	j , k , l = 0;
	int a[2][4];
	scanf("%d%d" , &A , &B);
	j = 1000;
	for(i = 0 ; i <= 3 ; i ++){
		a[0][i] = A / j;
		a[1][i] = B / j;
		A = A - (a[0][i] * j);
		B = B - (a[1][i] * j); 
		j = j / 10 ;
	}
	for(i = 0 ; i <= 3 ; i++){
		for(j = 0 ; j <= 3 ; j ++){
			if(a[0][i] == a[1][j] && i != j)
			l++;
			if(a[0][i] == a[1][j] && i == j)
			k++;
		}
	}
	printf("%d" , k );
	printf("A");
	printf("%d" , l );
	printf("B");
}
  
