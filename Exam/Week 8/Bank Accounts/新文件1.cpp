#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	int N;
	scanf("%d" , &N);
	char account[N][32];
	char user[32];
	int balance[N];
	char move[200];
	int nowuser;
	char process[4][32];
	int lengthcount = 0;
	int sum = 0;
	int check = 0;
	int target;
	char *start;
	for(int i = 0 ; i < N ; i++){
		scanf("%s" , user);
		strcpy(account[i] , user);
		scanf("%d" , &balance[i]);
	}
	while(gets(move) != 0){
		lengthcount = 0;
		start = strtok(move , " ");
		while(start != NULL){
			if(lengthcount < 4){
				strcpy(process[lengthcount] , start);
				lengthcount++;
				start = strtok(NULL , " ");
			}
			else continue;
		}
		if(lengthcount <= 4){
			check = 0;
			for(int i = 0 ; i < N ; i++){
				if(strcmp(process[0] , account[i]) == 0){
					nowuser = i;
					check = 1;
				}
			}
			if(check == 0){
				continue;
			}
			if(lengthcount == 3){
				if(strstr(process[1] , "earns") != NULL){
					sum = 0;
					for(int i = 0 ; i < strlen(process[2]) ; i++){
						sum = 10*sum + process[2][i] - '0';
					}
					balance[nowuser] += sum;
				}
				if(strstr(process[1] , "spends") != NULL){
					sum = 0;
					for(int i = 0 ; i < strlen(process[2]) ; i++){
						sum = 10*sum + process[2][i] - '0';
					}
					if(balance[nowuser] >= sum){
						balance[nowuser] -= sum;
					}
				}
				if(strstr(process[1] , "becomes") != NULL){
					sum = 0;
					for(int i = 0 ; i < strlen(process[2]) ; i++){
						sum = 10*sum + process[2][i] - '0';
					}
					balance[nowuser] = sum;
				}
			}
			if(lengthcount == 4){
				check = 0;
				int checktarget = 0;
				for(int i = 0 ; i < N ; i++){
					if(strcmp(process[0] , account[i]) == 0){
						nowuser = i;
						check = 1;
					}
				}
				for(int i = 0 ; i < N ; i++){
					if(strcmp(process[2] , account[i]) == 0){
						target = i;
						checktarget = 1;
					}
				}
				if(check == 0 || checktarget == 0){
					continue;
				}
				if(strstr(process[1] , "gives") != NULL){
					sum = 0;
					for(int i = 0 ; i < strlen(process[3]) ; i++){
						sum = 10*sum + process[3][i] - '0';
					}
					if(balance[nowuser] >= sum){
						balance[nowuser] -= sum;
						balance[target] += sum;
					}
				}
			}
		}
	}
	for(int i = 0 ; i < N ; i++){
		printf("%s " , account[i]);
		printf("%d\n" , balance[i]);
	}
	return 0;
 }

