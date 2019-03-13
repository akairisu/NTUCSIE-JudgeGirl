#include<stdio.h>
#include <string.h>
#include <ctype.h>

void chasing(int **A[], int a, int *B[], int b, int C[], int c)
{
	for(int i = 0 ; i < 5 ; i++){
		A[i] = NULL;
	}
	for (int i = 0; i < 4; i++){
		B[i] = NULL;
	}
	char string[64];
	char chase[1000][1000];
	int i;
	int d = 0;
	while(scanf("%c" , &string[d]) != EOF){
		if (string[d] == '\n') {
			string[d] = '\0';
			i = 0;
			while (string[i] == ' ')
				i++;
			for (int j = i; j <= strlen(string); j++)
				string[j - i] = string[j];
			i = 0;
			char *start = string;
			start = strtok(start , " ");
			while(start != NULL){
				strcpy(chase[i] , start);
				i++;
				start = strtok(NULL , " ");
			}
			if(i != 4){
				printf("0\n");
				d = 0;
				continue;
			}
			if( strlen(chase[0]) != 1 && strlen(chase[2])!= 1){
				printf("0\n");
				d = 0;
				continue;
			}
			else{
				if(chase[0][0] == 'A' && chase[2][0] == 'B'){
					int sum1 = 0;
					int sum3 = 0;
					int check = 0;
					int j = 0;
					while(j < strlen(chase[1])){
						if(isdigit(chase[1][j])){
							sum1 = sum1 * 10 + chase[1][j] - '0';
							j++;
						}
						else{
							check = 1;
							printf("0\n");
							break;
						}
					}
					if(check != 1){
						check = 0;
						j = 0;
						while(j < strlen(chase[3])){
							if(isdigit(chase[3][j])){
								sum3 = sum3 * 10 + chase[3][j] - '0';
								j++;
							}
							else{
								check = 1;
								printf("0\n");
								break;
							}
						}
					}
					if(check != 1){
						check = 0;
						if(sum1 >= a || sum3 >= b){
							printf("0\n");
							check = 1;
							d = 0;
							continue;
						}
					}
					if(check != 1){ 
						printf("1\n");
						A[sum1] = &B[sum3];
					}
				}
				else if(chase[0][0] == 'B' && chase[2][0] == 'C' ){
					int sum1 = 0;
					int sum3 = 0;
					int check = 0;
					int j = 0;
					while(j < strlen(chase[1])){
						if(isdigit(chase[1][j])){
							sum1 = sum1 * 10 + chase[1][j] - '0';
							j++;
						}
						else{
							check = 1;
							printf("0\n");
							break;
						}
					}
					if(check != 1){
						check = 0;
						sum3 = 0;
						j = 0;
						while(j < strlen(chase[3])){
							if(isdigit(chase[3][j])){
								sum3 = sum3 * 10 + chase[3][j] - '0';
								j++;
							}
							else{
								check = 1;
								printf("0\n");
								break;
							}
						}
					}
					if(check != 1){
						check = 0;
						if(sum1 >= b || sum3 >= c){
							printf("0\n");
							check = 1;
							d = 0;
							continue;
						}
					}
					if(check != 1){ 
						printf("1\n");
						B[sum1] = &C[sum3];
					}
				}
				else {
					printf("0\n");
				}
			}
			d = 0;
		}
		else d++;
	}
} 
