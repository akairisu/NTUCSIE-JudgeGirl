#include<stdio.h> 

int main(void)
 {
 	int n , m , first , second , row , column;
 	scanf("%d%d" , &n , &m);
 	int i , j ;
 	int h , max , temp , sec;
 	i = j = 1;
 	max = -1;
 	while (i <= n){
 		sec = -1;
 		j = 1;
 		while(j <= m){
 			scanf("%d" , &h);
 			if(j == 1){
 				first = j;
 				temp = h;
			 }
			 if(j >= 2){
			 	if(h >= temp){
			 		sec = temp;
			 		temp = h;
			 		second = first;
			 		first = j;
				 }
				if(h < temp && h >= sec){
					sec = h;
					second = j;
				}
			 }
			 j++;
		 }
		 if(i == 1){
		 	max = temp;
		 	row = i;
		 	column = first;
		 }
		 if(i >= 2){
		 	if(temp >= max){
		 		max = temp;
		 		row = i;
		 		column = first;
			 }
		 }
		 printf("%d %d\n" , first , second);
		 i++;
	 }
	 printf("%d %d\n" , row , column);
	 return 0;
 }
 
