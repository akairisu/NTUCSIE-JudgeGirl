#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void)
{
	char string[100];
	scanf("%s" , string);
	int alphabetcount[26]={0}; 
	int length = strlen(string);
	for(int i = 0 ; i < length ; i++){
		if(islower(string[i])){
			alphabetcount[string[i] - 'a']++;
		}
		if(isupper(string[i])){
			alphabetcount[string[i] - 'A']++;
		}
	}
	for(int i = 0 ; i < 26 ; i++){
		printf("%d\n" , alphabetcount[i]);
	}
	return 0;
 }

