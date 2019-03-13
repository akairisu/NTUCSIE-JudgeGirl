#include<stdio.h>
#include<string.h>
#include<ctype.h>
 
int main(void)
{
	int T;
	scanf("%d" , &T);
	int alphabet[26][26] = {{0}};
	char string[100];
	while(scanf("%s" , string) != EOF){
		for(int i = 0 ; i < strlen(string) - 1 ; i++){
			if(string[i + 1] != '0'){
				int a = string[i] - 'a';
				int b = string[i+1] - 'a';
				alphabet[a][b]++;
			}
		}
	}
	for(int i = 0 ; i < 26 ; i++){
		for(int j = 0 ; j < 26 ; j++){
			printf("%d" , alphabet[i][j]);
			if(j != 25){
				printf(" ");
			}
		}
		printf("\n");
	}
	int check = 1;
	int used[26][26] = {{0}};
	int maxfront , maxback;
	int checkfront;
	int max = T;
	for(int i = 0 ; i < 26 ; i++){
		for(int j = 0 ; j < 26 ; j++){
			if(alphabet[i][j] > max && used[i][j] != 1 && i != j){
				max = alphabet[i][j];
				maxfront = i;
				maxback = j;
				check = 0;
			}
		}
	}
	if(check == 0){
		checkfront = maxback;
		printf("%c%c" , 'a' + maxfront , 'a' + maxback);
		for(int i = 0 ; i < 26 ; i++){
			used[maxfront][i] = 1;
			used[i][maxfront] = 1;
		}
	}
	while(check != 1){
		check = 1;
		max = T;
		for(int i = 0 ; i < 26 ; i++){
			if(alphabet[checkfront][i] > max && used[checkfront][i] != 1 && i != checkfront){
				max = alphabet[checkfront][i];
				maxback = i;
				check = 0;
			}
		}
		for(int i = 0 ; i < 26 ; i++){
			used[checkfront][i] = 1;
			used[i][checkfront] = 1;
		}
		if(check == 0){
			checkfront = maxback;
			printf("%c" , 'a' + maxback);
		}
	}
	return 0;
 }

