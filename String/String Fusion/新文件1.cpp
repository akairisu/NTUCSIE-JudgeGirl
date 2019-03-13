#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char fusion[128];
	char string[128];
	int strlength;
	int check = 0;
	scanf("%s" , fusion);
	int fuslength = strlen(fusion);
	while(scanf("%s" , string) != EOF){
		check = 0;
		for(int i = 0 ; i < fuslength ; i++){
			if(strstr(string , fusion + i) == string){
				strcpy(&fusion[i] , string);
				check = 1;
				break;
			} 
		}
		if(check == 0){
			strcat(fusion , string);
		}
		fuslength = strlen(fusion);
	}
	printf("%s\n" , fusion);
	return 0;
 }

