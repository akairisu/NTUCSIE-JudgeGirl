#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void){
	char string[1000];
	while(scanf("%s", string) != EOF){
		int length = strlen(string);
		int sum = 0;
		int check = 0;
		int count = 1;
		for(int i = 0 ; i < length ; i++){
			if(isdigit(string[i])){
				if(check == 0){
					sum += string[i] - '0';
					check = 1;
				}
				else if(check == 1){
					sum *= 10;
					sum += string[i] - '0';
				}
				if(i == length - 1){
						printf("%d\n" , sum);
				} 
			}
			else if(check == 1){
				printf("%d\n" , sum);
				sum = 0;
				check = 0;
				count++;
			}
		}
	}
	return 0;
}
