#include<stdio.h>
#include<string.h>
#include<ctype.h> 

int main(void)
{
	char string[128];
	while(scanf("%s" , string) != EOF){
		if(strcmp(string , "the") == 0){
			continue;
		}
		if(strcmp(string , "and") == 0){
			continue;
		}
		if(strcmp(string , "of") == 0){
			continue;
		}
		if(strcmp(string , "at") == 0){
			continue;
		}
		if(strcmp(string , "the.") == 0){
			printf("\n");
			continue;
		}
		if(strcmp(string , "and.") == 0){
			printf("\n");
			continue;
		}
		if(strcmp(string , "of.") == 0){
			printf("\n");
			continue;
		}
		if(strcmp(string , "at.") == 0){
			printf("\n");
			continue;
		}
		int len = strlen(string);
		printf("%c" , toupper(string[0]));
		if(string[len - 1] == '.'){
			printf("\n");
		}
	}
	return 0;
 }

