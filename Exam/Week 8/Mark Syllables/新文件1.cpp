#include<stdio.h>
#include<string.h>
 
int main(void)
{
	char word[10000];
	int a , b;
	int syllable[10000];
	while(scanf("%s" , word) != EOF){
		int syllablecount = 0;
		int vowelcheck = 0;
		int len = strlen(word);
		for(int i = 0 ; i < len ; i++){
			syllable[i] = syllablecount;
			if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u'){
				vowelcheck = 1;
				syllablecount++;
			}
			else{
				vowelcheck = 0;
			}
		}
		scanf("%d%d" , &a , &b);
		for(int i = 0 ; i < len ; i++){
			if(syllable[i] == a){
				printf("%c" , word[i]);
			}
			else printf("+");
		}
		printf("\n");
		for(int i = 0 ; i < len ; i++){
			if(syllable[i] == b){
				printf("%c" , word[i]);
			}
			else printf("+");
		}
		printf("\n");
		for(int i = 0 ; i < len ; i++){
			if(syllable[i] != a && syllable[i] != b){
				printf("%c" , word[i]);
			}
			else printf("+");
		}
		printf("\n");
	}
	return 0;
 }

