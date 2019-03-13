#include<stdio.h>

 int main(void)
 {
 	int n , m , max , sec , row , column;
 	scanf("%d%d" , &n , &m);
 	int a[n][m] , k[n] , s[n] ,l[n];
 	for(int i = 0 ; i < n ; i++){
 		s[i] = -1;
 		for (int j = 0; j < m ; j++){
 			scanf("%d" , &a[i][j]);
 			if(j == 0){
 				k[i] = a[i][j];
				l[i] = j + 1;
				max = j + 1;
			 }
			if(j >= 1){
				if(a[i][j] >= k[i]){
					sec = max;
					max = j + 1;
					s[i] = k[i];
					k[i] = a[i][j]; 
					l[i] = j + 1;
				}
				if(a[i][j] < k[i] && a[i][j] >= s[i]){
					sec = j + 1;
					s[i] = a[i][j];
				}
			}
		 }
		 printf("%d %d\n" , max ,sec);
	 }
	 for(int i = 0; i < n; i++){
	 	if(i == 0){
	 		max = k[i];
	 		row = i + 1;
	 		column= l[i];
		 }
		if(i >= 1){
			if(k[i] >= max){
				max = k[i];
	 		row = i + 1;
	 		column= l[i];
			}
		}
	 }
	 printf("%d %d\n" , row , column);
	 return 0;
 }
